// $Id$

#ifndef XML_ENEMY_FILE_h
#define XML_ENEMY_FILE_h

#include "BattleDataStructures.h"
#include "../core/XmlFile.h"



class XmlEnemyFile : public XmlFile
{
public:
    explicit           XmlEnemyFile(const Ogre::String& file);
    virtual           ~XmlEnemyFile();

    void               Load(const int enemy_id, FighterData& data, Ogre::String& model, Ogre::String& script);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_ENEMY_FILE_h
