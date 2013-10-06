#include "core/particles/ParticleTechniqueTranslator.h"

#include <OgreLogManager.h>

#include "core/particles/ParticleSystemManager.h"

//------------------------------------------------------------------------------
void
ParticleTechniqueTranslator::translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node)
{
    Ogre::ObjectAbstractNode *obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());

    // Create the technique from the material
    ParticleSystem* system = Ogre::any_cast<ParticleSystem*>(obj->parent->context);

    ParticleTechnique* tech = system->CreateTechnique();
    if (!tech)
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTALLOCATIONERROR, obj->file, obj->line);
        return;
    }
    obj->context = Ogre::Any(tech);
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechniqueTranslator: create tech");

    for (Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
    {
        if ((*i)->type == Ogre::ANT_OBJECT)
        {
            processNode(compiler, *i);
        }
    }
}

//------------------------------------------------------------------------------
