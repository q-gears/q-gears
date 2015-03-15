#include <OgreRenderWindow.h>

#include "common/QGearsApplication.h"
#include "core/ConfigCmdManager.h"
#include "core/ConfigVarManager.h"
#include "core/Console.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "core/ScriptManager.h"
#include "core/Timer.h"
#include "core/Utilites.h"
#include <OgreFontManager.h>


template<>Console *Ogre::Singleton<Console>::msSingleton = nullptr;
ConfigVar cv_console_notification("console_notification", "Draw console strings even when console is hided", "false");


Console::Console():
    m_ToVisible(false),
    m_Visible(false),
    m_Height(0),

    m_MaxOutputLine(128),
    m_DisplayLine(0),
    m_InputLine(""),
    m_CursorPosition(0),
    m_CursorBlinkTime(0),

    m_HistoryLineCycleIndex(-1),
    m_MaxHistorySize(32),

    m_AutoCompletitionLine(0)
{

    Ogre::FontPtr font = Ogre::FontManager::getSingleton().getByName("CourierNew");
    if(font.isNull() == false)
    {
        m_LetterWidth = static_cast<int>(font->getGlyphAspectRatio('_') * 16);
    }
    else
    {
        LOG_ERROR("Console::frameStarted: Font for console not found.");
    }

    // calculate width and height of console depending on size of application
    Ogre::RenderTarget *render_target(QGears::Application::getSingleton().getRenderWindow());
    m_ConsoleWidth = render_target->getWidth();
    m_ConsoleHeight = static_cast<int>(render_target->getHeight() / 2.5f);
    m_LineWidth = (m_ConsoleWidth - 20) / 8;

    LOG_TRIVIAL("Created console width " + Ogre::StringConverter::toString(m_ConsoleWidth) + ", height " + Ogre::StringConverter::toString(m_ConsoleHeight));

    // add as frame and log listener
    Ogre::LogManager::getSingleton().getDefaultLog()->addListener(this);

    LoadHistory();
}


Console::~Console()
{
    // remove as listener
    Ogre::LogManager::getSingleton().getDefaultLog()->removeListener(this);
    SaveHistory();
}

void Console::LoadHistory()
{
    LOG_TRIVIAL("Loading console_history.txt ...");

    std::ifstream file("console_history.txt");
    std::string historyLine;
    while (std::getline(file, historyLine))
    {
        AddToHistory(historyLine);
    }
    std::reverse(m_History.begin(), m_History.end());
}

void Console::SaveHistory()
{
    std::ofstream file("console_history.txt");
    if (!file.is_open())
    {
        LOG_ERROR("Failed to open console_history.txt for writing");
        return;
    }
    for (auto& historyLine : m_History)
    {
        file << historyLine << "\r\n";
    }
}

void Console::AddToHistory(const Ogre::String& history)
{
    if (m_History.size() >= m_MaxHistorySize)
    {
        m_History.pop_back();
    }
    m_History.push_front(history);
    m_HistoryLineCycleIndex = -1;
}

