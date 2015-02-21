#ifndef UI_TEXT_AREA_H
#define UI_TEXT_AREA_H

#include <OgreHardwareVertexBuffer.h>
#include <OgreRenderQueueListener.h>
#include <OgreRoot.h>
#include <OgreUTFString.h>
#include <tinyxml/tinyxml.h>

#include "UiFont.h"
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
    float GetTextLengthFromNode( TiXmlNode* node ) const;
    float GetTextLength( const Ogre::UTFString& text ) const;
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

    unsigned int                        m_MaxLetters;
    Ogre::RenderOperation               m_RenderOp;
    Ogre::HardwareVertexBufferSharedPtr m_VertexBuffer;

    UiFont*                             m_Font;
    TextAlign                           m_TextAlign;
    Ogre::UTFString                     m_Text;
    TiXmlNode*                          m_TextNode;
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
