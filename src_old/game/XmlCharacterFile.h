// $Id$

#ifndef XML_CHARACTER_FILE_h
#define XML_CHARACTER_FILE_h

#include "GameState.h"
#include "../core/XmlFile.h"



class XmlCharacterFile : public XmlFile
{
public:
    explicit XmlCharacterFile(const Ogre::String& file);
    virtual ~XmlCharacterFile(void);

    void GetCharacters(std::vector<Character>& character_vector);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_CHARACTER_FILE_h