void
Console::Input(const QGears::Event& event)
{
    if(m_Visible != true)
    {
        // add console
        if (event.type == QGears::ET_KEY_PRESS && event.param1 == OIS::KC_GRAVE)
        {
            SetToVisible();
        }

        return;
    }

    // input command
    else if (event.type == QGears::ET_KEY_PRESS && (event.param1 == OIS::KC_RETURN || event.param1 == OIS::KC_NUMPADENTER) && m_InputLine.size())
    {
        if(m_AutoCompletition.size() > 0)
        {
            m_InputLine += m_AutoCompletition[m_AutoCompletitionLine];
        }

        AddTextToOutput(m_InputLine);
        AddInputToHistory();

        // backslashed text are console commands, otherwise - script commands
        if('\\' == m_InputLine[0] || '/' == m_InputLine[0])
        {
            if(m_InputLine.size() > 1)
            {
                // remove backslash
                m_InputLine.erase(0, 1);

                ExecuteCommand(m_InputLine);
            }
        }
        else
        {
            ExecuteScript();
        }

        m_InputLine.clear();
        m_CursorPosition = 0;
        ResetAutoCompletion();
    }
    else if (event.type == QGears::ET_KEY_PRESS && event.param1 == OIS::KC_TAB)
    {
        CompleteInput();
    }
    // remove console
    else if (event.type == QGears::ET_KEY_PRESS && event.param1 == OIS::KC_GRAVE)
    {
        SetToHide();
    }
    // history up
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_UP)
    {
        if(m_HistoryLineCycleIndex < (int)m_History.size() - 1)
        {
            ++m_HistoryLineCycleIndex;
            SetInputLineFromHistory();
        }
    }
    // history down
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_DOWN)
    {
        if(m_HistoryLineCycleIndex > 0)
        {
            --m_HistoryLineCycleIndex;
            SetInputLineFromHistory();
        }
    }
    // scroll display to previous row
    else if (event.type == QGears::ET_MOUSE_SCROLL && event.param1 > 0)
    {
        if(m_DisplayLine > 0)
        {
            m_DisplayLine -= 1;
        }
    }
    // scroll display to next row
    else if (event.type == QGears::ET_MOUSE_SCROLL && event.param1 < 0)
    {
        if(m_DisplayLine < m_OutputLine.size())
        {
            m_DisplayLine += 1;
        }

    }
    // scroll display to previous row
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_PGUP)
    {
        if(m_DisplayLine > 0)
        {
            m_DisplayLine -= 1;
        }
    }
    // scroll display to next row
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_PGDOWN)
    {
        if(m_DisplayLine < m_OutputLine.size())
        {
            m_DisplayLine += 1;
        }
    }
    // delete character after cursor
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_DELETE)
    {
        if(m_AutoCompletition.size() > 0)
        {
            ResetAutoCompletion();
        }
        else
        {
            if(m_InputLine.size() > 0 && m_CursorPosition < m_InputLine.size())
            {
                m_InputLine.erase(m_CursorPosition, 1);
            }
        }
    }
    // delete character before cursor
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_BACK)
    {
        if(m_AutoCompletition.size() > 0)
        {
            ResetAutoCompletion();
        }
        else
        {
            if(m_CursorPosition > 0)
            {
                m_InputLine.erase(m_CursorPosition - 1, 1);
                --m_CursorPosition;
            }
        }
    }
    // move cursor to left
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_LEFT)
    {
        if(m_AutoCompletition.size() > 0)
        {
            m_InputLine += m_AutoCompletition[m_AutoCompletitionLine];
            ResetAutoCompletion();
        }

        if(m_CursorPosition > 0)
        {
            --m_CursorPosition;
        }
    }
    // move cursor to right
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && event.param1 == OIS::KC_RIGHT)
    {
        if(m_AutoCompletition.size() > 0)
        {
            m_InputLine += m_AutoCompletition[m_AutoCompletitionLine];
            ResetAutoCompletion();
        }

        if(m_CursorPosition <  m_InputLine.size())
        {
            ++m_CursorPosition;
        }
    }
    else if (event.type == QGears::ET_KEY_PRESS && event.param1 == OIS::KC_ESCAPE)
    {
        m_InputLine.clear();
        m_CursorPosition = 0;
        ResetAutoCompletion();
    }
    // move cursor to start of string
    else if (event.type == QGears::ET_KEY_PRESS && event.param1 == OIS::KC_HOME)
    {
        m_CursorPosition = 0;

        if(m_AutoCompletition.size() > 0)
        {
            m_InputLine += m_AutoCompletition[m_AutoCompletitionLine];
            ResetAutoCompletion();
        }
    }
    // move cursor to end of string
    else if (event.type == QGears::ET_KEY_PRESS && event.param1 == OIS::KC_END)
    {
        if(m_AutoCompletition.size() > 0)
        {
            m_InputLine += m_AutoCompletition[m_AutoCompletitionLine];
            ResetAutoCompletion();
        }

        m_CursorPosition = m_InputLine.size();
    }
    // input ascii character
    else if ((event.type == QGears::ET_KEY_PRESS || event.type == QGears::ET_KEY_REPEAT_WAIT) && m_InputLine.size() < m_LineWidth)
    {
        char legalchars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()-_=+?{[]}|\\;:'\"<>,./? ";
        char txt = TranslateNumpad(event);

        for (unsigned int c = 0; c < sizeof(legalchars) - 1; ++c)
        {
            if(legalchars[c] == txt)
            {
                std::string::iterator i = m_InputLine.begin() + m_CursorPosition;
                m_InputLine.insert(i, txt);
                ++m_CursorPosition;
                ResetAutoCompletion();
                break;
            }
        }
    }
}


