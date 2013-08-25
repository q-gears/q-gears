#ifndef PARTICLE_RENDERER_H
#define PARTICLE_RENDERER_H

#include <OgreString.h>
#include <OgreStringInterface.h>

#include "ParticlePool.h"

class ParticleTechnique;
class VisualParticle;



class ParticleRenderer : public Ogre::StringInterface
{
public:
    ParticleRenderer();
    virtual ~ParticleRenderer();

    virtual void CopyAttributesTo(ParticleRenderer* renderer);

    void SetRendererInitialised(bool renderer_initialised);
    bool IsRendererInitialised() const;

    void SetRendererType(Ogre::String renderer_type);
    const Ogre::String& GetRendererType() const;

    void SetParentTechnique(ParticleTechnique* parent_technique);
    const ParticleTechnique* GetParentTechnique() const;

    virtual void SetVisible(bool visible = true) = 0;
    virtual void Initialize() = 0;
    virtual void UpdateRenderQueue(Ogre::RenderQueue* queue, ParticlePool<VisualParticle>& pool) = 0;

protected:
    bool                m_RendererInitialised;
    Ogre::String        m_RendererType;
    ParticleTechnique*  m_ParentTechnique;
};



#endif // PARTICLE_RENDERER_H
