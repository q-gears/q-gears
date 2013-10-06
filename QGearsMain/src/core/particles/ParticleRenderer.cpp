#include "core/particles/ParticleRenderer.h"

//------------------------------------------------------------------------------
ParticleRenderer::ParticleRenderer():
    m_ParentTechnique(NULL),
    m_RendererInitialised(false)
{
}

//------------------------------------------------------------------------------
ParticleRenderer::~ParticleRenderer()
{
}

//------------------------------------------------------------------------------
void
ParticleRenderer::CopyAttributesTo(ParticleRenderer* renderer)
{
}

//------------------------------------------------------------------------------
void
ParticleRenderer::SetRendererInitialised(bool renderer_initialised)
{
    m_RendererInitialised = renderer_initialised;
}

//------------------------------------------------------------------------------
bool
ParticleRenderer::IsRendererInitialised() const
{
    return m_RendererInitialised;
}

//------------------------------------------------------------------------------
void
ParticleRenderer::SetRendererType(Ogre::String renderer_type)
{
    m_RendererType = renderer_type;
}

//------------------------------------------------------------------------------
const Ogre::String&
ParticleRenderer::GetRendererType() const
{
    return m_RendererType;
}

//------------------------------------------------------------------------------
void
ParticleRenderer::SetParentTechnique(ParticleTechnique* parent_technique)
{
    m_ParentTechnique = parent_technique;
}

//------------------------------------------------------------------------------
const ParticleTechnique*
ParticleRenderer::GetParentTechnique() const
{
    return m_ParentTechnique;
}

//------------------------------------------------------------------------------
