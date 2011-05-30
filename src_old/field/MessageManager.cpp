// $Id$

#include <Ogre.h>

#include "FieldModule.h"
#include "MessageManager.h"
#include "../Main.h"
#include "../core/TextManager.h"
#include "../game/GameState.h"

Ogre::String message_state_string[10] = {"Closed", "Show Window", "Show Text", "Scroll Text", "Pause Ok", "Pause Time", "Opened", "Opened Overflow", "Opened Next Window", "Hide Window"};



MessageManager::MessageManager(FieldModule* field, FieldScriptManager* script):
    m_FieldModule(field),
    m_FieldScriptManager(script),

    m_MessageSpeed(256),
    m_WindowShowTime(0.135f),
    m_WindowHideTime(0.135f),
    m_WindowScrollTime(0.267f),
    m_WindowMinWidth(16),
    m_WindowMinHeight(16),

    m_NextButtonPressed(false),
    m_NextButtonRepeated(false),
    m_UpButtonPressed(false),
    m_DownButtonPressed(false)
{
    // debug info
    m_DebugInfoText = new TextArea("DebugMessageText");
    m_DebugInfoText->setCaption("");
    m_DebugInfoText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugInfoText->setPosition(5, 5);
    m_DebugInfoText->setTextAlignment(TextArea::LEFT);
    m_DebugInfoText->setFontName("DebugText");
    m_DebugInfoText->setCharHeight(18);

    m_DebugInfoOverlay = Ogre::OverlayManager::getSingleton().create("DebugMessageOverlay");
    m_DebugInfoOverlay->setZOrder(QGOO_FIELD_DEBUG);
    m_DebugInfoOverlay->add2D((Ogre::OverlayContainer*)m_DebugInfoText);

    m_MessageOverlay = Ogre::OverlayManager::getSingleton().create("MessageOverlay");
    m_MessageOverlay->setZOrder(QGOO_FIELD_MESSAGE);
    m_MessageOverlay->show();

    // dialog create
    for (int i = 0; i < 8; ++i)
    {
        m_Messages[i].window = new Window("FieldWindow" + Ogre::StringConverter::toString(i));
        m_Messages[i].window->setMetricsMode(Ogre::GMM_PIXELS);
        m_Messages[i].window->setMaterialName("field/dialog");
        m_Messages[i].window->SetBackgroundUV(0, 0.75f, 0.125f, 0.8125f);
        m_Messages[i].window->SetBackgroundTransparentUV(0, 0.8125f, 0.125f, 0.875f);
        m_Messages[i].window->SetTopLeftUV(0, 0.90625f, 0.03125f, 0.9375f);
        m_Messages[i].window->SetTopUV(0, 0.875f, 0.03125f, 0.90625f);
        m_Messages[i].window->SetTopRightUV(0.03125f, 0.90625f, 0.0625f, 0.9375f);
        m_Messages[i].window->SetLeftUV(0, 0.9375f, 0.03125f, 1);
        m_Messages[i].window->SetRightUV(0.09375f, 0.9375f, 0.125f, 1);
        m_Messages[i].window->SetBottomUV(0.0625f, 0.90625f, 0.125f, 0.9375f);
        m_Messages[i].window->SetBottomLeftUV(0.0625f, 0.875f, 0.09375f, 0.90625f);
        m_Messages[i].window->SetBottomRightUV(0.09375f, 0.875f, 0.125f, 0.90625f);
        m_Messages[i].window->setPosition(10, 10);
        m_Messages[i].window->setWidth(500);
        m_Messages[i].window->setHeight(300);
        m_Messages[i].window->hide();
        m_MessageOverlay->add2D(m_Messages[i].window);
        m_Messages[i].window->_notifyZOrder(m_MessageOverlay->getZOrder() * 100 + i * 2);

        m_Messages[i].text = new MessageTextArea("FieldWindowMessage" + Ogre::StringConverter::toString(i));
        m_Messages[i].text->setMetricsMode(Ogre::GMM_PIXELS);
        m_Messages[i].text->setTextAlignment(TextArea::LEFT);
        m_Messages[i].text->setFontName("FieldMessageText");
        m_Messages[i].text->setCharHeight(16);
        m_Messages[i].text->hide();
        //m_Messages[i].window->addChild(m_Messages[i].text);
        m_MessageOverlay->add2D(m_Messages[i].text);
        m_Messages[i].text->_notifyZOrder(m_MessageOverlay->getZOrder() * 100 + i * 2 + 1);

        m_Messages[i].cursor = (Ogre::PanelOverlayElement*)Ogre::OverlayManager::getSingleton().createOverlayElement("Panel", "FieldWindowCursor" + Ogre::StringConverter::toString(i));
        m_Messages[i].cursor->setMetricsMode(Ogre::GMM_PIXELS);
        m_Messages[i].cursor->setMaterialName("field/dialog");
        m_Messages[i].cursor->setUV(0, 0.6875f, 0.09375f, 0.75f);
        m_Messages[i].cursor->setPosition(0, 0);
        m_Messages[i].cursor->setWidth(24);
        m_Messages[i].cursor->setHeight(16);
        m_Messages[i].cursor->hide();
        //m_Messages[i].window->addChild(m_Messages[i].cursor);
        m_MessageOverlay->add2D(m_Messages[i].cursor);
        m_Messages[i].cursor->_notifyZOrder(m_MessageOverlay->getZOrder() * 100 + i * 2 + 1);
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("MessageManager created.");
}



MessageManager::~MessageManager(void)
{
    // delete debug
    m_DebugInfoOverlay->remove2D((Ogre::OverlayContainer*)m_DebugInfoText);
    delete m_DebugInfoText;
    Ogre::OverlayManager::getSingleton().destroy(m_DebugInfoOverlay);

    // dialog delete
    for (int i = 0; i < 8; ++i)
    {
        //m_MessageOverlay->remove2D(m_Messages[i].text);
        delete m_Messages[i].text;

        m_MessageOverlay->remove2D(m_Messages[i].window);
        delete m_Messages[i].window;

        //m_MessageOverlay->remove2D(m_Messages[i].cursor);
        Ogre::OverlayManager::getSingleton().destroyOverlayElement(m_Messages[i].cursor);
    }

    Ogre::OverlayManager::getSingleton().destroy(m_MessageOverlay);

    Ogre::LogManager::getSingletonPtr()->logMessage("MessageManager destroyed.");
}



void
MessageManager::Input(const Event& input)
{
    if (input.name == "game_ok")
    {
        m_NextButtonPressed = true;
    }
    else if (input.name == "game_ok_repeated")
    {
        m_NextButtonRepeated = true;
    }
    else if (input.name == "message_up")
    {
        m_UpButtonPressed = true;
    }
    else if (input.name == "message_down")
    {
        m_DownButtonPressed = true;
    }
}



void
MessageManager::Update(const float delta_time)
{
    for (int i = 0; i < 8; ++i)
    {
        switch (m_Messages[i].state)
        {
            case MS_SHOW_WINDOW:
            {
                float width_add = m_Messages[i].window_width * delta_time / m_WindowShowTime;
                float width_new = m_Messages[i].window->getWidth() + width_add;
                width_new = (width_new > m_Messages[i].window_width) ? m_Messages[i].window_width : width_new;
                m_Messages[i].window->setWidth(width_new);

                float height_add = m_Messages[i].window_height * delta_time / m_WindowShowTime;
                float height_new = m_Messages[i].window->getHeight() + height_add;
                height_new = (height_new > m_Messages[i].window_height) ? m_Messages[i].window_height : height_new;
                m_Messages[i].window->setHeight(height_new);

                float new_x = m_Messages[i].window_x + (m_Messages[i].window_width - width_new) / 2;
                float new_y = m_Messages[i].window_y + (m_Messages[i].window_height - height_new) / 2;
                m_Messages[i].window->setPosition(new_x, new_y);

                if (width_new == m_Messages[i].window_width && height_new == m_Messages[i].window_height)
                {
                    m_Messages[i].text->show();
                    m_Messages[i].state = MS_SHOW_TEXT;
                }
            }
            break;

            case MS_SHOW_TEXT:
            {
                if (m_Messages[i].auto_close == true)
                {
                    m_Messages[i].state = MS_HIDE_WINDOW;
                }

                float time = delta_time * 30;

                float addition, limit;
                //all
                    //A1 = 100;
                    //S5 = 1;
                //gragually
                if (m_Messages[i].clickable == true && (m_NextButtonPressed == true || m_NextButtonRepeated == true))
                {
                    m_Messages[i].init_text_speed_modifier += (m_Messages[i].init_text_speed_modifier >= 128) ? 0 : 1.0f * time;
                }
                else
                {
                    m_Messages[i].init_text_speed_modifier -= (m_Messages[i].init_text_speed_modifier <= 1) ? 0 : 1.0f * time;
                }

                if (m_MessageSpeed < 128)
                {
                    addition = ((128 - m_MessageSpeed) / 32) + 2;
                    limit = 1;
                }
                else
                {
                    addition = 2;
                    limit = ((m_MessageSpeed - 128) / 32) + 1;
                }

                float char_to_add = (limit * m_Messages[i].init_text_speed_modifier / 16 + addition) / limit;

                m_Messages[i].init_text += time * char_to_add;
                m_Messages[i].state = m_Messages[i].text->AddCharactersToDisplay(m_Messages[i].init_text, m_Messages[i].wait_time);

                switch (m_Messages[i].state)
                {
                    case MS_OPENED:
                    {
                        if (m_Messages[i].show_cursor == true)
                        {
                            m_Messages[i].cursor->setPosition(m_Messages[i].window_x + 5, m_Messages[i].window_y + m_Messages[i].cursor_row_current * m_Messages[i].text->getCharHeight() + 6);
                            m_Messages[i].cursor->show();
                        }
                    }
                    break;
                }
            }
            break;

            case MS_SCROLL_TEXT:
            {
                if (m_Messages[i].auto_close == true)
                {
                    m_Messages[i].state = MS_HIDE_WINDOW;
                }

                float position_add = m_Messages[i].text->getCharHeight() * delta_time / m_WindowScrollTime;
                m_Messages[i].text_current_y = m_Messages[i].text_current_y - position_add;
                m_Messages[i].text_current_y = (m_Messages[i].text_current_y < m_Messages[i].text_y) ? m_Messages[i].text_y : m_Messages[i].text_current_y;
                m_Messages[i].text->setTop((int)m_Messages[i].text_current_y);

                // clip text
                m_Messages[i].text->SetClipping(0, m_Messages[i].window_x - m_Messages[i].text->getTop() + 3, 0, 0);

                if (m_Messages[i].text_current_y == m_Messages[i].text_y)
                {
                    m_Messages[i].init_text_speed_modifier = 1;
                    m_Messages[i].state = MS_SHOW_TEXT;
                }
            }
            break;

            case MS_PAUSE_OK:
            {
                if (m_Messages[i].auto_close == true)
                {
                    m_Messages[i].state = MS_HIDE_WINDOW;
                }

                if (m_Messages[i].clickable == true && m_NextButtonPressed == true)
                {
                    m_Messages[i].init_text_speed_modifier = 1;
                    m_Messages[i].state = MS_SHOW_TEXT;
                }
            }
            break;

            case MS_PAUSE_TIME:
            {
                if (m_Messages[i].auto_close == true)
                {
                    m_Messages[i].state = MS_HIDE_WINDOW;
                }

                m_Messages[i].wait_time -= delta_time;

                if (m_Messages[i].wait_time <= 0)
                {
                    m_Messages[i].init_text_speed_modifier = 1;
                    m_Messages[i].state = MS_SHOW_TEXT;
                }
            }
            break;

            case MS_OPENED:
            {
                if (m_Messages[i].show_cursor == true && m_Messages[i].clickable == true)
                {
                    if (m_UpButtonPressed == true)
                    {
                        --(m_Messages[i].cursor_row_current);
                    }
                    else if (m_DownButtonPressed == true)
                    {
                        ++(m_Messages[i].cursor_row_current);
                    }

                    m_Messages[i].cursor_row_current = (m_Messages[i].cursor_row_current < m_Messages[i].cursor_row_first) ? m_Messages[i].cursor_row_last : m_Messages[i].cursor_row_current;
                    m_Messages[i].cursor_row_current = (m_Messages[i].cursor_row_current > m_Messages[i].cursor_row_last) ? m_Messages[i].cursor_row_first : m_Messages[i].cursor_row_current;

                    m_Messages[i].cursor->setPosition(m_Messages[i].window_x + 5, m_Messages[i].window_y + m_Messages[i].cursor_row_current * m_Messages[i].text->getCharHeight() + 6);
                }

                if ((m_Messages[i].auto_close == true) || (m_Messages[i].clickable == true && m_NextButtonPressed == true))
                {
                    if (m_Messages[i].show_cursor == true)
                    {
                        m_Messages[i].show_cursor = false;
                        m_Messages[i].cursor_row_selected = m_Messages[i].cursor_row_current;
                        m_Messages[i].cursor->hide();
                    }

                    m_Messages[i].state = MS_HIDE_WINDOW;
                }
            }
            break;

            case MS_OPENED_OVERFLOW:
            {
                if (m_Messages[i].auto_close == true)
                {
                    m_Messages[i].state = MS_HIDE_WINDOW;
                }

                if (m_Messages[i].clickable == true && m_NextButtonPressed == true)
                {
                    m_Messages[i].text_current_y = m_Messages[i].text->getTop();
                    m_Messages[i].text->setHeight(m_Messages[i].text->getHeight() + m_Messages[i].text->getCharHeight());
                    m_Messages[i].text->SetTopRow(m_Messages[i].text->GetTopRow() + 1);
                    m_Messages[i].text_y -= m_Messages[i].text->getCharHeight();
                    m_Messages[i].state = MS_SCROLL_TEXT;
                }
            }
            break;

            case MS_OPENED_NEXT_WINDOW:
            {
                if (m_Messages[i].auto_close == true)
                {
                    m_Messages[i].state = MS_HIDE_WINDOW;
                }

                if (m_Messages[i].clickable == true && m_NextButtonPressed == true)
                {
                    m_Messages[i].text->setTop(m_Messages[i].window_y + 6);
                    m_Messages[i].text->ClearCurrentCaption();
                    // reset text clipping
                    m_Messages[i].text->SetClipping(0, 0, 0, 0);

                    m_Messages[i].text_y = m_Messages[i].window_y + 6;

                    m_Messages[i].init_text_speed_modifier = 1;
                    m_Messages[i].state = MS_SHOW_TEXT;
                }
            }
            break;

            case MS_HIDE_WINDOW:
            {
                float width_add = m_Messages[i].window_width * delta_time / m_WindowHideTime;
                float width_new = m_Messages[i].window->getWidth() - width_add;
                width_new = (width_new < m_WindowMinWidth) ? m_WindowMinWidth : width_new;
                m_Messages[i].window->setWidth(width_new);

                float height_add = m_Messages[i].window_height * delta_time / m_WindowHideTime;
                float height_new = m_Messages[i].window->getHeight() - height_add;
                height_new = (height_new < m_WindowMinHeight) ? m_WindowMinHeight : height_new;
                m_Messages[i].window->setHeight(height_new);

                float new_x = m_Messages[i].window_x + (m_Messages[i].window_width - width_new) / 2;
                float new_y = m_Messages[i].window_y + (m_Messages[i].window_height - height_new) / 2;
                m_Messages[i].window->setPosition(new_x, new_y);

                // clip text
                float left_right_clip = (m_Messages[i].window_width - width_new) / 2;
                float top_bottom_clip = (m_Messages[i].window_height - height_new) / 2;
                // we clip in window border
                m_Messages[i].text->SetClipping(left_right_clip - 8 + 3, m_Messages[i].window_x - m_Messages[i].text->getTop() + top_bottom_clip + 3, left_right_clip, top_bottom_clip);

                if (width_new == m_WindowMinWidth && height_new == m_WindowMinHeight)
                {
                    this->HideMessage(i);
                }
            }
            break;
        }
    }



    if (m_DebugInfoOverlay->isVisible() == true)
    {
        Ogre::String caption;

        for (int i = 0; i < 8; ++i)
        {
            caption += Ogre::StringConverter::toString(i) + ": " + message_state_string[m_Messages[i].state];

            if (m_Messages[i].state == MS_SHOW_TEXT)
            {
                caption += "(" + Ogre::StringConverter::toString(m_Messages[i].text->GetCaptionSize()) + "/" + Ogre::StringConverter::toString(m_Messages[i].text->GetCaptionRealSize()) + ")";
            }

            if (m_Messages[i].state == MS_PAUSE_TIME)
            {
                caption += "(" + Ogre::StringConverter::toString(m_Messages[i].wait_time) + ")";
            }

            caption += "\n";
        }

        m_DebugInfoText->setCaption(caption);
    }



    m_NextButtonPressed = false;
    m_NextButtonRepeated = false;
    m_UpButtonPressed = false;
    m_DownButtonPressed = false;
}



void
MessageManager::ShowMessages(const bool show)
{
    if (show == true)
    {
        m_MessageOverlay->show();
    }
    else
    {
        m_MessageOverlay->hide();
    }
}



void
MessageManager::ShowDebug(const bool show)
{
    if (show == true)
    {
        m_DebugInfoOverlay->show();
    }
    else
    {
        m_DebugInfoOverlay->hide();
    }
}



void
MessageManager::ShowText(const int message_id, const int text_id, const int x, const int y)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return;
    }

    if (m_Messages[message_id].state != MS_CLOSED)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text: window '" + Ogre::StringConverter::toString(message_id) + "' already shown. Close it first.");
        return;
    }

    TextData text = g_TextManager->GetText(text_id);

    this->ShowMessage(message_id, text.text, x, y, text.width, text.height);
}



