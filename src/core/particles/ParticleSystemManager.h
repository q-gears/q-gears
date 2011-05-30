#ifndef PARTICLE_SYSTEM_MANAGER_H
#define PARTICLE_SYSTEM_MANAGER_H

#include <OgreSingleton.h>

#include "ParticleEmitter.h"
#include "ParticleEmitterFactory.h"
#include "ParticleRendererFactory.h"
#include "ParticleSystem.h"
#include "ParticleSystemFactory.h"
#include "ParticleTechnique.h"
#include "ParticleSystemTranslatorManager.h"



class ParticleSystemManager: public Ogre::Singleton<ParticleSystemManager>
{
public:
    ParticleSystemManager();
    ~ParticleSystemManager();

    // ParticleSystemTemplate
    ParticleSystem* CreateParticleSystemTemplate(const Ogre::String& name);
    ParticleSystem* GetParticleSystemTemplate(const Ogre::String& templateName);
    void ParticleSystemTemplateNames(std::vector<Ogre::String>& v);

    // ParticleSystem
    ParticleSystem* CreateParticleSystem(const Ogre::String& name, const Ogre::String& template_name);
    void DestroyParticleSystem(ParticleSystem* particle_system);

    // ParticleTechnique.
    ParticleTechnique* CreateTechnique();
    ParticleTechnique* CloneTechnique(ParticleTechnique* technique);
    void DestroyTechnique(ParticleTechnique* technique);

    // ParticleEmitter
    ParticleEmitter* CreateEmitter(const Ogre::String& emitter_type);
    ParticleEmitter* CloneEmitter(ParticleEmitter* emitter);
    void DestroyEmitter(ParticleEmitter* emitter);

    // ParticleRenderer
    ParticleRenderer* CreateRenderer(const Ogre::String& renderer_type);
    ParticleRenderer* CloneRenderer(ParticleRenderer* renderer);
    void DestroyRenderer(ParticleRenderer* renderer);

private:
    // factories
    void AddEmitterFactory(ParticleEmitterFactory* factory);
    void AddRendererFactory(ParticleRendererFactory* factory);


private:
    ParticleSystemFactory*           m_ParticleSystemFactory;

    ParticleSystemTranslatorManager* m_TranslatorManager;

    // ParticleSystemTemplate
    typedef std::map<Ogre::String, ParticleSystem*> ParticleSystemTemplateMap;
    ParticleSystemTemplateMap m_ParticleSystemTemplates;

    // Emitter Factories
    typedef std::map<Ogre::String, ParticleEmitterFactory*> EmitterFactoryMap;
    EmitterFactoryMap m_EmitterFactories;

    // Renderer Factories
    typedef std::map<Ogre::String, ParticleRendererFactory*> RendererFactoryMap;
    RendererFactoryMap m_RendererFactories;
};



#endif // PARTICLE_SYSTEM_MANAGER_H
