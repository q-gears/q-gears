#ifndef PARTICLE_TECHNIQUE_H
#define PARTICLE_TECHNIQUE_H

#include "ParticleEmitter.h"
#include "ParticleRenderer.h"
#include "ParticlePool.h"
#include "ParticlePoolMap.h"



class ParticleSystem;



class ParticleTechnique
{
public:
    ParticleTechnique();
    virtual ~ParticleTechnique();

    void CopyAttributesTo(ParticleTechnique* technique);

    void SetParentSystem(ParticleSystem* parentSystem) {m_ParentSystem = parentSystem;};
    ParticleSystem* GetParentSystem() const {return m_ParentSystem;};

    // this fucntion called from ParticleSystem which implements _updateRenderQueue from movable objects
    void UpdateRenderQueue(Ogre::RenderQueue* queue);

    void Initialize();
    void Update(Ogre::Real time_elapsed);

    ParticleRenderer* CreateRenderer(const Ogre::String& renderer_type);
    void SetRenderer(ParticleRenderer* renderer);
    void DestroyRenderer();

    ParticleEmitter* CreateEmitter(const Ogre::String& emitter_type);
    void AddEmitter(ParticleEmitter* emitter);
    void DestroyAllEmitters();
    int GetNumEmittableEmitters() const;

    void EmissionChange();

    int GetVisualParticlesQuota() const {return m_VisualParticleQuota;};
    void ExecuteEmitParticles(ParticleEmitter* emitter, int requested, Ogre::Real time_elapsed);
    void ResetVisualParticles();

private:
    ParticleSystem*                     m_ParentSystem;

    ParticleRenderer*                   m_Renderer;

    int                                 m_VisualParticleQuota;
    bool                                m_VisualParticlePoolIncreased;
    ParticlePool<VisualParticle>        m_VisualParticlesPool;
    std::vector<VisualParticle*>        m_VisualParticles;

    int                                 m_EmittedEmitterQuota;
    bool                                m_ParticleEmitterPoolIncreased;
    ParticlePoolMap<ParticleEmitter>    m_ParticleEmitterPool;
    std::vector<ParticleEmitter*>       m_Emitters;
};



#endif // PARTICLE_TECHNIQUE_H
