#ifndef UI_TEXT_AREA_H
#define UI_TEXT_AREA_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreUTFString.h>

#include "UiFont.h"
#include "UiWidget.h"
#include "library/tinyxml/tinyxml.h"



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
    void SetTextAlign( const TextAlign align );
    void SetText( const Ogre::UTFString& text );
    void SetText( TiXmlNode* text );
    void SetFont( const Ogre::String& font );
    void UpdateGeometry();
    const float GetTextLengthFromNode( TiXmlNode* node ) const;
    const float GetTextLength( const Ogre::UTFString& text ) const;
    void SetTextGeometryFromNode( TiXmlNode* node, TextBlockData& data, const TextStyle& style );
    void SetTextGeometry( const Ogre::UTFString& text, TextBlockData& data, const TextStyle& style );

private:
    UiTextArea();
    void CreateVertexBuffer();
    void DestroyVertexBuffer();

private:
    Ogre::MaterialPtr                   m_Material;
    Ogre::SceneManager*                 m_SceneManager;
    Ogre::RenderSystem*                 m_RenderSystem;

    int                                 m_MaxLetters;
    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;

    UiFont*                             m_Font;
    TextAlign                           m_TextAlign;
    Ogre::UTFString                     m_Text;
    TiXmlNode*                          m_TextNode;
};



#endif // UI_TEXT_AREA_H
