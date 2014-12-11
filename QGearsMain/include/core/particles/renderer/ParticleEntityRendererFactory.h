#ifndef PARTICLE_ENTITY_RENDERER_FACTORY_H
#define PARTICLE_ENTITY_RENDERER_FACTORY_H

#include "../ParticleRendererFactory.h"
#include "ParticleEntityRenderer.h"



class ParticleEntityRendererFactory : public ParticleRendererFactory
{
public:
    ParticleEntityRendererFactory() {};
    virtual ~ParticleEntityRendererFactory() {};

    Ogre::String GetRendererType() const
    {
        return "Entity";
    }

    ParticleRenderer* CreateRenderer()
    {
        return _createRenderer<ParticleEntityRenderer>();
    }
};



#endif // PARTICLE_ENTITY_RENDERER_FACTORY_H
