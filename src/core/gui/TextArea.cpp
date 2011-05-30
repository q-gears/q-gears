#include "TextArea.h"

#include <OgreException.h>
#include <OgreFont.h>
#include <OgreFontManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreHardwareVertexBuffer.h>
#include <OgreOverlayManager.h>
#include <OgreRoot.h>
#include <OgreStringConverter.h>

#include "../Logger.h"



#define DEFAULT_INITIAL_CHARS 32

#define POS_TEX_BINDING 0
#define COLOUR_BINDING 1

#define UNICODE_NEL 0x0085
#define UNICODE_CR 0x000D
#define UNICODE_LF 0x000A
#define UNICODE_SPACE 0x0020
#define UNICODE_ZERO 0x0030

Ogre::String TextArea::m_TypeName = "QGearsTextArea";



TextArea::TextArea(const Ogre::String& name):
    Ogre::OverlayContainer(name),
    m_AllocSize(0),
    m_OutOfDate(false),
    m_UseXML(false),
    m_TextHorizontalAlignment(THA_LEFT)
{
    mCharHeight = 0.02;
    mPixelCharHeight = 12;
    mSpaceWidth = 0;
    mPixelSpaceWidth = 0;
    mViewportAspectCoef = 1;
}



TextArea::~TextArea()
{
    delete m_RenderOp.vertexData;
}



void
TextArea::initialise(void)
{
    if (!mInitialised)
    {
        // Set up the render op
        // Combine positions and texture coords since they tend to change together
        // since character sizes are different
        m_RenderOp.vertexData = new Ogre::VertexData();
        Ogre::VertexDeclaration* decl = m_RenderOp.vertexData->vertexDeclaration;
        size_t offset = 0;
        // Positions
        decl->addElement(POS_TEX_BINDING, offset, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
        offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
        // Texcoords
        decl->addElement(POS_TEX_BINDING, offset, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES, 0);
        offset += Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT2);
        // Colours - store these in a separate buffer because they change less often
        decl->addElement(COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);

        m_RenderOp.operationType = Ogre::RenderOperation::OT_TRIANGLE_LIST;
        m_RenderOp.useIndexes = false;
        m_RenderOp.vertexData->vertexStart = 0;

        // Vertex buffer will be created in checkMemoryAllocation
        CheckMemoryAllocation(DEFAULT_INITIAL_CHARS);

        mInitialised = true;
    }

}

void
TextArea::CheckMemoryAllocation(const int number_of_chars)
{
    if (m_AllocSize < number_of_chars)
    {
        // Create and bind new buffers
        // Note that old buffers will be deleted automatically through reference counting

        // 6 verts per char since we're doing tri lists without indexes
        // Allocate space for positions & texture coords
        Ogre::VertexDeclaration* decl = m_RenderOp.vertexData->vertexDeclaration;
        Ogre::VertexBufferBinding* bind = m_RenderOp.vertexData->vertexBufferBinding;

        m_RenderOp.vertexData->vertexCount = number_of_chars * 6;



        Ogre::HardwareVertexBufferSharedPtr vbuf;

        // Create dynamic since text tends to change alot
        // positions & texcoords
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
                    decl->getVertexSize(POS_TEX_BINDING),
                    m_RenderOp.vertexData->vertexCount,
                    Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY);
        bind->setBinding(POS_TEX_BINDING, vbuf);

        // colours
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
                    decl->getVertexSize(COLOUR_BINDING),
                    m_RenderOp.vertexData->vertexCount,
                    Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY);
        bind->setBinding(COLOUR_BINDING, vbuf);

        m_AllocSize = number_of_chars;
    }
}



int
TextArea::GetCaptionSize() const
{
    return m_Caption.size();
}




void
TextArea::SetCaption(const Ogre::DisplayString& caption)
{
    if (m_UseXML == true)
    {
        m_Caption = "<c>" + caption + "</c>";
    }
    else
    {
        m_Caption = caption;
    }
    m_OutOfDate = true;
}



void
TextArea::SetUseXML(const bool use)
{
    m_UseXML = use;
}



void
TextArea::setFontName(const Ogre::String& font)
{
    m_Font = Ogre::FontManager::getSingleton().getByName(font);
    if (m_Font.isNull())
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_ITEM_NOT_FOUND, "Could not find font " + font, "TextArea::setFontName");
    }

    m_Font->load();
    mpMaterial = m_Font->getMaterial();
    mpMaterial->setDepthCheckEnabled(false);
    mpMaterial->setLightingEnabled(false);

    m_OutOfDate = true;
}



