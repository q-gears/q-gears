#include "ParticleRendererTranslator.h"

#include <OgreLogManager.h>

#include "ParticleSystemManager.h"



void
ParticleRendererTranslator::translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node)
{
    Ogre::ObjectAbstractNode *obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());

    // name can't be empty because we get renderer type from it
    if(obj->name.empty())
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTNAMEEXPECTED, obj->file, obj->line);
        return;
    }

    ParticleTechnique* tech = Ogre::any_cast<ParticleTechnique*>(obj->parent->context);

    ParticleRenderer* rend = tech->CreateRenderer(obj->name);
    if (rend == NULL)
    {
        compiler->addError(Ogre::ScriptCompiler::CE_OBJECTALLOCATIONERROR, obj->file, obj->line);
        return;
    }
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleRendererTranslator: create renderer");

    for (Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
    {
        if ((*i)->type == Ogre::ANT_PROPERTY)
        {
            Ogre::PropertyAbstractNode *prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
            Ogre::String value;

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

            Ogre::LogManager::getSingletonPtr()->logMessage("ParticleRendererTranslator: Set param '" + prop->name + "' to '" + value + "'.");
            if (!rend->setParameter(prop->name, value))
            {
                compiler->addError(Ogre::ScriptCompiler::CE_INVALIDPARAMETERS, prop->file, prop->line);
            }
        }
    }
}