char
Console::TranslateNumpad(const QGears::Event& event)
{
    switch (static_cast<int>(event.param1))
    {
    case OIS::KC_NUMPAD0:
        return '0';
    case OIS::KC_NUMPAD1:
        return '1';
    case OIS::KC_NUMPAD2:
        return '2';
    case OIS::KC_NUMPAD3:
        return '3';
    case OIS::KC_NUMPAD4:
        return '4';
    case OIS::KC_NUMPAD5:
        return '5';
    case OIS::KC_NUMPAD6:
        return '6';
    case OIS::KC_NUMPAD7:
        return '7';
    case OIS::KC_NUMPAD8:
        return '8';
    case OIS::KC_NUMPAD9:
        return '9';
    case OIS::KC_DECIMAL:
        return '.';
    case OIS::KC_ADD:
        return '+';
    case OIS::KC_SUBTRACT:
        return '-';
    case OIS::KC_MULTIPLY:
        return '*';
    case OIS::KC_DIVIDE:
        return '/';
    }
    return static_cast<char>(event.param2);
}

void
Console::Update()
{
    float delta_time = Timer::getSingleton().GetSystemTimeDelta();

    if(m_ToVisible == true && m_Height < m_ConsoleHeight)
    {
        // TODO: Convert this to a constant.
        m_Height += delta_time * 1500;

        if(m_Height >= m_ConsoleHeight)
        {
            m_Height = static_cast<float>(m_ConsoleHeight);
        }
    }
    else if(m_ToVisible == false && m_Height > 0)
    {
        m_Height -= delta_time * 1500;

        if(m_Height <= 0)
        {
            m_Height = 0;
            m_Visible = false;
        }
    }

    if(m_Visible == true)
    {
        UpdateDraw();
    }
    else if(cv_console_notification.GetB() == true)
    {
        UpdateNotification();
    }
}


