#include "Console.h"

#include <OgreFontManager.h>

#include "ConfigCmdManager.h"
#include "ConfigVarManager.h"
#include "DebugDraw.h"
#include "Logger.h"
#include "ScriptManager.h"
#include "Timer.h"
#include "Utilites.h"



template<>Console *Ogre::Singleton< Console >::ms_Singleton = NULL;



Console::Console():
    m_ToVisible( false ),
    m_Visible( false ),
    m_Height( 0 ),

    m_MaxOutputLine( 128 ),
    m_DisplayLine( 0 ),
    m_InputLine( "" ),
    m_CursorPosition( 0 ),
    m_CursorBlinkTime( 0 ),

    m_HistoryLine( -1 ),
    m_HistorySize( 32 ),

    m_AutoCompletitionLine( 0 )
{
    Ogre::FontPtr font = Ogre::FontManager::getSingletonPtr()->getByName( "CourierNew" );
    if( font.isNull() == false )
    {
        m_LetterWidth = font->getGlyphAspectRatio( '_' ) * 16;
    }
    else
    {
        LOG_ERROR( "Console::frameStarted: Font for console not found." );
    }

    // calculate width and height of console depending on size of application
    m_ConsoleWidth = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getWidth();
    m_ConsoleHeight = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getHeight() / 2.5f;
    m_LineWidth = ( m_ConsoleWidth - 20 ) / 8;

    LOG_TRIVIAL( "Created console width " + Ogre::StringConverter::toString( m_ConsoleWidth ) + ", height " + Ogre::StringConverter::toString( m_ConsoleHeight ) );

    // add as frame and log listner
    Ogre::LogManager::getSingleton().getDefaultLog()->addListener( this );
}



Console::~Console()
{
    // remove as listner
    Ogre::LogManager::getSingleton().getDefaultLog()->removeListener( this );
}



