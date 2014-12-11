#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include <OgreStringInterface.h>

#include "Particle.h"
#include "ParticleEmitterDictionary.h"



class ParticleTechnique;



class ParticleEmitter : public Ogre::StringInterface, public Particle
{
public:
    ParticleEmitter();
    virtual ~ParticleEmitter();

    virtual void CopyAttributesTo(ParticleEmitter* emitter);

    virtual void InitForEmission();

    virtual int CalculateRequestedParticles(Ogre::Real time_elapsed);
    virtual void InitParticleForEmission(Particle* particle);

    void SetParentTechnique(ParticleTechnique* tech) {m_ParentTechnique = tech;};
    ParticleTechnique* GetParentTechnique() const {return m_ParentTechnique;};

    void SetName(const Ogre::String& name) {m_Name = name;};
    const Ogre::String& GetName() const {return m_Name;};

    void SetEmitterType(const Ogre::String& emitter_type) {m_EmitterType = emitter_type;};
    const Ogre::String& GetEmitterType() const {return m_EmitterType;};

    void SetEmitsName(const Ogre::String& emitsName);
    const Ogre::String& GetEmitsName() const {return m_EmitsName;};

    void SetEmitsType(ParticleType emits_type) {m_EmitsType = emits_type;};
    ParticleType GetEmitsType() const {return m_EmitsType;};

    void SetEmissionRate(int rate) {m_EmissionRate = rate;};
    int GetEmissionRate() const {return m_EmissionRate;};



    // EMIT PARTICLE SETTINGS
    void SetEmitDirection(const Ogre::Vector3& dir) {m_EmitDirection1 = dir; m_EmitDirection2 = dir;};
    void SetEmitDirectionRange(const Ogre::Vector3& dir1, const Ogre::Vector3& dir2) {m_EmitDirection1 = dir1; m_EmitDirection2 = dir2;};
    void SetEmitTotalTimeToLive(float time) {m_EmitTotalTimeToLive = time;};

protected:
    ParticleTechnique*                                  m_ParentTechnique;

    Ogre::String                                        m_Name;
    Ogre::String                                        m_EmitterType;

    Ogre::String                                        m_EmitsName;
    ParticleType                                        m_EmitsType;
    static ParticleEmitterDictionary::EmissionRate      m_EmissionRateDictionary;
    int                                                 m_EmissionRate;
    Ogre::Real                                          m_EmissionRemainder;

    static ParticleEmitterDictionary::Direction         m_DirectionDictionary;
    Ogre::Vector3                                       m_EmitDirection1;
    Ogre::Vector3                                       m_EmitDirection2;
    static ParticleEmitterDictionary::TotalTimeToLive   m_TotalTimeToLiveDictionary;
    float                                               m_EmitTotalTimeToLive;
};



#endif // PARTICLE_EMITTER_H
