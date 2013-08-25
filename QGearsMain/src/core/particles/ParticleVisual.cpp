#include "ParticleVisual.h"

#include "ParticleVisual.h"



VisualParticle::VisualParticle():
    Particle()
{
    m_ParticleType = PT_VISUAL;
    m_Emittable = true; // Default is false, but visual particles are always emitted.
}



void
VisualParticle::InitForExpiration()
{
    Particle::InitForExpiration();

    if (additional_data != NULL)
    {
        additional_data->SetVisible(false);
    }
}
