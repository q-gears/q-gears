#ifndef PARTICLE_POINT_EMITTER_FACTORY_H
#define PARTICLE_POINT_EMITTER_FACTORY_H

#include "../ParticleEmitterFactory.h"
#include "ParticlePointEmitter.h"



class PointEmitterFactory : public ParticleEmitterFactory
{
public:
    PointEmitterFactory(){};
    virtual ~PointEmitterFactory(){};

    Ogre::String GetEmitterType() const
    {
        return "Point";
    }

    ParticleEmitter* CreateEmitter()
    {
        return _createEmitter<PointEmitter>();
    }
};



#endif // PARTICLE_POINT_EMITTER_FACTORY_H
