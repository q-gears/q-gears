#include "ParticleSystemTranslator.h"

#include <OgreLogManager.h>

#include "ParticleSystemManager.h"



void
ParticleSystemTranslator::translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node)
{
    Ogre::ObjectAbstractNode *obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());

    // name can't be empty because we add particle system by it
    if(obj->name.empty())
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTNAMEEXPECTED, obj->file, obj->line);
        return;
    }

    ParticleSystem* system = ParticleSystemManager::getSingleton().CreateParticleSystemTemplate(obj->name);

    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleSystemTranslator: create template for particle system '" + obj->name + "'");

    if (!system)
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTALLOCATIONERROR, obj->file, obj->line);
        return;
    }

    obj->context = Ogre::Any(system);

    for (Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
    {
        if ((*i)->type != Ogre::ANT_PROPERTY)
        {
            processNode(compiler, *i);
        }
    }
}
