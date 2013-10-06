#ifndef PARTICLE_ENTITY_RENDERER_DICTIONARY_H
#define PARTICLE_ENTITY_RENDERER_DICTIONARY_H

#include <OgreStringInterface.h>



namespace ParticleEntityRendererDictionary
{
    class MeshName : public Ogre::ParamCommand
    {
    public:
        Ogre::String doGet(const void* target) const {return "";}
        void doSet(void* target, const Ogre::String& val);
    };
}



#endif // PARTICLE_ENTITY_RENDERER_DICTIONARY_H
