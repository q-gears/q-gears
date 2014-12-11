#ifndef PARTICLE_SYSTEM_TRANSLATOR_MANAGER_H
#define PARTICLE_SYSTEM_TRANSLATOR_MANAGER_H

#include <OgreScriptTranslator.h>
#include <OgreSingleton.h>

#include "ParticleEmitterTranslator.h"
#include "ParticleRendererTranslator.h"
#include "ParticleSystemTranslator.h"
#include "ParticleTechniqueTranslator.h"



class ParticleSystemTranslatorManager : public Ogre::ScriptTranslatorManager
{
public:
    size_t getNumTranslators() const;

    Ogre::ScriptTranslator *getTranslator(const Ogre::AbstractNodePtr &node);

private:
    ParticleEmitterTranslator   m_EmitterTranslator;
    ParticleRendererTranslator  m_RendererTranslator;
    ParticleSystemTranslator    m_ParticleSystemTranslator;
    ParticleTechniqueTranslator m_TechniqueTranslator;
};




#endif // PARTICLE_SYSTEM_TRANSLATOR_MANAGER_H
