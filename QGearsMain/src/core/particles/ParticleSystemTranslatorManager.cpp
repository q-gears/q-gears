#include "core/particles/ParticleSystemTranslatorManager.h"

#include <OgreLogManager.h>

//------------------------------------------------------------------------------
size_t
ParticleSystemTranslatorManager::getNumTranslators() const
{
    return 1;
}

//------------------------------------------------------------------------------
Ogre::ScriptTranslator*
ParticleSystemTranslatorManager::getTranslator(const Ogre::AbstractNodePtr &node)
{
    Ogre::ScriptTranslator* translator = NULL;
    if (node->type == Ogre::ANT_OBJECT)
    {
        Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());

        if (obj->cls == "effect")
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("Found object 'effect'.");
            translator = &m_ParticleSystemTranslator;
        }
        else if (obj->cls == "group")
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("Found object 'technique'.");
            translator = &m_TechniqueTranslator;
        }
        else if (obj->cls == "renderer")
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("Found object 'renderer'.");
            translator = &m_RendererTranslator;
        }
        else if (obj->cls == "emitter")
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("Found object 'emitter'.");
            translator = &m_EmitterTranslator;
        }
    }

    return translator;
}

//------------------------------------------------------------------------------