void
MessageManager::ShowText(const int message_id, const char* text, const int x, const int y, const int width, const int height)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return;
    }

    if (m_Messages[message_id].state != MS_CLOSED)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text: window '" + Ogre::StringConverter::toString(message_id) + "' already shown. Close it first.");
        return;
    }

    this->ShowMessage(message_id, text, x, y, width, height);
}



int
MessageManager::ShowTextWait(const int message_id, const int text_id, const int x, const int y)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_wait: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return 1;
    }

    if (m_Messages[message_id].state != MS_CLOSED)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_wait: window '" + Ogre::StringConverter::toString(message_id) + "' already shown. Close it first.");
        return 1;
    }

    if (m_Messages[message_id].script_info.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_wait: Window already in waiting state.");
        return 1;
    }

    TextData text = g_TextManager->GetText(text_id);
    this->ShowMessage(message_id, text.text, x, y, text.width, text.height);

    m_Messages[message_id].script_info = m_FieldScriptManager->GetCurrentScriptInfo();

    return -1;
}



int
MessageManager::ShowTextWait(const int message_id, const char* text, const int x, const int y, const int width, const int height)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_wait: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return 1;
    }

    if (m_Messages[message_id].state != MS_CLOSED)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_wait: window '" + Ogre::StringConverter::toString(message_id) + "' already shown. Close it first.");
        return 1;
    }

    if (m_Messages[message_id].script_info.entity_id != -1)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_wait: Window already in waiting state.");
        return 1;
    }

    this->ShowMessage(message_id, text, x, y, width, height);

    m_Messages[message_id].script_info = m_FieldScriptManager->GetCurrentScriptInfo();

    return -1;
}



