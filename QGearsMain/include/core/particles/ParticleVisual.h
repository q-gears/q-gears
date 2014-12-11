#ifndef VISUAL_PARTICLE_H
#define VISUAL_PARTICLE_H

#include "Particle.h"



class VisualParticle : public Particle
{
public:
    VisualParticle();
    virtual ~VisualParticle() {};

    virtual void InitForExpiration();
};



#endif // VISUAL_PARTICLE_H
