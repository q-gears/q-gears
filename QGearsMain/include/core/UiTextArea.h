#ifndef UI_TEXT_AREA_H
#define UI_TEXT_AREA_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreUTFString.h>
#include <tinyxml/tinyxml.h>

#include "UiFont.h"
#include "UiWidget.h"

class UiSprite;

enum TextState
{
    TS_SHOW_TEXT,
    TS_SCROLL_TEXT,
    TS_PAUSE_OK,
    TS_PAUSE_TIME,
    TS_DONE,
    TS_OVERFLOW,
    TS_NEXT_PAGE,
};



struct TextChar
{
    TextChar():
        char_code( 0 ),
        colour( Ogre::ColourValue::White ),
        skip( false ),
        variable( "" ),
        variable_len( 0 ),
        pause_ok( false ),
        pause_time( 0.0f ),
        next_page( false ),
        sprite( NULL ),
        sprite_y( 0 )
    {
    }

    int char_code;
    Ogre::ColourValue colour;
    bool skip;
    Ogre::String variable;
    unsigned int variable_len;
    bool pause_ok;
    float pause_time;
    bool next_page;
    UiSprite* sprite;
    float sprite_y;
};



struct TextVariable
{
    Ogre::String name;
    Ogre::UTFString value;
};



class UiTextArea : public UiWidget
{
public:
    UiTextArea( const Ogre::String& name );
    UiTextArea( const Ogre::String& name, const Ogre::String& path_name, UiWidget* parent );
    virtual ~UiTextArea();

    void Initialise();
    virtual void Update();
    virtual void Render();
    virtual void UpdateTransformation();

    void UpdateGeometry();

    void InputPressed();
    void InputRepeated();

    enum TextAlign
    {
        LEFT,
        RIGHT,
        CENTER
    };
    void SetTextAlign( const TextAlign align );
    void SetPadding( const float top, const float right, const float bottom, const float left );
    void SetText( const Ogre::UTFString& text );
    void SetText( TiXmlNode* text );
    void TextClear();
    void RemoveSpritesFromText( const unsigned int end );
    void SetFont( const Ogre::String& font );
    const UiFont* GetFont() const;
    void SetTextPrintSpeed( const float speed );
    void SetTextScrollTime( const float time );
    void SetVariable( const Ogre::String& name, const Ogre::UTFString& value );
    Ogre::UTFString GetVariable( const Ogre::String& name ) const;
    TextState GetTextState() const;
    float GetTextLimit() const;
    unsigned int GetTextSize() const;
    float GetPauseTime() const;

private:
    float GetTextWidth() const;
    void PrepareTextFromNode( TiXmlNode* node, const Ogre::ColourValue& colour );
    void PrepareTextFromText( const Ogre::UTFString& text, const Ogre::ColourValue& colour );

    UiTextArea();
    void CreateVertexBuffer();
    void DestroyVertexBuffer();

private:
    Ogre::MaterialPtr                   m_Material;
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    unsigned int                        m_MaxLetters;
    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;

    UiFont*                             m_Font;
    TextAlign                           m_TextAlign;

    std::vector< TextChar >             m_Text;
    float                               m_TextLimit;
    float                               m_TextPrintSpeed;
    float                               m_TextPrintSpeedMod;
    TextState                           m_TextState;
    std::vector< TextVariable >         m_TextVariable;

    float                               m_TextScrollTime;
    float                               m_TextYOffset;
    float                               m_TextYOffsetTarget;
    float                               m_PauseTime;
    unsigned int                        m_NextPageStart;

    bool                                m_NextPressed;
    bool                                m_NextRepeated;

    float                               m_PaddingTop;
    float                               m_PaddingRight;
    float                               m_PaddingBottom;
    float                               m_PaddingLeft;

    bool                                m_Timer;
    int                                 m_TimerTime;
};

#endif // UI_TEXT_AREA_H
