// $Id$

#ifndef XML_PLAYER_FILE_h
#define XML_PLAYER_FILE_h

#include "BattleDataStructures.h"
#include "../core/XmlFile.h"



class XmlPlayerFile : public XmlFile
{
public:
    explicit           XmlPlayerFile(const Ogre::String& file);
    virtual           ~XmlPlayerFile();

    void               Load(const int player_id, FighterData& data, Ogre::String& model, Ogre::String& script);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_PLAYER_FILE_h