void
Console::Input( const Event& event )
{
    if (m_Visible != true)
    {
        // add console
        if (event.type == ET_KEY_PRESS && event.param1 == OIS::KC_GRAVE)
        {
            SetToVisible();
        }

        return;
    }

    // input command
    else if( event.type == ET_KEY_PRESS && event.param1 == OIS::KC_RETURN && m_InputLine.size() )
    {
        if( m_AutoCompletition.size() > 0 )
        {
            m_InputLine += m_AutoCompletition[ m_AutoCompletitionLine ];
        }

        AddTextToOutput( m_InputLine );
        AddInputToHistory();

        // backslashed text are console commands, otherwise - script commands
        if( '\\' == m_InputLine[ 0 ] || '/' == m_InputLine[ 0 ] )
        {
            ExecuteCommand();
        }
        else
        {
            ExecuteScript();
        }

        m_InputLine.clear();
        m_CursorPosition = 0;
        ResetAutoCompletion();
    }
    else if( event.type == ET_KEY_PRESS && event.param1 == OIS::KC_TAB )
    {
        CompleteInput();
    }
    // remove console
    else if( event.type == ET_KEY_PRESS && event.param1 == OIS::KC_GRAVE )
    {
        SetToHide();
    }
    // history up
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_UP )
    {
        if( m_HistoryLine < ( int )m_History.size() - 1 )
        {
            ++m_HistoryLine;
            SetInputLineFromHistory();
        }
    }
    // history down
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_DOWN )
    {
        if( m_HistoryLine > 0 )
        {
            --m_HistoryLine;
            SetInputLineFromHistory();
        }
    }
    // scroll display to previous row
    else if( event.type == ET_MOUSE_SCROLL && event.param1 > 0 )
    {
        if( m_DisplayLine > 0 )
        {
            m_DisplayLine -= 1;
        }
    }
    // scroll display to next row
    else if( event.type == ET_MOUSE_SCROLL && event.param1 < 0 )
    {
        if( m_DisplayLine < m_OutputLine.size() )
        {
            m_DisplayLine += 1;
        }
    }
    // scroll display to previous row
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_PGUP )
    {
        if( m_DisplayLine > 0 )
        {
            m_DisplayLine -= 1;
        }
    }
    // scroll display to next row
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_PGDOWN )
    {
        if( m_DisplayLine < m_OutputLine.size() )
        {
            m_DisplayLine += 1;
        }
    }
    // delete character after cursor
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_DELETE )
    {
        if( m_AutoCompletition.size() > 0 )
        {
            ResetAutoCompletion();
        }
        else
        {
            if( m_InputLine.size() > 0 && m_CursorPosition < m_InputLine.size() )
            {
                m_InputLine.erase( m_CursorPosition, 1 );
            }
        }
    }
    // delete character before cursor
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_BACK )
    {
        if( m_AutoCompletition.size() > 0 )
        {
            ResetAutoCompletion();
        }
        else
        {
            if( m_CursorPosition > 0 )
            {
                m_InputLine.erase( m_CursorPosition - 1, 1 );
                --m_CursorPosition;
            }
        }
    }
    // move cursor to left
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_LEFT )
    {
        if( m_AutoCompletition.size() > 0 )
        {
            m_InputLine += m_AutoCompletition[ m_AutoCompletitionLine ];
            ResetAutoCompletion();
        }

        if( m_CursorPosition > 0 )
        {
            --m_CursorPosition;
        }
    }
    // move cursor to right
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && event.param1 == OIS::KC_RIGHT )
    {
        if( m_AutoCompletition.size() > 0 )
        {
            m_InputLine += m_AutoCompletition[ m_AutoCompletitionLine ];
            ResetAutoCompletion();
        }

        if( m_CursorPosition <  m_InputLine.size() )
        {
            ++m_CursorPosition;
        }
    }
    else if ( event.type == ET_KEY_PRESS && event.param1 == OIS::KC_ESCAPE )
    {
        m_InputLine.clear();
        m_CursorPosition = 0;
        ResetAutoCompletion();
    }
    // move cursor to start of string
    else if( event.type == ET_KEY_PRESS && event.param1 == OIS::KC_HOME )
    {
        m_CursorPosition = 0;

        if( m_AutoCompletition.size() > 0 )
        {
            m_InputLine += m_AutoCompletition[ m_AutoCompletitionLine ];
            ResetAutoCompletion();
        }
    }
    // move cursor to end of string
    else if( event.type == ET_KEY_PRESS && event.param1 == OIS::KC_END )
    {
        if( m_AutoCompletition.size() > 0 )
        {
            m_InputLine += m_AutoCompletition[ m_AutoCompletitionLine ];
            ResetAutoCompletion();
        }

        m_CursorPosition = m_InputLine.size();
    }
    // input ascii character
    else if( ( event.type == ET_KEY_PRESS || event.type == ET_KEY_REPEAT ) && m_InputLine.size() < m_LineWidth )
    {
        char legalchars[] = "ABCDEFGHIJKLMNOPQRSTUVWXUZabcdefghijklmnopqrstuvwxyz1234567890~!@#$%^&*()-_=+?{[]}|\\;:'\"<>,./? ";
        char txt = event.param2;
        for( int c = 0; c < sizeof( legalchars ) - 1; ++c )
        {
            if( legalchars[ c ] == txt )
            {
                std::string::iterator i = m_InputLine.begin() + m_CursorPosition;
                m_InputLine.insert( i, txt );
                ++m_CursorPosition;
                ResetAutoCompletion();
                break;
            }
        }
    }
}



void
Console::Update()
{
    float delta_time = Timer::getSingleton().GetSystemTimeDelta();

    if( m_ToVisible == true && m_Height < m_ConsoleHeight )
    {
        m_Height += delta_time * 1500;

        if( m_Height >= m_ConsoleHeight )
        {
            m_Height = m_ConsoleHeight;
        }
    }
    else if( m_ToVisible == false && m_Height > 0 )
    {
        m_Height -= delta_time * 1500;

        if( m_Height <= 0 )
        {
            m_Height = 0;
            m_Visible = false;
        }
    }

    UpdateDraw();
}



