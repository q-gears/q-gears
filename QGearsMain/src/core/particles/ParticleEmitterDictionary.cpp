#include "ParticleEmitterDictionary.h"

#include <OgreStringConverter.h>

#include "ParticleEmitter.h"
#include "../Logger.h"
#include "../Utilites.h"



namespace ParticleEmitterDictionary
{
    void
    EmissionRate::doSet(void* target, const Ogre::String& val)
    {
        static_cast<ParticleEmitter*>(target)->SetEmissionRate(Ogre::StringConverter::parseInt(val));
    }

    void
    TotalTimeToLive::doSet(void* target, const Ogre::String& val)
    {
        static_cast<ParticleEmitter*>(target)->SetEmitTotalTimeToLive(Ogre::StringConverter::parseReal(val));
    }

    void
    Direction::doSet(void* target, const Ogre::String& val)
    {
        Ogre::StringVector strings = StringTokenise(val);
        if (strings.size() == 1)
        {
            static_cast<ParticleEmitter*>(target)->SetEmitDirection(Ogre::StringConverter::parseVector3(strings[0]));
        }
        else if (strings.size() > 1)
        {
            static_cast<ParticleEmitter*>(target)->SetEmitDirectionRange(Ogre::StringConverter::parseVector3(strings[0]), Ogre::StringConverter::parseVector3(strings[1]));
        }
        else
        {
            LOG_WARNING("In particle emitter setting direction must be at least one value.");
        }
    }
}
