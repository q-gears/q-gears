#ifndef TEXT_AREA_h
#define TEXT_AREA_h

#include <OgreOverlayContainer.h>
#include <OgreFont.h>

#include "../library/tinyxml/tinyxml.h"



struct TextStyle
{
    Ogre::ColourValue colour;
};



struct TextBlockData
{
    float left;
    float top;
    int position;
};



class TextArea : public Ogre::OverlayContainer
{
public:
    enum TextHorizontalAlignment
    {
        THA_LEFT,
        THA_CENTER
    };

public:
                                TextArea(const Ogre::String& name);
    virtual                    ~TextArea();

    virtual void                initialise();

    virtual void                setCaption(const Ogre::DisplayString& text){};
    void                        SetCaption(const Ogre::DisplayString& text);

    void                        SetUseXML(const bool use);

    void                        setCharHeight(Ogre::Real height);
    Ogre::Real                  getCharHeight() const;

    void                        setSpaceWidth(Ogre::Real width);
    Ogre::Real                  getSpaceWidth() const;

    void                        setFontName(const Ogre::String& font);
    const Ogre::String&         getFontName() const;

    void                        SetTextAlignment(const TextHorizontalAlignment& alignment);

    // See OverlayElement.
    virtual const Ogre::String& getTypeName() const;
    // See Renderable.
    void                        getRenderOperation(Ogre::RenderOperation& op);
    // Overridden from OverlayElement
    void                        setMaterialName(const Ogre::String& matName);
    // Overridden from OverlayElement
    void                        setMetricsMode(Ogre::GuiMetricsMode gmm);
    // Overridden from OverlayElement
    void                        _update();

    // Get real string size (without special symbols like colours)
    int                         GetCaptionSize() const;

private:
    // Internal method to allocate memory, only reallocates when necessary
    void                        CheckMemoryAllocation(const int number_of_chars);

    // Inherited function
    virtual void                updatePositionGeometry();
    void                        SetTextGeometryFromNode(TiXmlNode* node, TextBlockData& data, const TextStyle& style);
    void                        SetTextGeometry(const Ogre::DisplayString& caption, TextBlockData& data, const TextStyle& style);

    // Inherited function
    virtual void                updateTextureGeometry();

protected:
    static Ogre::String     m_TypeName;

    Ogre::RenderOperation   m_RenderOp;
    size_t                  m_AllocSize;
    bool                    m_OutOfDate;

    bool                    m_UseXML;
    Ogre::FontPtr           m_Font;
    TextHorizontalAlignment m_TextHorizontalAlignment;
    Ogre::DisplayString     m_Caption;



    float        mCharHeight;
    Ogre::ushort mPixelCharHeight;
    float        mSpaceWidth;
    Ogre::ushort mPixelSpaceWidth;
    float        mViewportAspectCoef;
};



#endif // TEXT_AREA_h
