#include "ParticleSystemManager.h"

#include <OgreLogManager.h>
#include <OgreRoot.h>

#include "ParticleSystemFactory.h"
#include "emitters/ParticlePointEmitterFactory.h"
#include "renderer/ParticleEntityRendererFactory.h"



template<> ParticleSystemManager* Ogre::Singleton<ParticleSystemManager>::ms_Singleton = 0;




ParticleSystemManager::ParticleSystemManager()
{
    m_TranslatorManager = new ParticleSystemTranslatorManager();
    Ogre::ScriptCompilerManager::getSingleton().addTranslatorManager(m_TranslatorManager);

    Ogre::ScriptCompilerManager::getSingleton().addScriptPattern("*.effects");

    m_ParticleSystemFactory = new ParticleSystemFactory();
    Ogre::Root::getSingleton().addMovableObjectFactory(m_ParticleSystemFactory);

    AddEmitterFactory(new PointEmitterFactory());

    AddRendererFactory(new ParticleEntityRendererFactory());
}



ParticleSystemManager::~ParticleSystemManager()
{
    Ogre::ScriptCompilerManager::getSingleton().removeTranslatorManager(m_TranslatorManager);
    delete m_TranslatorManager;

    if (m_ParticleSystemFactory)
    {
        Ogre::Root::getSingleton().removeMovableObjectFactory(m_ParticleSystemFactory);
        delete m_ParticleSystemFactory;
        m_ParticleSystemFactory = 0;
    }

    // Delete all Particle System Templates
    ParticleSystemTemplateMap::iterator t;
    for (t = m_ParticleSystemTemplates.begin(); t != m_ParticleSystemTemplates.end(); ++t)
    {
        delete t->second;
    }
    m_ParticleSystemTemplates.clear();



    EmitterFactoryMap::iterator efi;
    for (efi = m_EmitterFactories.begin(); efi != m_EmitterFactories.end(); ++efi)
    {
        delete efi->second;
    }



    RendererFactoryMap::iterator rfi;
    for (rfi = m_RendererFactories.begin(); rfi != m_RendererFactories.end(); ++rfi)
    {
        delete rfi->second;
    }
}



ParticleSystem*
ParticleSystemManager::CreateParticleSystemTemplate(const Ogre::String& name)
{
    // Validate name
    if (m_ParticleSystemTemplates.find(name) != m_ParticleSystemTemplates.end())
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_DUPLICATE_ITEM, "ParticleSystem template with name '" + name + "' already exists.", "ParticleSystemManager::CreateParticleSystemTemplate");
    }

    ParticleSystem* particle_system_template = new ParticleSystem(name);
    m_ParticleSystemTemplates[name] = particle_system_template;
    return particle_system_template;
}




ParticleSystem*
ParticleSystemManager::GetParticleSystemTemplate(const Ogre::String& template_name)
{
    ParticleSystemTemplateMap::iterator i = m_ParticleSystemTemplates.find(template_name);
    if (i != m_ParticleSystemTemplates.end())
    {
        return i->second;
    }

    return 0;
}



void
ParticleSystemManager::ParticleSystemTemplateNames(std::vector<Ogre::String>& v)
{
    ParticleSystemTemplateMap::iterator it;
    ParticleSystemTemplateMap::iterator it_end = m_ParticleSystemTemplates.end();
    for (it = m_ParticleSystemTemplates.begin(); it != it_end; ++it)
    {
        v.push_back((*it).first);
    }
}



ParticleSystem*
ParticleSystemManager::CreateParticleSystem(const Ogre::String& name, const Ogre::String& template_name)
{
    Ogre::NameValuePairList params;
    params["template_name"] = template_name;

    ParticleSystem* system = static_cast<ParticleSystem*>(Ogre::Root::getSingleton().getSceneManager("Scene")->createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, &params));
    return system;
}