void
Console::UpdateDraw()
{
    float delta_time = Timer::getSingleton().GetSystemTimeDelta();

    DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
    DEBUG_DRAW.SetScreenSpace( true );
    DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.05f, 0.06f, 0.2f, 1 ) );
    DEBUG_DRAW.SetZ( -0.5f );
    DEBUG_DRAW.Quad( 0, 0, m_ConsoleWidth, 0, m_ConsoleWidth, m_Height, 0, m_Height );
    DEBUG_DRAW.SetColour( Ogre::ColourValue(  0.18f, 0.22f, 0.74f, 1 ) );
    DEBUG_DRAW.SetZ( -0.6f );
    DEBUG_DRAW.Line( 0, m_Height, m_ConsoleWidth, m_Height );

    int row = 1;
    int rows = ( m_ConsoleHeight - 30 ) / 16;
    int y = -m_ConsoleHeight + m_Height;
    int empty = rows - m_DisplayLine;
    if( empty > 0 )
    {
        y += empty * 16;
    }

    std::list< OutputLine >::iterator i;
    for( i = m_OutputLine.begin(); i != m_OutputLine.end(); ++i, ++row )
    {
        if( row > m_DisplayLine - rows && row <= m_DisplayLine )
        {
            DEBUG_DRAW.SetColour( ( *i ).colour );
            DEBUG_DRAW.Text( 5, y, ( *i ).text );
            y += 16;
        }
    }
    if( m_DisplayLine != m_OutputLine.size() )
    {
        Ogre::String temp = "";
        for( int i = 0; i < m_LineWidth; ++i )
        {
            temp += "^";
        }
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 0, 0, 1 ) );
        DEBUG_DRAW.Text( 5, y, temp );
    }



    m_CursorBlinkTime += delta_time;
    if( ( ( ( int )( m_CursorBlinkTime * 1000 ) ) >> 8 ) & 1 )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0.88f, 0.88f, 0.88f, 1 ) );
        DEBUG_DRAW.Text( 12 + m_CursorPosition * m_LetterWidth, -19 + m_Height, "_" );
    }


    if( m_AutoCompletition.size() > 0 )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
        DEBUG_DRAW.Text( 12, -20 + m_Height, m_InputLine);
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 0, 1, 0, 1 ) );
        DEBUG_DRAW.Text( 12 + ( m_InputLine.size() * m_LetterWidth ), -20 + m_Height, m_AutoCompletition[ m_AutoCompletitionLine ] );
    }
    else
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue( 1, 1, 1, 1 ) );
        DEBUG_DRAW.Text( 12, -20 + m_Height, m_InputLine );
    }

    DEBUG_DRAW.SetZ( 0 );
}



