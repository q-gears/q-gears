#ifndef PARTICLE_RENDERER_TRANSLATOR_H
#define PARTICLE_RENDERER_TRANSLATOR_H

#include <OgreScriptTranslator.h>
#include <OgreSingleton.h>



class ParticleRendererTranslator : public Ogre::ScriptTranslator
{
public:
    void translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node);
};



#endif // PARTICLE_RENDERER_TRANSLATOR_H
