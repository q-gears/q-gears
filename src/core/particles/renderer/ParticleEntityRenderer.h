#ifndef PARTICLE_ENTITY_RENDERER_H
#define PARTICLE_ENTITY_RENDERER_H

#include <OgreSceneNode.h>

#include "ParticleEntityAdditionalData.h"
#include "ParticleEntityRendererDictionary.h"
#include "../ParticleRenderer.h"



class ParticleEntityRenderer : public ParticleRenderer
{
public:
    ParticleEntityRenderer();
    virtual ~ParticleEntityRenderer();

    virtual void CopyAttributesTo(ParticleRenderer* renderer);

    const Ogre::String& GetMeshName() const;
    void SetMeshName(const Ogre::String& mesh_name);

    void Clear();

    virtual void SetVisible(bool visible);
    virtual void Initialize();
    virtual void UpdateRenderQueue(Ogre::RenderQueue* queue, ParticlePool<VisualParticle>& pool);

protected:
    std::vector<ParticleEntityAdditionalData*>          m_AllAdditionalData;
    std::vector<ParticleEntityAdditionalData*>          m_UnassignedAdditionalData;
    std::vector<Ogre::Entity*>                          m_Entities;
    static ParticleEntityRendererDictionary::MeshName   m_MeshNameDictionary;
    Ogre::String                                        m_MeshName;
};



#endif // PARTICLE_ENTITY_RENDERER_H