void
Console::OnResize()
{
    // calculate width and height of console depending on size of application
    m_ConsoleWidth = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getWidth();
    m_ConsoleHeight = Ogre::Root::getSingleton().getRenderTarget( "QGearsWindow" )->getHeight() / 2.5f;
    m_LineWidth = ( m_ConsoleWidth - 20 ) / 8;

    LOG_TRIVIAL( "Resized console width to " + Ogre::StringConverter::toString( m_ConsoleWidth ) + ", height to " + Ogre::StringConverter::toString( m_ConsoleHeight ) );

    // update height of already opened console
    m_Height = ( m_Height > m_ConsoleHeight) ? m_ConsoleHeight : m_Height;
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
Console::AddTextToOutput( const Ogre::String& text, const Ogre::ColourValue& colour )
{
    // go through line and add it to output correctly
    const char* str = text.c_str();
    Ogre::String output_line;
    int string_size = 0;
    bool indent = false;
    int c = 0;
    for( ; c < text.size(); ++c )
    {
        // add space at start of string if we want indent
        if( string_size == 0 && indent == true )
        {
            output_line.push_back( ' ' );
            ++string_size;
        }

        if( str[ c ] != '\n' )
        {
            output_line.push_back( str[ c ] );
            ++string_size;
        }

        if( str[ c ] == '\n' || string_size >= m_LineWidth || c >= text.size() - 1 )
        {
            // if string is larger than output size than add indent
            indent = ( string_size >= m_LineWidth ) ? true : false;

            if( m_OutputLine.size() >= m_MaxOutputLine )
            {
                m_OutputLine.pop_front();
            }

            if( m_OutputLine.size() == m_DisplayLine )
            {
                ++m_DisplayLine;
            }

            OutputLine line;
            line.text = output_line;
            line.colour = colour;
            m_OutputLine.push_back( line );
            output_line.clear();
            string_size = 0;
        }
    }

    // add one more string if text ended with \n
    if( text.size() == 0 || str[ text.size() - 1 ] == '\n' )
    {
        if( m_OutputLine.size() >= m_MaxOutputLine )
        {
            m_OutputLine.pop_front();
        }

        if( m_OutputLine.size() == m_DisplayLine )
        {
            ++m_DisplayLine;
        }

        OutputLine line;
        line.text = "";
        line.colour = colour;
        m_OutputLine.push_back( line );
    }
}



void
Console::ExecuteCommand()
{
    bool handled = false;

    // remove backslash
    m_InputLine.erase( 0, 1 );

    Ogre::StringVector params = StringTokenise( m_InputLine );

    // is it cvar
    ConfigVar* cvar = ConfigVarManager::getSingleton().Find( params[ 0 ] );

    if( cvar != NULL )
    {
        handled = true;

        if( params.size() > 1 )
        {
            cvar->SetS( params[ 1 ] );

            AddTextToOutput( params[ 0 ] + " changed to \"" + params[ 1 ] + "\".\n" );
        }
        else
        {
            AddTextToOutput( params[ 0 ] + " = \"" + cvar->GetS() + "\".\n" +
                            " default:\"" + cvar->GetDefaultValue() + "\".\n" +
                            " description: " + cvar->GetDescription() + ".\n" );
        }
    }

    if( handled == false )
    {
        // handle command
        ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find(params[0]);
        if (cmd != NULL)
        {
            cmd->GetHandler()(params);
            return;
        }
        else
        {
            AddTextToOutput( "Can't find command \"" + params[ 0 ] + "\".\n" );
        }
    }
}



void
Console::ExecuteScript()
{
    ScriptManager::getSingleton().RunString( m_InputLine );
}



void
Console::CompleteInput()
{
    if( m_AutoCompletition.size() == 0 )
    {
        // remove backslash
        if( m_InputLine.size() > 0 && ( '\\' == m_InputLine[ 0 ] || '/' == m_InputLine[ 0 ] ) )
        {
            m_InputLine.erase( 0, 1 );
        }

        int input_size = m_InputLine.size();

        Ogre::StringVector params = StringTokenise( m_InputLine );

        if( params.size() == 0 )
        {
            // add cvars
            int num_vars = ConfigVarManager::getSingleton().GetConfigVarNumber();
            for( int i = 0; i < num_vars; ++i )
            {
                m_AutoCompletition.push_back( ConfigVarManager::getSingleton().GetConfigVar( i )->GetName() );
            }

            // add commands
            int num_cmds = ConfigCmdManager::getSingleton().GetConfigCmdNumber();
            for( int i = 0; i < num_cmds; ++i )
            {
                m_AutoCompletition.push_back( ConfigCmdManager::getSingleton().GetConfigCmd( i )->GetName() );
            }
        }
        else if( params.size() == 1 )
        {
            m_InputLine = params[ 0 ];

            // add cvars
            int num_vars = ConfigVarManager::getSingleton().GetConfigVarNumber();
            for( int i = 0; i < num_vars; ++i )
            {
                Ogre::String name = ConfigVarManager::getSingleton().GetConfigVar( i )->GetName();
                int pos = name.find( m_InputLine );
                if( pos == 0 && input_size != name.size() )
                {
                    Ogre::String part = name.substr( input_size, name.size() - input_size );
                    m_AutoCompletition.push_back( part );
                }
            }

            // add commands
            int num_cmds = ConfigCmdManager::getSingleton().GetConfigCmdNumber();
            for( int i = 0; i < num_cmds; ++i )
            {
                Ogre::String name = ConfigCmdManager::getSingleton().GetConfigCmd( i )->GetName();

                int pos = name.find( m_InputLine );
                if( pos == 0 && name != params[ 0 ] )
                {
                    Ogre::String part = name.substr( input_size, name.size() - input_size );
                    m_AutoCompletition.push_back( part );
                }
                else if( name == params[ 0 ] && ConfigCmdManager::getSingleton().GetConfigCmd( i )->GetCompletion() != NULL )
                {
                    m_InputLine += " ";
                    ConfigCmdManager::getSingleton().GetConfigCmd( i )->GetCompletion()( m_AutoCompletition );
                }
            }
        }
        else if( params.size() > 1 )
        {
            Ogre::String all_params = params[ 1 ];
            for( int i = 2; i < params.size(); ++i )
            {
                all_params += " " + params[ i ];
            }

            // add commands arguments
            ConfigCmd* cmd = ConfigCmdManager::getSingleton().Find( params[ 0 ] );
            if( cmd != NULL )
            {
                if( cmd->GetCompletion() != NULL )
                {
                    Ogre::StringVector full_complete;
                    cmd->GetCompletion()( full_complete );
                    if( full_complete.size() > 0 )
                    {
                        std::sort( full_complete.begin(), full_complete.end() );

                        for( int i = 0 ; i < full_complete.size(); ++i )
                        {
                            int pos = full_complete[ i ].find( all_params );
                            if( pos == 0 && all_params != full_complete[ i ] )
                            {
                                Ogre::String part = full_complete[ i ].substr( all_params.size(), full_complete[ i ].size() - all_params.size() );
                                m_AutoCompletition.push_back( part );
                            }
                        }
                    }
                }
            }

            m_InputLine = params[ 0 ] + " " + all_params;
        }

        m_InputLine = "/" + m_InputLine;
        m_CursorPosition = m_InputLine.size();

        // sort list
        std::sort( m_AutoCompletition.begin(), m_AutoCompletition.end() );
        m_AutoCompletitionLine = 0;

        for( int i = 0; i < m_AutoCompletition.size(); ++i )
        {
            AddTextToOutput( " " + m_InputLine + m_AutoCompletition[ i ] );
        }
        if( m_AutoCompletition.size() > 0 )
        {
            AddTextToOutput( "\n" );
        }
    }
    else
    {
        if( m_AutoCompletitionLine < m_AutoCompletition.size() - 1 )
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
    if( m_History.size() >= m_HistorySize )
    {
        m_History.pop_back();
    }
    m_History.push_front( m_InputLine );
    m_HistoryLine = -1;
}



void
Console::SetInputLineFromHistory()
{
    std::list< Ogre::String >::iterator i = m_History.begin();
    for( int count = 0; i != m_History.end(); ++i, ++count )
    {
        if( count == m_HistoryLine )
        {
            m_InputLine = ( *i );
            m_CursorPosition = m_InputLine.size();
            break;
        }
    }
}



void
Console::messageLogged( const Ogre::String& message, Ogre::LogMessageLevel lml, bool maskDebug, const Ogre::String& logName )
{
    Ogre::ColourValue colour = Ogre::ColourValue::White;
    switch( ( int )lml )
    {
        case 2: colour = Ogre::ColourValue( 1, 1, 0, 1 ); break;
        case 3: colour = Ogre::ColourValue( 1, 0, 0, 1 ); break;
    }
    AddTextToOutput( message, colour );
};
