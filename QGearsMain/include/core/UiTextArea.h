#ifndef UI_TEXT_AREA_H
#define UI_TEXT_AREA_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreUTFString.h>
#include <tinyxml/tinyxml.h>

#include "UiFont.h"
#include "UiSprite.h"
#include "UiWidget.h"


struct TextStyle
{
    Ogre::ColourValue colour;
};



struct TextBlockData
{
    float local_x1;
    float local_y1;
    int position;
};

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

    enum TextAlign
    {
        LEFT,
        RIGHT,
        CENTER
    };

    void InputPressed();
    void InputRepeated();
    void SetTextAlign( const TextAlign align );
    void SetText( const Ogre::UTFString& text );
    void SetText( TiXmlNode* text );
    void SetTextPrintSpeed(const float speed);
    void SetTextScrollTime(const float time);
    void SetFont( const Ogre::String& font );
    const UiFont* GetFont() const;
    void UpdateGeometry();
    float GetTextLengthFromNode( TiXmlNode* node ) const;
    float GetTextLength( const Ogre::UTFString& text ) const;
    float GetTextWidth() const;
    void SetTextGeometryFromNode( TiXmlNode* node, TextBlockData& data, const TextStyle& style );
    void SetTextGeometry( const Ogre::UTFString& text, TextBlockData& data, const TextStyle& style );
    void SetVariable( const Ogre::String& name, const Ogre::UTFString& value );
    Ogre::UTFString GetVariable( const Ogre::String& name ) const;
    TextState GetTextState() const;
    float GetTextLimit() const;
    unsigned int GetTextSize() const;
    float GetPauseTime() const;

private:
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
    Ogre::UTFString                     m_Text;
    TiXmlNode*                          m_TextNode;

    //std::vector< TextChar >             m_Text;
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

inline
void WriteTriangleVertex(float *&writeIterator, const Ogre::Vector3 &coord,
                const Ogre::ColourValue &colour, const float u, const float v)
{
    *writeIterator++ = coord.x;
    *writeIterator++ = coord.y;
    *writeIterator++ = coord.z;
    *writeIterator++ = colour.r;
    *writeIterator++ = colour.g;
    *writeIterator++ = colour.b;
    *writeIterator++ = colour.a;
    *writeIterator++ = u;
    *writeIterator++ = v;
}

inline void
WriteGlyph(float *&writeIterator, const Ogre::Vector3 coords[],
           const Ogre::ColourValue &colour, const Ogre::FloatRect &texture)
{
    // draw two triangles with a colour and texture.
    WriteTriangleVertex(writeIterator, coords[0], colour, texture.left, texture.top);
    WriteTriangleVertex(writeIterator, coords[1], colour, texture.right, texture.top);
    WriteTriangleVertex(writeIterator, coords[2], colour, texture.right, texture.bottom);
    // Triangle two
    WriteTriangleVertex(writeIterator, coords[0], colour, texture.left, texture.top);
    WriteTriangleVertex(writeIterator, coords[2], colour, texture.right, texture.bottom);
    WriteTriangleVertex(writeIterator, coords[3], colour, texture.left, texture.bottom);
}

#endif // UI_TEXT_AREA_H
