#include "core/DialogsManager.h"

#include "core/ConfigVar.h"
#include "core/DebugDraw.h"
#include "core/Logger.h"
#include "core/TextManager.h"



template<>DialogsManager *Ogre::Singleton< DialogsManager >::msSingleton = NULL;



ConfigVar cv_debug_message( "debug_message", "Draw message debug", "false" );

Ogre::String message_state_string[ 5 ] = {"Closed", "Show Window", "Show Text", "Opened", "Hide Window"};



DialogsManager::DialogsManager():
    m_NextPressed( false ),
    m_NextRepeated( false ),
    m_UpPressed( false ),
    m_DownPressed( false ),

    m_LimitArea( NULL )
{
    LOG_TRIVIAL( "DialogsManager created." );
}



DialogsManager::~DialogsManager()
{
    for( unsigned int i = 0; i < m_Messages.size(); ++i )
    {
        delete m_Messages[ i ];
    }

    LOG_TRIVIAL( "DialogsManager destroyed." );
}



void
DialogsManager::Initialise()
{
    UiWidget* g_widget = UiManager::getSingletonPtr()->GetWidget( "Dialog" );
    if( g_widget == NULL )
    {
        LOG_ERROR( "Can't create DialogsManager because Widget \"Dialog\" not founded." );
        return;
    }
    m_LimitArea = g_widget->GetChild( "LimitArea" );
    if( m_LimitArea == NULL )
    {
        LOG_ERROR( "Can't create DialogsManager because Widget \"LimitArea\" not founded in Widget \"Dialog\"." );
        return;
    }

    unsigned int num = m_LimitArea->GetNumberOfChildren();

    for( unsigned int i = 0; i < num; ++i )
    {
        UiWidget* widget = m_LimitArea->GetChild( i );
        UiTextArea* text_area = (UiTextArea*) widget->GetChild( "TextArea" );
        if( text_area == NULL )
        {
            LOG_ERROR( "Can't create dialog \"" +widget->GetName() + "\" because because text_area with name \"TextArea\" missing." );
            continue;
        }

        MessageData* data = new MessageData();
        data->widget = widget;
        data->window = widget->GetChild( "Window" );
        data->text_area = text_area;
        data->text_area->SetTextPrintSpeed( 256 );
        data->text_area->SetTextScrollTime( 0.267f );
        data->cursor = widget->GetChild( "Cursor" );
        if( data->cursor != NULL )
        {
            data->cursor->GetY( data->cursor_percent_y, data->cursor_y );
        }
        m_Messages.push_back( data );
    }

    LOG_TRIVIAL( "DialogsManager initialized." );
}



void
DialogsManager::Input( const QGears::Event& input )
{
    if ((input.type == QGears::ET_KEY_PRESS) && (input.event == "message_ok"))
    {
        m_NextPressed = true;
    }
    else if ((input.type == QGears::ET_KEY_REPEAT) && (input.event == "message_ok"))
    {
        m_NextRepeated = true;
    }
    else if ((input.type == QGears::ET_KEY_PRESS) && (input.event == "message_up"))
    {
        m_UpPressed = true;
    }
    else if ((input.type == QGears::ET_KEY_PRESS) && (input.event == "message_down"))
    {
        m_DownPressed = true;
    }
}



