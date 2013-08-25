#include "ParticleTechnique.h"

#include <OgreLogManager.h>
#include <OgreStringConverter.h>

#include "ParticleSystemManager.h"
#include "ParticleVisual.h"



ParticleTechnique::ParticleTechnique():
    m_Renderer(NULL),

    m_VisualParticleQuota(10),
    m_VisualParticlePoolIncreased(false),

    m_EmittedEmitterQuota(10),
    m_ParticleEmitterPoolIncreased(false)
{
}



ParticleTechnique::~ParticleTechnique()
{
    DestroyAllEmitters();
    DestroyRenderer();
}



void
ParticleTechnique::CopyAttributesTo(ParticleTechnique* technique)
{
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo start");
    // Destroy the emitters, affectors, etc.
    technique->DestroyAllEmitters();
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo 1");
    technique->DestroyRenderer();

    technique->m_ParentSystem = m_ParentSystem;
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo 2");
    // Copy the renderer
    ParticleRenderer* cloned_renderer = ParticleSystemManager::getSingletonPtr()->CloneRenderer(m_Renderer);
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo 3");
    technique->SetRenderer(cloned_renderer);

    technique->m_VisualParticleQuota = m_VisualParticleQuota;
    technique->m_VisualParticlePoolIncreased = false;
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo 4");
    technique->m_EmittedEmitterQuota = m_EmittedEmitterQuota;
    technique->m_ParticleEmitterPoolIncreased = false;
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo 5");
    // Copy all emitters
    ParticleEmitter* cloned_emitter;
    for( unsigned int i = 0; i < m_Emitters.size(); ++i )
    {
        cloned_emitter = ParticleSystemManager::getSingletonPtr()->CloneEmitter( m_Emitters[ i ] );
        technique->AddEmitter( cloned_emitter );
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::CopyAttributesTo end");
}



void
ParticleTechnique::UpdateRenderQueue(Ogre::RenderQueue* queue)
{
    if (m_Renderer && m_Renderer->IsRendererInitialised())
    {
        m_Renderer->UpdateRenderQueue(queue, m_VisualParticlesPool);
    }
}



void
ParticleTechnique::Initialize()
{
    if (m_Renderer && m_Renderer->IsRendererInitialised() == false)
    {
        m_Renderer->Initialize();
    }



    // Create new visual particles if the quota has been increased
    if (m_VisualParticlePoolIncreased == false)
    {
        int old_size = m_VisualParticlesPool.GetSize();
        if (m_VisualParticleQuota > old_size)
        {
            // Create new visual particles
            VisualParticle* particle = NULL;
            for (int i = old_size; i < m_VisualParticleQuota; ++i)
            {
                particle = new VisualParticle();
                m_VisualParticlesPool.AddElement(particle);
                m_VisualParticles.push_back(particle);
            }
        }

        m_VisualParticlePoolIncreased = true;
    }



    // Create new emitter particles if the quota has been increased
    if (m_ParticleEmitterPoolIncreased == false)
    {
        int old_size = m_ParticleEmitterPool.GetSize();
        if (m_EmittedEmitterQuota > old_size)
        {
            // Create new emitters, based on the already created emitters in the technique and which are marked for emission.
            int numberOfEmittedEmitters = GetNumEmittableEmitters();
            if (numberOfEmittedEmitters == 0)
            {
                return;
            }

            ParticleEmitter* existing_emitter = 0;
            ParticleEmitter* cloned_emitter = 0;

            // Distribute size equally
            int increment = m_EmittedEmitterQuota / numberOfEmittedEmitters;

            // Run through emitters of the technique
            for( unsigned int i = 0; i < m_Emitters.size(); ++i )
            {
                if( m_Emitters[ i ]->IsEmittable() )
                {
                    // Clone the emitter 'increment' times and add to the pool
                    for (int j = 0; j < increment; ++j)
                    {
                        cloned_emitter = ParticleSystemManager::getSingletonPtr()->CloneEmitter(m_Emitters[i]);
                        cloned_emitter->SetEmittable(true);
                        m_ParticleEmitterPool.AddElement(cloned_emitter->GetName(), cloned_emitter);
                    }
                }
            }
        }

        m_ParticleEmitterPoolIncreased = true;
    }
}



void
ParticleTechnique::Update(Ogre::Real time_elapsed)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update START");
    // Perform some initialisation type of activities (if needed). This must be done within the update-loop,
    // because settings could be changed (i.e. changing quota), which must trigger a re-initialisation.

    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update initialize start");
    Initialize();

    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update initialize end");

    // Process the emitters
    for( unsigned int i = 0; i < m_Emitters.size(); ++i )
    {
        // emitted particles handled in pool update
        if( m_Emitters[ i ]->IsEmittable() == false )
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update emit static emitters");
            ExecuteEmitParticles(m_Emitters[i], m_Emitters[i]->CalculateRequestedParticles(time_elapsed), time_elapsed);
        }
    }



    if (m_VisualParticlesPool.IsEmpty() == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update: visual particle started.");

        VisualParticle* particle = m_VisualParticlesPool.GetFirst();
        while (!m_VisualParticlesPool.End())
        {
            if (particle != NULL)
            {
                Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update found particle with ttl " + Ogre::StringConverter::toString(particle->time_to_live));
                if (particle->time_to_live > time_elapsed)
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update update visual start");
                    particle->Update(time_elapsed);
                    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update update visual end");
                }
                else
                {
                    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update expire visual start");
                    particle->InitForExpiration();
                    m_VisualParticlesPool.LockLatestElement();
                    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update expire visual end");
                }

                // Decrement time to live
                particle->time_to_live -= time_elapsed;
            }

            particle = m_VisualParticlesPool.GetNext();
        }

        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update: visual particle finished.");
    }



    // Process all particles
    if (m_ParticleEmitterPool.IsEmpty() == false)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update: emitter particle started.");

        ParticleEmitter* particle = m_ParticleEmitterPool.GetFirst();
        while (!m_ParticleEmitterPool.End())
        {
            if (particle)
            {
                if (particle->time_to_live > time_elapsed)
                {
                    particle->Update(time_elapsed);
                    ExecuteEmitParticles(particle, particle->CalculateRequestedParticles(time_elapsed), time_elapsed);
                }
                else
                {
                    particle->InitForExpiration();
                    m_ParticleEmitterPool.LockLatestElement();
                }

                // Decrement time to live
                particle->time_to_live -= time_elapsed;
            }

            particle = m_ParticleEmitterPool.GetNext();
        }

        Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update: emitter particle finished.");
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::Update END");
}