void
ParticleSystemManager::DestroyParticleSystem(ParticleSystem* particle_system)
{
    Ogre::Root::getSingleton().getSceneManager("Scene")->destroyMovableObject(particle_system);
}



ParticleTechnique*
ParticleSystemManager::CreateTechnique()
{
    ParticleTechnique* technique = new ParticleTechnique();
    technique->CreateRenderer("Entity"); // Set default renderer
    return technique;
}



ParticleTechnique*
ParticleSystemManager::CloneTechnique(ParticleTechnique* technique)
{
    if (technique == NULL)
    {
        return NULL;
    }

    ParticleTechnique* cloned_technique = CreateTechnique();
    technique->CopyAttributesTo(cloned_technique);
    return cloned_technique;
}



void
ParticleSystemManager::DestroyTechnique(ParticleTechnique* technique)
{
    // Deletion must be done by the same object that also created it
    delete technique;
}



ParticleEmitter*
ParticleSystemManager::CreateEmitter(const Ogre::String& emitter_type)
{
    // Locate emitter type
    EmitterFactoryMap::iterator it = m_EmitterFactories.find(emitter_type);
    if (it == m_EmitterFactories.end())
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Particle System: Cannot find requested emitter type.", "ParticleSystemManager::CreateEmitter");
    }
    return it->second->CreateEmitter();
}



ParticleEmitter*
ParticleSystemManager::CloneEmitter(ParticleEmitter* emitter)
{
    if (!emitter)
    {
        return NULL;
    }

    ParticleEmitter* cloned_emitter = CreateEmitter(emitter->GetEmitterType());
    emitter->CopyAttributesTo(cloned_emitter);
    return cloned_emitter;
}



void
ParticleSystemManager::DestroyEmitter(ParticleEmitter* emitter)
{
    // Locate emitter type
    EmitterFactoryMap::iterator it = m_EmitterFactories.find(emitter->GetEmitterType());
    if (it == m_EmitterFactories.end())
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Particle System: Cannot find requested emitter type.", "ParticleSystemManager::DestroyEmitter");
    }
    it->second->DestroyEmitter(emitter);
}



ParticleRenderer*
ParticleSystemManager::CreateRenderer(const Ogre::String& renderer_type)
{
    // Locate renderer type
    RendererFactoryMap::iterator it = m_RendererFactories.find(renderer_type);

    if (it == m_RendererFactories.end())
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "PU: Cannot find requested renderer type.", "ParticleSystemManager::CreateRenderer");
    }

    return it->second->CreateRenderer();
}



ParticleRenderer*
ParticleSystemManager::CloneRenderer(ParticleRenderer* renderer)
{
    if (renderer == NULL)
    {
        return NULL;
    }

    ParticleRenderer* cloned_renderer = CreateRenderer(renderer->GetRendererType());
    renderer->CopyAttributesTo(cloned_renderer);
    return cloned_renderer;
}



void
ParticleSystemManager::DestroyRenderer(ParticleRenderer* renderer)
{
    // Locate renderer type
    RendererFactoryMap::iterator it = m_RendererFactories.find(renderer->GetRendererType());

    if (it == m_RendererFactories.end())
    {
        OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "PU: Cannot find requested renderer type.", "ParticleSystemManager::DestroyRenderer");
    }

    it->second->DestroyRenderer(renderer);
}



void
ParticleSystemManager::AddEmitterFactory(ParticleEmitterFactory* factory)
{
    Ogre::String type = factory->GetEmitterType();
    m_EmitterFactories[type] = factory;
    Ogre::LogManager::getSingleton().logMessage("ParticleUniverse: Particle Emitter Type '" + type + "' registered.");
}



void
ParticleSystemManager::AddRendererFactory(ParticleRendererFactory* factory)
{
    Ogre::String type = factory->GetRendererType();
    m_RendererFactories[type] = factory;
    Ogre::LogManager::getSingleton().logMessage("ParticleUniverse: Particle Renderer Type '" + type + "' registered");
}