const Ogre::String&
TextArea::getFontName() const
{
    return m_Font->getName();
}



void
TextArea::SetTextAlignment(const TextHorizontalAlignment& alignment)
{
    m_TextHorizontalAlignment = alignment;
}



void
TextArea::setCharHeight(Ogre::Real height)
{
    if (mMetricsMode != Ogre::GMM_RELATIVE)
    {
        mPixelCharHeight = static_cast<unsigned short>(height);
    }
    else
    {
        mCharHeight = height;
    }

    m_OutOfDate = true;
}



Ogre::Real
TextArea::getCharHeight() const
{
    if (mMetricsMode == Ogre::GMM_PIXELS)
    {
        return mPixelCharHeight;
    }
    else
    {
        return mCharHeight;
    }
}



void
TextArea::setSpaceWidth(Ogre::Real width)
{
    if (mMetricsMode != Ogre::GMM_RELATIVE)
    {
        mPixelSpaceWidth = static_cast<unsigned>(width);
    }
    else
    {
        mSpaceWidth = width;
    }

    m_OutOfDate = true;
}



Ogre::Real
TextArea::getSpaceWidth() const
{
    if (mMetricsMode == Ogre::GMM_PIXELS)
    {
        return mPixelSpaceWidth;
    }
    else
    {
        return mSpaceWidth;
    }
}



const Ogre::String&
TextArea::getTypeName() const
{
    return m_TypeName;
}



void
TextArea::getRenderOperation(Ogre::RenderOperation& op)
{
    op = m_RenderOp;
}



void
TextArea::setMaterialName(const Ogre::String& matName)
{
    Ogre::OverlayElement::setMaterialName(matName);
}



void
TextArea::setMetricsMode(Ogre::GuiMetricsMode gmm)
{
    Ogre::Real vpWidth, vpHeight;
    vpWidth = (Ogre::Real) (Ogre::OverlayManager::getSingleton().getViewportWidth());
    vpHeight = (Ogre::Real) (Ogre::OverlayManager::getSingleton().getViewportHeight());

    mViewportAspectCoef = vpHeight/vpWidth;

    Ogre::OverlayElement::setMetricsMode(gmm);

    mMetricsMode = gmm;

    switch (mMetricsMode)
    {
        case Ogre::GMM_PIXELS:
        {
            // set pixel variables based on viewport multipliers
            mPixelCharHeight = static_cast<unsigned short>(mCharHeight * vpHeight);
            mPixelSpaceWidth = static_cast<unsigned short>(mSpaceWidth * vpHeight);
        }
        break;

        case Ogre::GMM_RELATIVE_ASPECT_ADJUSTED:
        {
            // set pixel variables multiplied by the height constant
            mPixelCharHeight = static_cast<unsigned short>(mCharHeight * 10000.0);
            mPixelSpaceWidth = static_cast<unsigned short>(mSpaceWidth * 10000.0);
        }
        break;
    }

    m_OutOfDate = true;
}



void
TextArea::_update(void)
{
    Ogre::Real vpWidth, vpHeight;
    vpWidth = (Ogre::Real) (Ogre::OverlayManager::getSingleton().getViewportWidth());
    vpHeight = (Ogre::Real) (Ogre::OverlayManager::getSingleton().getViewportHeight());

    mViewportAspectCoef = vpHeight/vpWidth;

    // Check size if pixel-based / relative-aspect-adjusted
    switch (mMetricsMode)
    {
        case Ogre::GMM_PIXELS:
        {
            if (Ogre::OverlayManager::getSingleton().hasViewportChanged() || m_OutOfDate == true)
            {
                // recalculate character size
                mCharHeight = (Ogre::Real) mPixelCharHeight / vpHeight;
                mSpaceWidth = (Ogre::Real) mPixelSpaceWidth / vpHeight;
                m_OutOfDate = true;
            }
        }
        break;

        case Ogre::GMM_RELATIVE_ASPECT_ADJUSTED:
        {
            if (Ogre::OverlayManager::getSingleton().hasViewportChanged() || m_OutOfDate == true)
            {
                // recalculate character size
                mCharHeight = (Ogre::Real) mPixelCharHeight / 10000.0;
                mSpaceWidth = (Ogre::Real) mPixelSpaceWidth / 10000.0;
                m_OutOfDate = true;
            }
        }
        break;
    }

    Ogre::OverlayElement::_update();

    if (m_OutOfDate == true)
    {
        updatePositionGeometry();
        m_OutOfDate = false;
    }
}