void
MessageManager::Hide(const int message_id)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] hide: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return;
    }

    if (m_Messages[message_id].state == MS_CLOSED)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] hide: window '" + Ogre::StringConverter::toString(message_id) + "' already closed. Open it first.");
        return;
    }

    m_Messages[message_id].auto_close = true;
}



void
MessageManager::SetStyle(const int message_id, const MessageStyle style)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] set_style: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return;
    }

    switch (style)
    {
        case MSL_SOLID:
        {
            m_Messages[message_id].show_window = true;
            m_Messages[message_id].window->SetTransparent(false);

            if (m_Messages[message_id].state != MS_CLOSED)
            {
                m_Messages[message_id].window->show();
            }
        }
        break;

        case MSL_TRANSPARENT:
        {
            m_Messages[message_id].show_window = true;
            m_Messages[message_id].window->SetTransparent(true);

            if (m_Messages[message_id].state != MS_CLOSED)
            {
                m_Messages[message_id].window->show();
            }
        }
        break;

        case MSL_NONE:
        {
            m_Messages[message_id].show_window = false;

            if (m_Messages[message_id].state != MS_CLOSED)
            {
                m_Messages[message_id].window->hide();
            }
        }
        break;
    }
}



void
MessageManager::SetClickable(const int message_id, const bool clickable)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] set_clickable: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return;
    }

    m_Messages[message_id].clickable = clickable;
}



