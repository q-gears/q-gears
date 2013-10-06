#include "core/particles/renderer/ParticleEntityRenderer.h"

#include <OgreEntity.h>
#include <OgreRoot.h>

#include "core/particles/ParticleSystem.h"
#include "core/particles/ParticleTechnique.h"
#include "core/particles/ParticleVisual.h"

//------------------------------------------------------------------------------
ParticleEntityRendererDictionary::MeshName ParticleEntityRenderer::m_MeshNameDictionary;

//------------------------------------------------------------------------------
ParticleEntityRenderer::ParticleEntityRenderer():
    ParticleRenderer(),
    m_MeshName(Ogre::StringUtil::BLANK)
{
    m_RendererType = "Entity";

    if (createParamDictionary("ParticleEntityRenderer"))
    {
        Ogre::ParamDictionary* dict = getParamDictionary();

        dict->addParameter(Ogre::ParameterDef("mesh_name", "", Ogre::PT_STRING), &m_MeshNameDictionary);
    }
}

//------------------------------------------------------------------------------
ParticleEntityRenderer::~ParticleEntityRenderer()
{
    if (m_ParentTechnique == NULL)
    {
        return;
    }

    Clear();
}

//------------------------------------------------------------------------------
void
ParticleEntityRenderer::CopyAttributesTo(ParticleRenderer* renderer)
{
    // First copy parent attributes
    ParticleRenderer::CopyAttributesTo(renderer);

    // First cast to ParticleEntityRenderer
    ParticleEntityRenderer* entity_renderer = static_cast<ParticleEntityRenderer*>(renderer);

    // Copy attributes in case there is a entityRenderer (which should be available)
    entity_renderer->m_MeshName = m_MeshName;
}

//------------------------------------------------------------------------------
const Ogre::String&
ParticleEntityRenderer::GetMeshName() const
{
    return m_MeshName;
}

//------------------------------------------------------------------------------
void
ParticleEntityRenderer::SetMeshName(const Ogre::String& mesh_name)
{
    m_MeshName = mesh_name;
    m_RendererInitialised = false; // Retriggers the _prepare function
    Clear(); // Delete all nodes en entities, they will be rebuild
}

//------------------------------------------------------------------------------
void
ParticleEntityRenderer::Clear()
{
    if (m_ParentTechnique == NULL)
    {
        return;
    }

    // Note: The created ChildSceneNodes are destroyed when the ParticleSystem is destroyed

    std::vector<ParticleEntityAdditionalData*>::const_iterator it;
    std::vector<ParticleEntityAdditionalData*>::const_iterator itEnd = m_AllAdditionalData.end();
    for (it = m_AllAdditionalData.begin(); it != itEnd; ++it)
    {
        delete (*it);
    }

    m_AllAdditionalData.clear();
    m_UnassignedAdditionalData.clear();

    // Destroy the Entities. Do it like this, because it must be assured that the entity still exists
    // and has not already been destroyed.
    Ogre::SceneManager* scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    for( unsigned int i = 0; i < m_Entities.size(); i++ )
    {
        scene_manager->destroyEntity( m_Entities[ i ] );
    }
    m_Entities.clear();

    // Reset the visual data in the pool
    m_ParentTechnique->ResetVisualParticles();
}

//------------------------------------------------------------------------------
void
ParticleEntityRenderer::SetVisible(bool visible)
{
    std::vector<ParticleEntityAdditionalData*>::const_iterator it;
    std::vector<ParticleEntityAdditionalData*>::const_iterator itEnd = m_AllAdditionalData.end();
    for (it = m_AllAdditionalData.begin(); it != itEnd; ++it)
    {
        (*it)->node->setVisible(visible);
    }
}

//------------------------------------------------------------------------------
void
ParticleEntityRenderer::Initialize()
{
    // Use the given technique, although it should be the same as mParentTechnique (must be set already)
    if (!m_ParentTechnique || m_RendererInitialised)
    {
        return;
    }

    std::stringstream ss;
    ss << this;
    Ogre::String entity_name = m_MeshName + ss.str();
    int quota = m_ParentTechnique->GetVisualParticlesQuota();
    Ogre::SceneNode* parent_node = m_ParentTechnique->GetParentSystem()->getParentSceneNode();

    if (parent_node)
    {
        // Create number of visual_data objects including SceneNodes
        for (int i = 0; i < quota; i++)
        {
            ParticleEntityAdditionalData* visual_data = new ParticleEntityAdditionalData(parent_node->createChildSceneNode());
            m_AllAdditionalData.push_back(visual_data); // Used to assign to a particle
            m_UnassignedAdditionalData.push_back(visual_data); // Managed by this renderer
        }

        // Create number of Entities
        Ogre::Entity* entity = Ogre::Root::getSingleton().getSceneManager("Scene")->createEntity(entity_name, m_MeshName); // Base entity

        for( unsigned int i = 0; i < m_AllAdditionalData.size(); ++i )
        {
            Ogre::Entity* cloned_entity = entity->clone( entity_name + Ogre::StringConverter::toString( i ) );
            m_Entities.push_back( cloned_entity );
            m_AllAdditionalData[ i ]->node->attachObject( cloned_entity );
        }
        Ogre::Root::getSingleton().getSceneManager( "Scene" )->destroyEntity( entity_name );
    }

    SetVisible(false);
    m_RendererInitialised = true;
}

//------------------------------------------------------------------------------
void
ParticleEntityRenderer::UpdateRenderQueue(Ogre::RenderQueue* queue, ParticlePool<VisualParticle>& pool)
{
    // Fast check to determine whether there are visual particles
    if (pool.IsEmpty())
    {
        return;
    }

    VisualParticle* particle = pool.GetFirst();
    while (!pool.End())
    {
        if (particle)
        {
            if (!particle->additional_data && !m_UnassignedAdditionalData.empty())
            {
                particle->additional_data = m_UnassignedAdditionalData.back();
                m_UnassignedAdditionalData.pop_back();
            }

            if (particle->additional_data)
            {
                Ogre::SceneNode* node = (static_cast<ParticleEntityAdditionalData*>(particle->additional_data))->node;
                if (node)
                {
                    node->setPosition(particle->position);
                    node->setVisible(true);
                }
            }
        }
        particle = pool.GetNext();
    }
}

//------------------------------------------------------------------------------
