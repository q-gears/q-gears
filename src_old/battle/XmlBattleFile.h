// $Id$

#ifndef XML_BATTLE_FILE_h
#define XML_BATTLE_FILE_h

#include "../core/XmlFile.h"

class BattleModule;



class XmlBattleFile : public XmlFile
{
public:
    explicit XmlBattleFile(const Ogre::String& file);
    virtual ~XmlBattleFile();

    void     Load(const int battle_id, BattleModule* battle_module);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_BATTLE_FILE_h