void
DialogsManager::Update()
{
    for( unsigned int i = 0; i < m_Messages.size(); ++i )
    {
        switch( m_Messages[ i ]->state )
        {
            case MS_SHOW_WINDOW:
            {
                if( ( m_Messages[ i ]->window == NULL ) || (m_Messages[ i ]->window->GetCurrentAnimationName() == Ogre::StringUtil::BLANK ) )
                {
                    m_Messages[ i ]->text_area->PlayAnimation( "Show", UiAnimation::ONCE, 0, -1 );
                    m_Messages[ i ]->text_area->SetVisible( true );
                    m_Messages[ i ]->state = MS_SHOW_TEXT;
                }
            }
            break;

            case MS_SHOW_TEXT:
            {
                if( AutoCloseCheck( i ) == true )
                {
                    break;
                }

                if( m_Messages[ i ]->clickable == true )
                {
                    if( m_NextPressed == true )
                    {
                        m_Messages[ i ]->text_area->InputPressed();
                    }
                    if( m_NextRepeated == true )
                    {
                        m_Messages[ i ]->text_area->InputRepeated();
                    }
                }

                if( m_Messages[ i ]->text_area->GetTextState() == TS_DONE )
                {
                    m_Messages[ i ]->state = MS_OPENED;

                    if( ( m_Messages[ i ]->cursor != NULL ) && ( m_Messages[ i ]->show_cursor == true ) )
                    {
                        m_Messages[ i ]->cursor->SetY( m_Messages[ i ]->cursor_percent_y, m_Messages[ i ]->cursor_y + m_Messages[ i ]->cursor_row_current * m_Messages[ i ]->text_area->GetFont()->GetHeight() );
                        m_Messages[ i ]->cursor->SetVisible( true );
                    }
                }
            }
            break;

            case MS_OPENED:
            {
                if( m_Messages[ i ]->clickable == true && m_NextPressed == true )
                {
                    m_Messages[ i ]->auto_close = true;

                    if( ( m_Messages[ i ]->cursor != NULL ) && ( m_Messages[ i ]->show_cursor == true ) )
                    {
                        m_Messages[ i ]->show_cursor = false;
                        m_Messages[ i ]->cursor_row_selected = m_Messages[ i ]->cursor_row_current;
                        m_Messages[ i ]->cursor->SetVisible( false );
                    }
                }

                if( AutoCloseCheck( i ) == true )
                {
                    break;
                }

                if( ( m_Messages[ i ]->cursor != NULL ) && ( m_Messages[ i ]->show_cursor == true ) && ( m_Messages[ i ]->clickable == true ) )
                {
                    if( m_UpPressed == true )
                    {
                        m_Messages[ i ]->cursor_row_current -= 1;
                    }
                    else if( m_DownPressed == true )
                    {
                        m_Messages[ i ]->cursor_row_current += 1;
                    }

                    m_Messages[ i ]->cursor_row_current = ( m_Messages[ i ]->cursor_row_current < m_Messages[ i ]->cursor_row_first ) ? m_Messages[ i ]->cursor_row_last : m_Messages[ i ]->cursor_row_current;
                    m_Messages[ i ]->cursor_row_current = ( m_Messages[ i ]->cursor_row_current > m_Messages[ i ]->cursor_row_last ) ? m_Messages[ i ]->cursor_row_first : m_Messages[ i ]->cursor_row_current;

                    m_Messages[ i ]->cursor->SetY( m_Messages[ i ]->cursor_percent_y, m_Messages[ i ]->cursor_y + m_Messages[ i ]->cursor_row_current * m_Messages[ i ]->text_area->GetFont()->GetHeight() );
                }
            }
            break;

            case MS_HIDE_WINDOW:
            {
                if( ( m_Messages[ i ]->window == NULL ) || (m_Messages[ i ]->window->GetCurrentAnimationName() == Ogre::StringUtil::BLANK ) )
                {
                    HideMessage( i );
                }
            }
            break;
        }
    }



    if( cv_debug_message.GetB() == true )
    {
        DEBUG_DRAW.SetColour( Ogre::ColourValue::White );
        DEBUG_DRAW.SetTextAlignment( DEBUG_DRAW.LEFT );
        DEBUG_DRAW.SetScreenSpace( true );
        int y = 34;

        for( unsigned int i = 0; i < m_Messages.size(); ++i )
        {
            Ogre::String caption;
            caption += "Message " + Ogre::StringConverter::toString( i ) + ": " + message_state_string[ m_Messages[ i ]->state ];

            if( m_Messages[ i ]->state == MS_SHOW_TEXT )
            {
                caption += " (" + Ogre::StringConverter::toString( int( m_Messages[ i ]->text_area->GetTextLimit() ) ) + "/" + Ogre::StringConverter::toString( m_Messages[ i ]->text_area->GetTextSize() );

                switch( m_Messages[ i ]->text_area->GetTextState() )
                {
                    case TS_PAUSE_OK: caption += " pause ok"; break;
                    case TS_PAUSE_TIME: caption += " pause time " + Ogre::StringConverter::toString( int( m_Messages[ i ]->text_area->GetPauseTime() ) ); break;
                    case TS_OVERFLOW: caption += " overflow"; break;
                    case TS_NEXT_PAGE: caption += " next page"; break;
                    case TS_SCROLL_TEXT: caption += " scroll"; break;
                }

                caption += ")";
            }

            DEBUG_DRAW.Text( 10, y, caption );
            y += 16;
        }
    }



    m_NextPressed = false;
    m_NextRepeated = false;
    m_UpPressed = false;
    m_DownPressed = false;
}



void
DialogsManager::Clear()
{
    for( unsigned int i = 0; i < m_Messages.size(); ++i )
    {
        HideMessage( i );
    }
}



void
DialogsManager::ShowDialog( const char* d_name, const char* name, const int x, const int y )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] show_dialog: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return;
    }

    if( m_Messages[ id ]->state != MS_CLOSED )
    {
        LOG_TRIVIAL( "[SCRIPT] show_dialog: dialog \"" + Ogre::String( d_name ) + " already shown. Close it first." );
        return;
    }

    float width, height;
    TiXmlNode* text = TextManager::getSingleton().GetDialog( name, width, height );
    if( text != NULL )
    {
        m_Messages[ id ]->text_area->SetText( text );
        ShowMessage( id, x, y, width, height );
    }
    else
    {
        LOG_TRIVIAL( "[SCRIPT] show_dialog: dialog text \"" + Ogre::String( name ) + "\" doesn't exist." );
    }
}



void
DialogsManager::ShowText( const char* d_name, const char* text, const int x, const int y, const int width, const int height )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] show_text: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return;
    }

    if( m_Messages[ id ]->state != MS_CLOSED )
    {
        LOG_TRIVIAL( "[SCRIPT] show_dialog: dialog \"" + Ogre::String( d_name ) + " already shown. Close it first." );
        return;
    }

    m_Messages[ id ]->text_area->SetText( text );
    ShowMessage( id, x, y, width, height );
}