void
TextArea::updatePositionGeometry()
{
    if (m_Font.isNull())
    {
        // not initialised yet, probably due to the order of creation in a template
        return;
    }


    // allocate needed buffers
    int charlen = GetCaptionSize();
    CheckMemoryAllocation(charlen);



    TextBlockData data;
    data.left = _getDerivedLeft() * 2.0 - 1.0;
    data.top = -((_getDerivedTop() * 2.0 ) - 1.0);
    data.position = 0;

    TextStyle style;
    style.colour = Ogre::ColourValue::White;



    if (m_UseXML == true)
    {
        TiXmlDocument doc;
        doc.SetCondenseWhiteSpace(false);
        doc.Parse(m_Caption.asUTF8_c_str(), NULL, TIXML_ENCODING_UTF8);
        TiXmlNode* node = doc.RootElement()->FirstChild();

        SetTextGeometryFromNode(node, data, style);
    }
    else
    {
         SetTextGeometry(m_Caption, data, style);
    }

    m_RenderOp.vertexData->vertexCount = data.position * 6;
}



void
TextArea::SetTextGeometryFromNode(TiXmlNode* node, TextBlockData& data, const TextStyle& style)
{
    while (node != NULL)
    {
        switch(node->Type())
        {
            case TiXmlNode::TINYXML_TEXT:
            {
                Ogre::DisplayString text = node->ValueStr();
                SetTextGeometry(text, data, style);
            }
            break;

            case TiXmlNode::TINYXML_ELEMENT:
            {
                TextStyle style_child;
                style_child.colour = style.colour;

                std::string name = node->ValueStr();
                if (name == "colour")
                {
                    style_child.colour = Ogre::StringConverter::parseColourValue(node->ToElement()->Attribute("value"));
                }

                TiXmlNode* node_child = node->FirstChild();
                SetTextGeometryFromNode(node_child, data, style_child);
            }
            break;
        }

        node = node->NextSibling();
    }
}



