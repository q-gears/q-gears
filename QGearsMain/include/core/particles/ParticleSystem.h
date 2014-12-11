#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <OgreMovableObject.h>

#include "ParticleTechnique.h"



class ParticleSystem : public Ogre::MovableObject
{
public:
    ParticleSystem(const Ogre::String& name);
    virtual ~ParticleSystem();
    void CopyAttributesTo(ParticleSystem* ps);

    // realization of Ogre::MovableObject
    const Ogre::String& getMovableType() const;
    const Ogre::AxisAlignedBox& getBoundingBox() const;
    Ogre::Real getBoundingRadius() const;
    void _updateRenderQueue(Ogre::RenderQueue* queue);
    void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false) {};

    void Update(Ogre::Real time_elapsed);

    // technique
    ParticleTechnique* CreateTechnique();
    void AddTechnique(ParticleTechnique* technique);
    void DestroyAllTechniques();

private:
    std::vector<ParticleTechnique*> m_Techniques;
};



#endif // PARTICLE_SYSTEM_H
