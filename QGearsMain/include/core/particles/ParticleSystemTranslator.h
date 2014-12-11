#ifndef PARTICLE_SYSTEM_TRANSLATOR_H
#define PARTICLE_SYSTEM_TRANSLATOR_H

#include <OgreScriptTranslator.h>
#include <OgreSingleton.h>



class ParticleSystemTranslator : public Ogre::ScriptTranslator
{
public:
    void translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node);
};



#endif // PARTICLE_SYSTEM_TRANSLATOR_H