void
TextArea::SetTextGeometry(const Ogre::DisplayString& caption, TextBlockData& data, const TextStyle& style)
{
    // set colour for text
    Ogre::RGBA current_colour;
    Ogre::Root::getSingleton().convertColourValue(style.colour, &current_colour);



    // Get position / texcoord buffer
    Ogre::HardwareVertexBufferSharedPtr vbuf = m_RenderOp.vertexData->vertexBufferBinding->getBuffer(POS_TEX_BINDING);
    float* pVert = static_cast<float*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    pVert += data.position * 30;
    // Get color buffer
    Ogre::HardwareVertexBufferSharedPtr cbuf = m_RenderOp.vertexData->vertexBufferBinding->getBuffer(COLOUR_BINDING);
    Ogre::RGBA* pDest = static_cast<Ogre::RGBA*>(cbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));
    pDest += data.position * 6;

    float largestWidth = 0;

    // Derive space with from a number 0
    if (mSpaceWidth == 0)
    {
        mSpaceWidth = m_Font->getGlyphAspectRatio(UNICODE_ZERO) * mCharHeight * 2.0 * mViewportAspectCoef;
    }



    // Use iterator
    int i, iend;
    iend = caption.size();
    bool newLine = true;
    float len = 0.0f;

    for (i = 0; i < iend; ++i)
    {
        if (newLine)
        {
            len = 0.0f;
            for (int j = i; j < iend && (caption[j] != UNICODE_CR && caption[j] != UNICODE_NEL && caption[j] != UNICODE_LF); ++j)
            {
                if (caption[j] == UNICODE_SPACE)
                {
                    len += mSpaceWidth;
                }
                else
                {
                    len += m_Font->getGlyphAspectRatio(caption[j]) * mCharHeight;
                }
            }

            newLine = false;
        }

        Ogre::Font::CodePoint character = caption[i];
        if (character == UNICODE_CR || character == UNICODE_NEL || character == UNICODE_LF)
        {
            data.left = _getDerivedLeft() * 2.0 - 1.0;
            data.top -= mCharHeight * 2.0;
            // Also reduce tri count
            m_RenderOp.vertexData->vertexCount -= 6;
            newLine = true;

            // consume CR/LF in one
            if (character == UNICODE_CR)
            {
                int peeki = i;
                ++peeki;
                if (peeki < iend && caption[peeki] == UNICODE_LF)
                {
                    i = peeki; // skip both as one newline
                    // Also reduce tri count
                    m_RenderOp.vertexData->vertexCount -= 6;
                }
            }

            continue;
        }
        else if (character == UNICODE_SPACE) // space
        {
            // Just leave a gap, no tris
            data.left += mSpaceWidth;
            // Also reduce tri count
            m_RenderOp.vertexData->vertexCount -= 6;
            continue;
        }



        Ogre::Real horiz_height = m_Font->getGlyphAspectRatio(character) * mViewportAspectCoef;
        const Ogre::Font::UVRect& uvRect = m_Font->getGlyphTexCoords(character);

        // each vert is (x, y, z, u, v)
        //-------------------------------------------------------------------------------------
        // First tri
        //
        // Upper left
        if (m_TextHorizontalAlignment == TextArea::THA_LEFT)
        {
            *pVert++ = data.left;
        }
        else
        {
            *pVert++ = data.left - (len / 2);
        }
        *pVert++ = data.top;
        *pVert++ = -1.0;
        *pVert++ = uvRect.left;
        *pVert++ = uvRect.top;

        data.top -= mCharHeight * 2.0;

        // Bottom left
        if (m_TextHorizontalAlignment == TextArea::THA_LEFT)
        {
            *pVert++ = data.left;
        }
        else
        {
            *pVert++ = data.left - (len / 2);
        }
        *pVert++ = data.top;
        *pVert++ = -1.0;
        *pVert++ = uvRect.left;
        *pVert++ = uvRect.bottom;

        data.top += mCharHeight * 2.0;
        data.left += horiz_height * mCharHeight * 2.0;

        // Top right
        if (m_TextHorizontalAlignment == TextArea::THA_LEFT)
        {
            *pVert++ = data.left;
        }
        else
        {
            *pVert++ = data.left - (len / 2);
        }
        *pVert++ = data.top;
        *pVert++ = -1.0;
        *pVert++ = uvRect.right;
        *pVert++ = uvRect.top;
        //-------------------------------------------------------------------------------------

        //-------------------------------------------------------------------------------------
        // Second tri
        //
        // Top right (again)
        if (m_TextHorizontalAlignment == TextArea::THA_LEFT)
        {
            *pVert++ = data.left;
        }
        else
        {
            *pVert++ = data.left - (len / 2);
        }
        *pVert++ = data.top;
        *pVert++ = -1.0;
        *pVert++ = uvRect.right;
        *pVert++ = uvRect.top;

        data.top -= mCharHeight * 2.0;
        data.left -= horiz_height  * mCharHeight * 2.0;

        // Bottom left (again)
        if (m_TextHorizontalAlignment == TextArea::THA_LEFT)
        {
            *pVert++ = data.left;
        }
        else
        {
            *pVert++ = data.left - (len / 2);
        }
        *pVert++ = data.top;
        *pVert++ = -1.0;
        *pVert++ = uvRect.left;
        *pVert++ = uvRect.bottom;

        data.left += horiz_height  * mCharHeight * 2.0;

        // Bottom right
        if (m_TextHorizontalAlignment == TextArea::THA_LEFT)
        {
            *pVert++ = data.left;
        }
        else
        {
            *pVert++ = data.left - (len / 2);
        }
        *pVert++ = data.top;
        *pVert++ = -1.0;
        *pVert++ = uvRect.right;
        *pVert++ = uvRect.bottom;
        //-------------------------------------------------------------------------------------


        // colour
        // First tri (top, bottom, top)
        *pDest++ = current_colour;
        *pDest++ = current_colour;
        *pDest++ = current_colour;
        // Second tri (top, bottom, bottom)
        *pDest++ = current_colour;
        *pDest++ = current_colour;
        *pDest++ = current_colour;


        // Go back up with top
        data.top += mCharHeight * 2.0;

        data.position += 1;

        float currentWidth = (data.left + 1)/2 - _getDerivedLeft();
        if (currentWidth > largestWidth)
        {
            largestWidth = currentWidth;

        }
    }

    // Unlock vertex buffer and color buffer
    vbuf->unlock();
    cbuf->unlock();

    if (mMetricsMode == Ogre::GMM_PIXELS)
    {
        // Derive parametric version of dimensions
        Ogre::Real vpWidth;
        vpWidth = (Ogre::Real) (Ogre::OverlayManager::getSingleton().getViewportWidth());

        largestWidth *= vpWidth;
    };
}



void
TextArea::updateTextureGeometry()
{
    // Nothing to do, we combine positions and textures
}
