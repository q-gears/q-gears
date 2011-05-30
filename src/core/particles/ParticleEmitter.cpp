#include "ParticleEmitter.h"

#include <OgreLogManager.h>
#include <OgreString.h>
#include <OgreStringConverter.h>

#include "ParticleTechnique.h"



ParticleEmitterDictionary::EmissionRate ParticleEmitter::m_EmissionRateDictionary;
ParticleEmitterDictionary::TotalTimeToLive ParticleEmitter::m_TotalTimeToLiveDictionary;
ParticleEmitterDictionary::Direction ParticleEmitter::m_DirectionDictionary;



ParticleEmitter::ParticleEmitter(void) :
    Particle(),
    m_ParentTechnique(NULL),
    m_Name(Ogre::StringUtil::BLANK),
    m_EmitsName(Ogre::StringUtil::BLANK),
    m_EmitsType(PT_VISUAL),
    m_EmissionRate(1),
    m_EmissionRemainder(0),

    m_EmitDirection1(Ogre::Vector3::ZERO),
    m_EmitDirection2(Ogre::Vector3::ZERO),
    m_EmitTotalTimeToLive(10)
{
    m_ParticleType = PT_EMITTER;

    if (createParamDictionary("ParticleEmitter"))
    {
        Ogre::ParamDictionary* dict = getParamDictionary();

        dict->addParameter(Ogre::ParameterDef("emission_rate", "", Ogre::PT_INT), &m_EmissionRateDictionary);
        dict->addParameter(Ogre::ParameterDef("time_to_live", "", Ogre::PT_REAL), &m_TotalTimeToLiveDictionary);
        dict->addParameter(Ogre::ParameterDef("direction", "", Ogre::PT_STRING), &m_DirectionDictionary);
    }
}



ParticleEmitter::~ParticleEmitter()
{
}



void
ParticleEmitter::CopyAttributesTo(ParticleEmitter* emitter)
{
    Particle::CopyAttributesTo(emitter);

    emitter->SetParentTechnique(m_ParentTechnique);
    emitter->SetName(m_Name);
    emitter->SetEmitterType(m_EmitterType);

    emitter->SetEmitsName(m_EmitsName);
    emitter->SetEmitsType(m_EmitsType);
    emitter->SetEmissionRate(m_EmissionRate);

    emitter->SetEmitDirectionRange(m_EmitDirection1, m_EmitDirection2);
    emitter->SetEmitTotalTimeToLive(m_EmitTotalTimeToLive);
}



void
ParticleEmitter::InitForEmission()
{
    m_EmissionRemainder = 0;
}



int
ParticleEmitter::CalculateRequestedParticles(Ogre::Real time_elapsed)
{
    int request = 0;
    Ogre::LogManager::getSingletonPtr()->logMessage("ParticleEmitter::CalculateRequestedParticles time:" +
        Ogre::StringConverter::toString(time_elapsed) +
        " emission rate:" +
        Ogre::StringConverter::toString(m_EmissionRate) +
        " reminder:" +
        Ogre::StringConverter::toString(m_EmissionRemainder));
    if (m_Enabled && m_EmissionRate > 0)
    {
        m_EmissionRemainder += m_EmissionRate * time_elapsed;
        request = (int)m_EmissionRemainder;
        m_EmissionRemainder -= request;
    }

    return request;
}



void
ParticleEmitter::InitParticleForEmission(Particle* particle)
{
    particle->SetParentEmitter(this);

    particle->position = position; // particle emits from emitter position
    particle->direction.x = Ogre::Math::RangeRandom(m_EmitDirection1.x, m_EmitDirection2.x);
    particle->direction.y = Ogre::Math::RangeRandom(m_EmitDirection1.y, m_EmitDirection2.y);
    particle->direction.z = Ogre::Math::RangeRandom(m_EmitDirection1.z, m_EmitDirection2.z);
    particle->time_to_live = m_EmitTotalTimeToLive;
    particle->total_time_to_live = m_EmitTotalTimeToLive;
}



void
ParticleEmitter::SetEmitsName(const Ogre::String& emits_name)
{
    m_EmitsName = emits_name;
    if (m_ParentTechnique && m_EmitsName != Ogre::StringUtil::BLANK)
    {
        // Notify the Technique that something changed
        m_ParentTechnique->EmissionChange();
    }
}
