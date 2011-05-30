#include "ParticleEmitterTranslator.h"

#include <OgreLogManager.h>

#include "ParticleSystemManager.h"



void
ParticleEmitterTranslator::translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node)
{
    Ogre::ObjectAbstractNode *obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());

    // name can't be empty because we get renderer type from it
    if(obj->name.empty())
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTNAMEEXPECTED, obj->file, obj->line);
        return;
    }

    ParticleTechnique* tech = Ogre::any_cast<ParticleTechnique*>(obj->parent->context);

    ParticleEmitter* emitter = tech->CreateEmitter(obj->name);
    if (emitter == NULL)
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTALLOCATIONERROR, obj->file, obj->line);
        return;
    }
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleEmitterTranslator: create emitter.");

    for (Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
    {
        if ((*i)->type == Ogre::ANT_PROPERTY)
        {
            Ogre::PropertyAbstractNode *prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
            Ogre::String value = prop->getValue();
/*
            // Glob the values together
            for (Ogre::AbstractNodeList::iterator i = prop->values.begin(); i != prop->values.end(); ++i)
            {
                if((*i)->type == Ogre::ANT_ATOM)
                {
                    if (value.empty())
                    {
                        value = ((Ogre::AtomAbstractNode*)(*i).get())->value;
                    }
                    else
                    {
                        value = value + " " + ((Ogre::AtomAbstractNode*)(*i).get())->value;
                    }
                }
                else
                {
                    compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line);
                    break;
                }
            }
*/
            Ogre::LogManager::getSingletonPtr()->logMessage("ParticleEmitterTranslator: Set param '" + prop->name + "' to '" + value + "'.");
            if (!emitter->setParameter(prop->name, value))
            {
                compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line);
            }
        }
    }
}
