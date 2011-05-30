// $Id$

#ifndef XML_ATTACK_FILE_h
#define XML_ATTACK_FILE_h

#include "BattleDataStructures.h"
#include "../core/XmlFile.h"

class BattleModule;



class XmlAttackFile : public XmlFile
{
public:
    explicit           XmlAttackFile(const Ogre::String& file);
    virtual           ~XmlAttackFile();

    void               Load(BattleModule* battle_module);

private:
    bool       m_NormalFile;
    xmlNodePtr m_RootNode;
};



#endif // XML_ATTACK_FILE_h