void
Console::UpdateDraw()
{
    float delta_time = Timer::getSingleton().GetSystemTimeDelta();

    DEBUG_DRAW.SetTextAlignment(DEBUG_DRAW.LEFT);
    DEBUG_DRAW.SetScreenSpace(true);
    DEBUG_DRAW.SetColour(Ogre::ColourValue(0.05f, 0.06f, 0.2f, 0.95f));
    DEBUG_DRAW.SetZ(-0.5f);
    DEBUG_DRAW.Quad(0.0f, 0.0f, static_cast<float>(m_ConsoleWidth), 0.0f, static_cast<float>(m_ConsoleWidth), m_Height, 0.0f, m_Height);
    DEBUG_DRAW.SetColour(Ogre::ColourValue(0.18f, 0.22f, 0.74f, 0.95f));
    DEBUG_DRAW.SetZ(-0.6f);
    DEBUG_DRAW.Line(0.0f, m_Height, static_cast<float>(m_ConsoleWidth), m_Height);

    int row = 1;
    int rows = (m_ConsoleHeight - 30) / 16;
    int y = static_cast<int>(-m_ConsoleHeight + m_Height);
    int empty = rows - m_DisplayLine;
    if(empty > 0)
    {
        y += empty * 16;
    }

    std::list<OutputLine>::iterator i;
    for(i = m_OutputLine.begin(); i != m_OutputLine.end(); ++i, ++row)
    {
        if(row > (int)m_DisplayLine - rows && row <= (int)m_DisplayLine)
        {

            DEBUG_DRAW.SetColour((*i).colour);
            DEBUG_DRAW.Text(5.0f, static_cast<float>(y), (*i).text);
            y += 16;
        }
    }
    if(m_DisplayLine != m_OutputLine.size())
    {
        Ogre::String temp = "";
        for(unsigned int i = 0; i < m_LineWidth; ++i)
        {
            temp += "^";
        }
        DEBUG_DRAW.SetColour(Ogre::ColourValue(1.0f, 0.0f, 0.0f, 1.0f));
        DEBUG_DRAW.Text(5.0f, static_cast<float>(y), temp);
    }

    m_CursorBlinkTime += delta_time;
    if((((int)(m_CursorBlinkTime * 1000)) >> 8) & 1)
    {
        DEBUG_DRAW.SetColour(Ogre::ColourValue(0.88f, 0.88f, 0.88f, 1));
        DEBUG_DRAW.Text(static_cast<float>(12 + m_CursorPosition * m_LetterWidth), static_cast<float>(-19 + m_Height), "_");
    }


    if(m_AutoCompletition.size() > 0)
    {
        DEBUG_DRAW.SetColour(Ogre::ColourValue(1, 1, 1, 1));
        DEBUG_DRAW.Text(12, -20 + m_Height, m_InputLine);
        DEBUG_DRAW.SetColour(Ogre::ColourValue(0, 1, 0, 1));
        DEBUG_DRAW.Text(static_cast<float>(12 + (m_InputLine.size() * m_LetterWidth)), static_cast<float>(-20 + m_Height), m_AutoCompletition[m_AutoCompletitionLine]);
    }
    else
    {
        DEBUG_DRAW.SetColour(Ogre::ColourValue(1, 1, 1, 1));
        DEBUG_DRAW.Text(12, -20 + m_Height, m_InputLine);
    }

    DEBUG_DRAW.SetZ(0);
}


void
Console::UpdateNotification()
{
    DEBUG_DRAW.SetTextAlignment(DEBUG_DRAW.LEFT);
    DEBUG_DRAW.SetScreenSpace(true);
    DEBUG_DRAW.SetZ(-0.6f);

    std::list< OutputLine >::reverse_iterator i;
    int y = (m_OutputLine.size() > 10) ? 160 : m_OutputLine.size() * 16;
    int line = 0;
    float max_time = 3.0f;

    for(i = m_OutputLine.rbegin(); i != m_OutputLine.rend() && line < 10; ++i)
    {
        float time = Timer::getSingleton().GetSystemTimeTotal() - (*i).time;
        if(time < max_time)
        {
            Ogre::ColourValue colour = (*i).colour;
            colour.a = (max_time - time) / max_time;
            DEBUG_DRAW.SetColour(colour);
            DEBUG_DRAW.Text(5.0f, static_cast<float>(y), (*i).text);
            y -= 16;
            ++line;
        }
    }
}


void
Console::OnResize()
{
    // calculate width and height of console depending on size of application
    Ogre::RenderTarget *render_target(QGears::Application::getSingleton().getRenderWindow());
    m_ConsoleWidth = render_target->getWidth();
    m_ConsoleHeight = static_cast<int>(render_target->getHeight() / 2.5f);
    m_LineWidth = (m_ConsoleWidth - 20) / 8;

    LOG_TRIVIAL("Resized console width to " + Ogre::StringConverter::toString(m_ConsoleWidth) + ", height to " + Ogre::StringConverter::toString(m_ConsoleHeight));

    // update height of already opened console
    m_Height = (m_Height > m_ConsoleHeight) ? m_ConsoleHeight : m_Height;
}


void
Console::SetToVisible()
{
    m_ToVisible = true;
    m_Visible = true;
}


void
Console::SetToHide()
{
    m_ToVisible = false;
}


bool
Console::IsVisible() const
{
    return m_Visible;
}


