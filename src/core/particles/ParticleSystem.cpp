#include "ParticleSystem.h"

#include <OgreLogManager.h>
#include <OgreSceneNode.h>

#include "ParticleSystemManager.h"



ParticleSystem::ParticleSystem(const Ogre::String& name):
    MovableObject(name)
{
}



ParticleSystem::~ParticleSystem()
{
    // Destroy nodes that are used for renderers and stuff.
    if (getParentSceneNode())
    {
        getParentSceneNode()->removeAndDestroyAllChildren();
    }

    DestroyAllTechniques();
}



void
ParticleSystem::CopyAttributesTo(ParticleSystem* ps)
{
    // Destroy all existing techniques.
    ps->DestroyAllTechniques();

    // Copy techniques
    ParticleTechnique* cloned_technique = NULL;
    for(int i = 0; i < m_Techniques.size(); ++i)
    {
        cloned_technique = ParticleSystemManager::getSingletonPtr()->CloneTechnique(m_Techniques[i]);
        ps->AddTechnique(cloned_technique);
    }
}



const Ogre::String&
ParticleSystem::getMovableType() const
{
    return "ParticleSystem";
}



const Ogre::AxisAlignedBox&
ParticleSystem::getBoundingBox() const
{
    return Ogre::AxisAlignedBox::BOX_INFINITE;
}



Ogre::Real
ParticleSystem::getBoundingRadius() const
{
    return 999;
}



void
ParticleSystem::_updateRenderQueue(Ogre::RenderQueue* queue)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleSystem::_updateRenderQueue");
    for (int i = 0; i < m_Techniques.size(); ++i)
    {
        m_Techniques[i]->UpdateRenderQueue(queue);
    }
}



void
ParticleSystem::Update(Ogre::Real time_elapsed)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleSystem::Update STARTED. Technique number: " + Ogre::StringConverter::toString(m_Techniques.size()));
    for (int i = 0; i < m_Techniques.size(); ++i)
    {
         m_Techniques[i]->Update(time_elapsed);
    }
}



ParticleTechnique*
ParticleSystem::CreateTechnique()
{
    ParticleTechnique* technique = ParticleSystemManager::getSingletonPtr()->CreateTechnique();
    AddTechnique(technique);
    return technique;
}



void
ParticleSystem::AddTechnique(ParticleTechnique* technique)
{
    m_Techniques.push_back(technique);
    technique->SetParentSystem(this);
}



void
ParticleSystem::DestroyAllTechniques()
{
    for (int i = 0; i < m_Techniques.size(); ++i)
    {
        ParticleSystemManager::getSingletonPtr()->DestroyTechnique(m_Techniques[i]);
    }
    m_Techniques.clear();
}
