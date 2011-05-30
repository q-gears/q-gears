#ifndef WINDOW_MANAGER_h
#define WINDOW_MANAGER_h

#include <Ogre.h>
#include <OgrePanelOverlayElement.h>
#include <vector>



// this is needed by MessageTextArea
enum MessageState
{
    MS_CLOSED,             // 0
    MS_SHOW_WINDOW,        // 1
    MS_SHOW_TEXT,          // 2
    MS_SCROLL_TEXT,        // 8
    MS_PAUSE_OK,           // D
    MS_PAUSE_TIME,         // 3 new
    MS_OPENED,             // 6
    MS_OPENED_OVERFLOW,    // 4
    MS_OPENED_NEXT_WINDOW, // E
    MS_HIDE_WINDOW         // 7
};



#include "FieldScriptManager.h"
#include "MessageTextArea.h"
#include "../core/Actor.h"
#include "../core/ui/Window.h"



class FieldModule;



enum MessageStyle
{
    MSL_SOLID,
    MSL_TRANSPARENT,
    MSL_NONE
};



struct MessageData
{
    MessageData():
        text(NULL),
        window(NULL),
        cursor(NULL),

        clickable(true),
        show_window(true),
        show_cursor(false),
        auto_close(false),

        state(MS_CLOSED),

        wait_time(0),

        window_width(0),
        window_height(0),
        window_x(0),
        window_y(0),

        init_text(0),
        init_text_speed_modifier(1),
        text_y(0),
        text_current_y(0),

        cursor_row_selected(0),
        cursor_row_current(0),
        cursor_row_first(0),
        cursor_row_last(0)
    {
    }

    MessageTextArea*           text;
    Window*                    window;
    Ogre::PanelOverlayElement* cursor;

    ScriptInfo                 script_info;

    bool                       clickable;
    bool                       show_window;
    bool                       show_cursor;
    bool                       auto_close;

    MessageState               state;

    float                      wait_time;

    float                      window_width;
    float                      window_height;
    float                      window_x;
    float                      window_y;

    float                      init_text;
    float                      init_text_speed_modifier;
    float                      text_y;
    float                      text_current_y;

    int                        cursor_row_selected;
    int                        cursor_row_current;
    int                        cursor_row_first;
    int                        cursor_row_last;
};



class MessageManager : public Actor
{
public:
                   MessageManager(FieldModule* field, FieldScriptManager* script);
    virtual       ~MessageManager(void);

    virtual void   Input(const Event& input);
    virtual void   Update(const float delta_time);

    void           ShowMessages(const bool show);
    void           ShowDebug(const bool show);

    void           ShowText(const int message_id, const int text_id, const int x, const int y);
    void           ShowText(const int message_id, const char* text, const int x, const int y, const int width, const int height);
    int            ShowTextWait(const int message_id, const int text_id, const int x, const int y);
    int            ShowTextWait(const int message_id, const char* text, const int x, const int y, const int width, const int height);
    void           Hide(const int message_id);
    void           SetStyle(const int message_id, const MessageStyle style);
    void           SetClickable(const int message_id, const bool clickable);
    void           SetCursor(const int message_id, const int first_row, const int last_row);
    int            GetCursor(const int message_id) const;

private:
    void           ShowMessage(const int message_id, const Ogre::DisplayString& text, const int x, const int y, const int width, const int height);
    void           HideMessage(const int message_id);

    bool           CheckMessageId(const int message_id) const;

private:
    FieldModule*                  m_FieldModule;
    FieldScriptManager*           m_FieldScriptManager;

    TextArea*                     m_DebugInfoText;
    Ogre::Overlay*                m_DebugInfoOverlay;

    Ogre::Overlay*                m_MessageOverlay;

    MessageData                   m_Messages[8];

    float                         m_MessageSpeed; // 1-255

    float                         m_WindowShowTime;
    float                         m_WindowHideTime;
    float                         m_WindowScrollTime;
    float                         m_WindowMinWidth;
    float                         m_WindowMinHeight;

    bool                          m_NextButtonPressed;
    bool                          m_NextButtonRepeated;
    bool                          m_UpButtonPressed;
    bool                          m_DownButtonPressed;
};



#endif // WINDOW_MANAGER_h
