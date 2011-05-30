// $Id$

#ifndef TEXT_MANAGER_h
#define TEXT_MANAGER_h

#include <OgreString.h>
#include <OgreUTFString.h>
#include <map>

struct TextData
{
    TextData():
        text(""),
        width(0),
        height(0)
    {
    }

    Ogre::String        name;
    Ogre::UTFString     text;
    int                 width;
    int                 height;
};

typedef std::vector<TextData> TextDataVector;



class TextManager
{
public:
                          TextManager(void);
    virtual              ~TextManager(void);

    void                  SetLanguageRoot(const Ogre::String& root);

    void                  LoadTexts(const Ogre::String& file_name);
    void                  UnloadTexts(const Ogre::String& file_name);
    const TextData        GetText(const Ogre::String& name);

private:
    struct TextBlock
    {
        Ogre::String          block_name;
        std::vector<TextData> text;
    }

    Ogre::String            m_LanguageRoot;
    std::list<TextBlock>    m_Texts;
};



extern TextManager* g_TextManager;



#endif // TEXT_MANAGER_h
