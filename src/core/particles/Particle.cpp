#include "Particle.h"



Particle::Particle(): 
    m_ParentEmitter(NULL),
    m_ParticleType(PT_VISUAL),
    m_Enabled(true),
    m_Emittable(false),

    additional_data(NULL),
    position(Ogre::Vector3::ZERO),
    direction(Ogre::Vector3::ZERO),
    time_to_live(10),
    total_time_to_live(10)
{
};



Particle::~Particle()
{
};



void
Particle::Update(Ogre::Real time_elapsed)
{
    position += direction * time_elapsed;
}



void
Particle::CopyAttributesTo(Particle* particle)
{
    // do not copy m_ParentEmitter and m_ParticleType
    // this can be emited from other emitter and have different type
    particle->m_Enabled = m_Enabled;
    particle->SetEmittable(m_Emittable);

    particle->position = position;
    particle->direction = direction;
    particle->time_to_live = time_to_live;
    particle->total_time_to_live = total_time_to_live;
}
