#ifndef DIALOGS_MANAGER_h
#define DIALOGS_MANAGER_h

#include <OgreSingleton.h>

#include "UiManager.h"
#include "UiTextArea.h"



enum MessageState
{
    MS_CLOSED,
    MS_SHOW_WINDOW,
    MS_SHOW_TEXT,
    MS_OPENED,
    MS_HIDE_WINDOW
};



enum MessageStyle
{
    MSL_SOLID,
    MSL_TRANSPARENT,
    MSL_NONE
};



struct MessageData
{
    MessageData():
        widget( NULL ),
        window( NULL ),
        scissor( NULL ),
        text_area( NULL ),
        cursor( NULL ),

        state( MS_CLOSED ),

        clickable( true ),
        show_window( true ),
        show_cursor( false ),
        auto_close( false ),

        cursor_percent_y( 0 ),
        cursor_y( 0 ),
        cursor_row_selected( 0 ),
        cursor_row_current( 0 ),
        cursor_row_first( 0 ),
        cursor_row_last( 0 )
    {
    }

    UiWidget* widget;
    UiWidget* window;
    UiWidget* scissor;
    UiTextArea* text_area;
    UiWidget* cursor;

    MessageState state;

    std::vector< ScriptId > sync;

    bool clickable;
    bool show_window;
    bool show_cursor;
    bool auto_close;

    float cursor_percent_y;
    float cursor_y;
    int cursor_row_selected;
    int cursor_row_current;
    int cursor_row_first;
    int cursor_row_last;
};



class DialogsManager : public Ogre::Singleton< DialogsManager >
{
public:
    DialogsManager();
    virtual ~DialogsManager();

    void Initialise();
    void Input( const QGears::Event& event );
    void Update();
    void Clear();

    void ShowDialog( const char* d_name, const char* name, const int x, const int y );
    void ShowText( const char* d_name, const char* text, const int x, const int y, const int width, const int height );
    int Sync( const char* d_name );
    void SetVariable( const char* d_name, const char* name, const char* value );
    void Hide( const char* d_name );
    void SetClickable( const char* d_name, const bool clickable );
    void SetCursor( const char* d_name, const int first_row, const int last_row );
    int GetCursor( const char* d_name ) const;

private:
    void ShowMessage( const int id, const int x, const int y, const int width, const int height );
    void HideMessage( const int id );
    int GetMessageId( const char* d_name ) const;
    bool AutoCloseCheck( const unsigned int id );

private:
    UiWidget* m_LimitArea;
    std::vector< MessageData* > m_Messages;

    bool m_NextPressed;
    bool m_NextRepeated;
    bool m_UpPressed;
    bool m_DownPressed;
};



#endif // DIALOGS_MANAGER_H