void
Console::AddTextToOutput(const Ogre::String& text, const Ogre::ColourValue& colour)
{
    // go through line and add it to output correctly
    const char* str = text.c_str();
    Ogre::String output_line;
    unsigned int string_size = 0;
    bool indent = false;
    unsigned int c = 0;
    for(; c < text.size(); ++c)
    {
        // add space at start of string if we want indent
        if(string_size == 0 && indent == true)
        {
            output_line.push_back(' ');
            ++string_size;
        }

        if(str[c] != '\n')
        {
            output_line.push_back(str[c]);
            ++string_size;
        }

        if(str[c] == '\n' || string_size >= m_LineWidth || c >= text.size() - 1)
        {
            // if string is larger than output size than add indent
            indent = (string_size >= m_LineWidth) ? true : false;

            if(m_OutputLine.size() >= m_MaxOutputLine)
            {
                m_OutputLine.pop_front();
            }

            if(m_OutputLine.size() == m_DisplayLine)
            {
                ++m_DisplayLine;
            }

            OutputLine line;
            line.text = output_line;
            line.colour = colour;
            line.time = Timer::getSingleton().GetSystemTimeTotal();
            m_OutputLine.push_back(line);

            output_line.clear();
            string_size = 0;
        }
    }

    // add one more string if text ended with \n
    if(text.size() == 0 || str[text.size() - 1] == '\n')
    {
        if(m_OutputLine.size() >= m_MaxOutputLine)
        {
            m_OutputLine.pop_front();
        }

        if(m_OutputLine.size() == m_DisplayLine)
        {
            ++m_DisplayLine;
        }

        OutputLine line;
        line.text = "";
        line.colour = colour;
        line.time = Timer::getSingleton().GetSystemTimeTotal();
        m_OutputLine.push_back(line);
    }
}


void
Console::ExecuteCommand(const Ogre::String& command)
{
    bool handled = false;
    Ogre::StringVector params = StringTokenise(command);

    // is it cvar
    ConfigVar* cvar = ConfigVarManager::getSingleton().Find(params[0]);

    if(cvar != nullptr)
    {
        handled = true;

        if(params.size() > 1)
        {
            cvar->SetS(params[1]);

            AddTextToOutput(params[0] + " changed to \"" + params[1] + "\".\n");
        }
        else
        {
            AddTextToOutput(params[0] + " = \"" + cvar->GetS() + "\".\n" +
                            " default:\"" + cvar->GetDefaultValue() + "\".\n" +
                            " description: " + cvar->GetDescription() + ".\n" );
        }
    }

    if(handled == false)
    {
        // handle command
        ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find(params[0]);
        if(cmd != nullptr)
        {
            cmd->GetHandler()(params);
            return;
        }
        else
        {
            AddTextToOutput("Can't find command \"" + params[0] + "\".\n");
        }
    }
}


void
Console::ExecuteScript()
{
    ScriptManager::getSingleton().RunString(m_InputLine);
}