void
MessageManager::SetCursor(const int message_id, const int first_row, const int last_row)
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_cursor: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return;
    }

    if (m_Messages[message_id].state != MS_CLOSED)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_cursor: window '" + Ogre::StringConverter::toString(message_id) + "' already shown. Close it first.");
        return;
    }

    m_Messages[message_id].show_cursor = true;
    m_Messages[message_id].cursor_row_current = first_row;
    m_Messages[message_id].cursor_row_first = first_row;
    m_Messages[message_id].cursor_row_last = last_row;
}



int
MessageManager::GetCursor(const int message_id) const
{
    if (CheckMessageId(message_id) == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] show_text_cursor: given message_id '" + Ogre::StringConverter::toString(message_id) + "' doesn't exist.");
        return 0;
    }

    return m_Messages[message_id].cursor_row_selected;
}



void
MessageManager::ShowMessage(const int message_id, const Ogre::DisplayString& text, const int x, const int y, const int width, const int height)
{
    m_Messages[message_id].text->setPosition(x + 8, y + 6);
    m_Messages[message_id].text_y = y + 6;
    m_Messages[message_id].text->setCaption(text);
    // set text width no larger than window size without border
    m_Messages[message_id].text->setWidth(width - 8 - 3);
    m_Messages[message_id].text->setHeight(height - 6 - 3);
    m_Messages[message_id].text->SetMaxRowHeight((height - 6 - 3) / 16);
    // reset text clipping
    m_Messages[message_id].text->SetClipping(0, 0, 0, 0);

    m_Messages[message_id].auto_close = false;

    m_Messages[message_id].init_text = 0;
    m_Messages[message_id].init_text_speed_modifier = 1;

    m_Messages[message_id].window_width = width;
    m_Messages[message_id].window_height = height;
    m_Messages[message_id].window_x = x;
    m_Messages[message_id].window_y = y;

    m_Messages[message_id].window->setPosition(x, y);
    m_Messages[message_id].window->setWidth(m_WindowMinWidth);
    m_Messages[message_id].window->setHeight(m_WindowMinHeight);

    if (m_Messages[message_id].show_window == true)
    {
        m_Messages[message_id].window->show();
    }

    m_Messages[message_id].state = MS_SHOW_WINDOW;
}



void
MessageManager::HideMessage(const int message_id)
{
    m_Messages[message_id].auto_close = false;
    m_Messages[message_id].state = MS_CLOSED;

    if (m_Messages[message_id].text != NULL)
    {
        m_Messages[message_id].text->hide();
    }

    if (m_Messages[message_id].window != NULL)
    {
        m_Messages[message_id].window->hide();
    }

    if (m_Messages[message_id].script_info.entity_id != -1)
    {
        m_FieldScriptManager->ContinueEntityScriptExecution(m_Messages[message_id].script_info);
        m_Messages[message_id].script_info.entity_id = -1;
    }
}



bool
MessageManager::CheckMessageId(const int message_id) const
{
    return message_id >= 0 && message_id < 8;
}
