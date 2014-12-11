#ifndef PARTICLE_EMITTER_DICTIONARY_H
#define PARTICLE_EMITTER_DICTIONARY_H

#include <OgreStringInterface.h>



namespace ParticleEmitterDictionary
{
    class EmissionRate : public Ogre::ParamCommand
    {
    public:
        Ogre::String doGet(const void* target) const {return "";};
        void doSet(void* target, const Ogre::String& val);
    };

    class TotalTimeToLive : public Ogre::ParamCommand
    {
    public:
        Ogre::String doGet(const void* target) const {return "";};
        void doSet(void* target, const Ogre::String& val);
    };

    class Direction : public Ogre::ParamCommand
    {
    public:
        Ogre::String doGet(const void* target) const {return "";};
        void doSet(void* target, const Ogre::String& val);
    };
}



#endif // PARTICLE_EMITTER_DICTIONARY_H