ParticleRenderer*
ParticleTechnique::CreateRenderer(const Ogre::String& renderer_type)
{
    if (m_Renderer)
    {
        DestroyRenderer();
    }

    if (renderer_type != Ogre::StringUtil::BLANK)
    {
        m_Renderer = ParticleSystemManager::getSingletonPtr()->CreateRenderer(renderer_type);
        m_Renderer->SetParentTechnique(this);
        m_Renderer->SetRendererInitialised(false);
    }

    return m_Renderer;
}



void
ParticleTechnique::SetRenderer(ParticleRenderer* renderer)
{
    if (m_Renderer)
    {
        DestroyRenderer();
    }

    m_Renderer = renderer;
    m_Renderer->SetParentTechnique(this);
    m_Renderer->SetRendererInitialised(false);
}



void
ParticleTechnique::DestroyRenderer()
{
    if (m_Renderer)
    {
        ParticleSystemManager::getSingletonPtr()->DestroyRenderer(m_Renderer);
        m_Renderer = NULL;
    }
}



ParticleEmitter*
ParticleTechnique::CreateEmitter(const Ogre::String& emitter_type)
{
    ParticleEmitter* emitter = NULL;

    if (emitter_type != Ogre::StringUtil::BLANK)
    {
        emitter = ParticleSystemManager::getSingletonPtr()->CreateEmitter(emitter_type);
        m_Emitters.push_back(emitter);
        emitter->SetParentTechnique(this);
        EmissionChange();
    }

    return emitter;
}



void
ParticleTechnique::AddEmitter(ParticleEmitter* emitter)
{
    if (emitter != NULL)
    {
        m_Emitters.push_back(emitter);
        emitter->SetParentTechnique(this);
        EmissionChange();
    }
}



void
ParticleTechnique::DestroyAllEmitters()
{
    for( unsigned int i = 0; i < m_Emitters.size(); ++i )
    {
        ParticleSystemManager::getSingletonPtr()->DestroyEmitter(m_Emitters[i]);
    }
    m_Emitters.clear();
}



int
ParticleTechnique::GetNumEmittableEmitters() const
{
    int count = 0;
    for( unsigned int i = 0; i < m_Emitters.size(); ++i )
    {
        if (m_Emitters[i]->IsEmittable())
        {
            count++;
        }
    }

    return count;
}



void
ParticleTechnique::EmissionChange()
{
    // Run through all emitters and set MarkedForEmission to false.
    for( unsigned int i = 0; i < m_Emitters.size(); ++i )
    {
        m_Emitters[i]->SetEmittable(false);
    }

    // Run through all emitters and determine which objects each one emits.
    for( unsigned int i = 0; i < m_Emitters.size(); ++i )
    {
        Ogre::String name = m_Emitters[i]->GetEmitsName();
        if (name != m_Emitters[i]->GetName())
        {
            // Search the emitter to be emitted
            for( unsigned int j = 0; j < m_Emitters.size(); ++j )
            {
                if (m_Emitters[j]->GetName() == name)
                {
                    m_Emitters[j]->SetEmittable(true);
                }
            }
        }
    }
}



void
ParticleTechnique::ExecuteEmitParticles(ParticleEmitter* emitter, int requested, Ogre::Real time_elapsed)
{
    // Only proceed if the emitter and technique are enabled
    if (emitter->IsEnabled() == false)
    {
        return;
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::ExecuteEmitParticles request " + Ogre::StringConverter::toString(requested) + " particles to emit.");

    for (int j = 0; j < requested; ++j)
    {
        // Create a new particle & init using emitter
        Particle* particle = NULL;
        switch (emitter->GetEmitsType())
        {
            case Particle::PT_VISUAL: particle = m_VisualParticlesPool.ReleaseElement(); break;
            case Particle::PT_EMITTER: particle = m_ParticleEmitterPool.ReleaseElement(emitter->GetEmitsName()); break;
        }

        // Return if there is no particle left anymore, or the name cannot be found
        if (particle == NULL)
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("ParticleTechnique::ExecuteEmitParticles request there is no particles left.");
            return;
        }

        particle->InitForEmission();

        // Initialise the particle with data from the emitter.
        emitter->InitParticleForEmission(particle);
    }
}



void
ParticleTechnique::ResetVisualParticles()
{
    for( unsigned int i = 0; i < m_VisualParticles.size(); ++i )
    {
        m_VisualParticles[i]->additional_data = NULL;
    }
    m_VisualParticlesPool.LockAllElements();
}