void
Console::CompleteInput()
{
    bool add_slash = false;

    if(m_AutoCompletition.size() == 0)
    {
        // remove backslash
        if(m_InputLine.size() > 0 && ('\\' == m_InputLine[0] || '/' == m_InputLine[0]))
        {
            m_InputLine.erase(0, 1);
        }

        size_t input_size = m_InputLine.size();

        Ogre::StringVector params = StringTokenise(m_InputLine);

        if(params.size() == 0)
        {
            // add cvars
            int num_vars = ConfigVarManager::getSingleton().GetConfigVarNumber();
            for(int i = 0; i < num_vars; ++i)
            {
                m_AutoCompletition.push_back(ConfigVarManager::getSingleton().GetConfigVar(i)->GetName());
            }

            // add commands
            int num_cmds = ConfigCmdManager::getSingleton().GetConfigCmdNumber();
            for(int i = 0; i < num_cmds; ++i)
            {
                m_AutoCompletition.push_back(ConfigCmdManager::getSingleton().GetConfigCmd(i)->GetName());
            }

            add_slash = true;
        }
        else if(params.size() == 1)
        {
            m_InputLine = params[0];

            // add cvars
            int num_vars = ConfigVarManager::getSingleton().GetConfigVarNumber();
            for(int i = 0; i < num_vars; ++i)
            {
                Ogre::String name = ConfigVarManager::getSingleton().GetConfigVar(i)->GetName();
                unsigned int pos = name.find(m_InputLine);
                if(pos == 0)
                {
                    add_slash = true;

                    if(input_size != name.size())
                    {
                        Ogre::String part = name.substr(input_size, name.size() - input_size);
                        m_AutoCompletition.push_back(part);
                    }
                }
            }

            // add commands
            int num_cmds = ConfigCmdManager::getSingleton().GetConfigCmdNumber();
            for(int i = 0; i < num_cmds; ++i)
            {
                Ogre::String name = ConfigCmdManager::getSingleton().GetConfigCmd(i)->GetName();

                int pos = name.find(m_InputLine);
                if(pos == 0)
                {
                    add_slash = true;

                    if(name != params[0])
                    {
                        Ogre::String part = name.substr(input_size, name.size() - input_size);
                        m_AutoCompletition.push_back(part);
                    }
                    else if(ConfigCmdManager::getSingleton().GetConfigCmd(i)->GetCompletion() != nullptr)
                    {
                        m_InputLine += " ";
                        ConfigCmdManager::getSingleton().GetConfigCmd(i)->GetCompletion()(m_AutoCompletition);
                    }
                }
            }
        }
        else if(params.size() > 1)
        {
            Ogre::String all_params = params[1];

            for(size_t i = 2; i < params.size(); ++i)
            {
                all_params += " " + params[i];
            }

            // add commands arguments
            ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find(params[0]);
            if(cmd != nullptr)
            {
                add_slash = true;

                if(cmd->GetCompletion() != nullptr)
                {
                    Ogre::StringVector full_complete;
                    cmd->GetCompletion()(full_complete);
                    if(full_complete.size() > 0)
                    {
                        std::sort(full_complete.begin(), full_complete.end());

                        for(size_t i = 0 ; i < full_complete.size(); ++i)
                        {
                            int pos = full_complete[i].find(all_params);
                            if(pos == 0 && all_params != full_complete[i])
                            {
                                Ogre::String part = full_complete[i].substr(all_params.size(), full_complete[i].size() - all_params.size());
                                m_AutoCompletition.push_back(part);
                            }
                        }
                    }
                }
            }

            m_InputLine = params[0] + " " + all_params;
        }

        // if we found at least one match
        if(add_slash == true)
        {
            m_InputLine = "/" + m_InputLine;
        }
        m_CursorPosition = m_InputLine.size();

        // sort list
        std::sort(m_AutoCompletition.begin(), m_AutoCompletition.end());
        m_AutoCompletitionLine = 0;

        for(size_t i = 0; i < m_AutoCompletition.size(); ++i)
        {
            AddTextToOutput(" " + m_InputLine + m_AutoCompletition[i]);
        }
        if(m_AutoCompletition.size() > 0)
        {
            AddTextToOutput("\n");
        }
    }
    else
    {
        if(m_AutoCompletitionLine < m_AutoCompletition.size() - 1)
        {
            ++m_AutoCompletitionLine;
        }
        else
        {
            m_AutoCompletitionLine = 0;
        }
    }
}


void
Console::ResetAutoCompletion()
{
    m_AutoCompletition.clear();
    m_AutoCompletitionLine = 0;
}


void
Console::AddInputToHistory()
{
    AddToHistory(m_InputLine);
}


void
Console::SetInputLineFromHistory()
{
    ResetAutoCompletion();

    std::list<Ogre::String>::iterator i = m_History.begin();
    for(int count = 0; i != m_History.end(); ++i, ++count)
    {
        if(count == m_HistoryLineCycleIndex)
        {
            m_InputLine = (*i);
            m_CursorPosition = m_InputLine.size();
            break;
        }
    }
}


void
Console::messageLogged(const Ogre::String& message, Ogre::LogMessageLevel lml, bool maskDebug, const Ogre::String& logName, bool& skipThisMessage)
{
    Ogre::ColourValue colour = Ogre::ColourValue::White;
    switch((int)lml)
    {
        case 2: colour = Ogre::ColourValue(1, 1, 0, 1); break;
        case 3: colour = Ogre::ColourValue(1, 0, 0, 1); break;
    }
    AddTextToOutput(message, colour);
}
