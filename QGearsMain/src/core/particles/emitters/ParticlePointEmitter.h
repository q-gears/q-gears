#ifndef PARTICLE_POINT_EMITTER_H
#define PARTICLE_POINT_EMITTER_H

#include "../ParticleEmitter.h"



class PointEmitter : public ParticleEmitter
{
public:
    PointEmitter();
    virtual ~PointEmitter() {};

    virtual void CopyAttributesTo(ParticleEmitter* emitter);
};



#endif // PARTICLE_POINT_EMITTER_H