int
DialogsManager::Sync( const char* d_name )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] sync: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return 1;
    }

    ScriptId script = ScriptManager::getSingleton().GetCurrentScriptId();
    m_Messages[ id ]->sync.push_back( script );
    return -1;
}



void
DialogsManager::SetVariable( const char* d_name, const char* name, const char* value )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] set_variable: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return;
    }

    m_Messages[ id ]->text_area->SetVariable( name, value );
}



void
DialogsManager::Hide( const char* d_name )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] hide: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return;
    }

    if( m_Messages[ id ]->state == MS_CLOSED )
    {
        LOG_TRIVIAL( "[SCRIPT ERROR] hide: dialog \"" + Ogre::String( d_name ) + "\" already closed. Open it first." );
        return;
    }

    m_Messages[ id ]->auto_close = true;
}



void
DialogsManager::SetClickable( const char* d_name, const bool clickable )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] set_clickable: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return;
    }

    m_Messages[ id ]->clickable = clickable;
}



void
DialogsManager::SetCursor( const char* d_name, const int first_row, const int last_row )
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] set_cursor: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return;
    }

    if( m_Messages[ id ]->state != MS_CLOSED )
    {
        LOG_TRIVIAL( "[SCRIPT] set_cursor: dialog \"" + Ogre::String( d_name ) + "\" already shown. Close it first." );
        return;
    }

    m_Messages[ id ]->show_cursor = true;
    m_Messages[ id ]->cursor_row_current = first_row;
    m_Messages[ id ]->cursor_row_first = first_row;
    m_Messages[ id ]->cursor_row_last = last_row;
}



int
DialogsManager::GetCursor( const char* d_name ) const
{
    int id = GetMessageId( d_name );
    if( id == -1 )
    {
        LOG_TRIVIAL( "[SCRIPT] get_cursor: dialog \"" + Ogre::String( d_name ) + "\" doesn't exist." );
        return 0;
    }

    return m_Messages[ id ]->cursor_row_selected;
}



void
DialogsManager::ShowMessage( const int id, const int x, const int y, const int width, const int height )
{
    // handle error when dialog wingow cross border of limit area
    float la_percent_width, la_width;
    m_LimitArea->GetWidth( la_percent_width, la_width );
    float move_back_x = 0;
    if( x + width > la_width )
    {
        move_back_x = x + width - la_width;
    }
    float la_percent_height, la_height;
    m_LimitArea->GetWidth( la_percent_height, la_height );
    float move_back_y = 0;
    if( y + height > la_height )
    {
        move_back_y = y + height - la_height;
    }

    m_Messages[ id ]->widget->SetX( 0, x - move_back_x );
    m_Messages[ id ]->widget->SetY( 0, y - move_back_y );
    m_Messages[ id ]->widget->SetWidth( 0, width );
    m_Messages[ id ]->widget->SetHeight( 0, height );
    m_Messages[ id ]->widget->SetVisible( true );

    m_Messages[ id ]->auto_close = false;

    if( ( m_Messages[ id ]->window != NULL ) && ( m_Messages[ id ]->show_window == true ) )
    {
        m_Messages[ id ]->window->SetVisible( true );
        m_Messages[ id ]->window->PlayAnimation( "Show", UiAnimation::ONCE, 0, -1 );
    }

    m_Messages[ id ]->state = MS_SHOW_WINDOW;
}



void
DialogsManager::HideMessage( const int id )
{
    m_Messages[ id ]->auto_close = false;
    m_Messages[ id ]->state = MS_CLOSED;

    if( m_Messages[ id ]->window != NULL )
    {
        m_Messages[ id ]->window->SetVisible( false );
    }
    if( m_Messages[ id ]->cursor != NULL )
    {
        m_Messages[ id ]->cursor->SetVisible( false );
    }
    m_Messages[ id ]->text_area->SetVisible( false );
    m_Messages[ id ]->widget->SetVisible( false );

    for( unsigned int i = 0; i < m_Messages[ id ]->sync.size(); ++i )
    {
        ScriptManager::getSingleton().ContinueScriptExecution( m_Messages[ id ]->sync[ i ] );
    }
    m_Messages[ id ]->sync.clear();
}



int
DialogsManager::GetMessageId( const char* d_name ) const
{
    for( unsigned int i = 0; i < m_Messages.size(); ++i )
    {
        if( m_Messages[ i ]->widget->GetName() == Ogre::String( d_name ) )
        {
            return i;
        }
    }

    return -1;
}



bool
DialogsManager::AutoCloseCheck( const unsigned int id )
{
    if( m_Messages[ id ]->auto_close == true )
    {
        m_Messages[ id ]->text_area->PlayAnimation( "Hide", UiAnimation::ONCE, 0, -1 );
        if( m_Messages[ id ]->window != NULL )
        {
            m_Messages[ id ]->window->PlayAnimation( "Hide", UiAnimation::ONCE, 0, -1 );
        }
        m_Messages[ id ]->state = MS_HIDE_WINDOW;
        return true;
    }

    return false;
}
