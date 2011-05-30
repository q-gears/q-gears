#ifndef PARTICLE_EMITTER_FACTORY_H
#define PARTICLE_EMITTER_FACTORY_H

#include "ParticleEmitter.h"



class ParticleEmitterFactory
{
public:
    ParticleEmitterFactory(){};
    virtual ~ParticleEmitterFactory(){};

    virtual Ogre::String GetEmitterType() const = 0;

    virtual ParticleEmitter* CreateEmitter() = 0;

    void DestroyEmitter(ParticleEmitter* emitter)
    {
        if (emitter != NULL)
        {
            delete emitter;
        }
    };

protected:
    template <class T>
    ParticleEmitter* _createEmitter()
    {
        ParticleEmitter* particle_emitter = new T();
        particle_emitter->SetEmitterType(GetEmitterType());
        return particle_emitter;
    };
};



#endif // PARTICLE_EMITTER_FACTORY_H
