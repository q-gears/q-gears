#ifndef PARTICLE_RENDERER_FACTORY_H
#define PARTICLE_RENDERER_FACTORY_H

#include "ParticleRenderer.h"



class ParticleRendererFactory
{
public:
    ParticleRendererFactory(){};
    virtual ~ParticleRendererFactory(){};

    virtual Ogre::String GetRendererType() const = 0;

    virtual ParticleRenderer* CreateRenderer() = 0;

    void DestroyRenderer (ParticleRenderer* renderer)
    {
        if (renderer != NULL)
        {
            delete renderer;
        }
    };

protected:
    template <class T>
    ParticleRenderer* _createRenderer()
    {
        ParticleRenderer* particle_renderer = new T();
        particle_renderer->SetRendererType(GetRendererType());
        return particle_renderer;
    };
};



#endif // PARTICLE_RENDERER_FACTORY_H
