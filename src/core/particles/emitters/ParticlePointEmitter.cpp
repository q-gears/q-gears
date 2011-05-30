#include "ParticlePointEmitter.h"



PointEmitter::PointEmitter():
    ParticleEmitter()
{
    m_EmitterType ="Point";
}



void
PointEmitter::CopyAttributesTo(ParticleEmitter* emitter)
{
    ParticleEmitter::CopyAttributesTo(emitter);
}
