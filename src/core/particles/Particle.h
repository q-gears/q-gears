#ifndef PARTICLE_H
#define PARTICLE_H

#include <OgrePrerequisites.h>
#include <OgreVector3.h>

#include "ParticleAdditionalData.h"



class ParticleEmitter;



class Particle
{
public:
    enum ParticleType
    {
        PT_VISUAL,
        PT_EMITTER
    };

    Particle();
    virtual ~Particle() = 0;

    virtual void InitForEmission() {};
    virtual void InitForExpiration() {};

    virtual void Update(Ogre::Real time_elapsed);

    virtual void CopyAttributesTo(Particle* particle);

    ParticleType GetParticleType() const {return m_ParticleType;};

    void SetParentEmitter(ParticleEmitter* parent_emitter) {m_ParentEmitter = parent_emitter;};
    ParticleEmitter* GetParentEmitter() const {return m_ParentEmitter;};

    void SetEnabled(bool enabled) {m_Enabled = enabled;};
    bool IsEnabled() const {return m_Enabled;};

    void SetEmittable(bool emittable) {m_Emittable = emittable;};
    bool IsEmittable() const {return m_Emittable;};

    ParticleAdditionalData* additional_data;
    Ogre::Vector3           position;
    Ogre::Vector3           direction;
    float                   time_to_live;
    float                   total_time_to_live;

protected:
    ParticleEmitter*    m_ParentEmitter;
    ParticleType        m_ParticleType;
    bool                m_Enabled;
    bool                m_Emittable;
};



#endif // PARTICLE_H
