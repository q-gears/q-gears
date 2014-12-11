#ifndef PARTICLE_TECHNIQUE_TRANSLATOR_H
#define PARTICLE_TECHNIQUE_TRANSLATOR_H

#include <OgreScriptTranslator.h>
#include <OgreSingleton.h>



class ParticleTechniqueTranslator : public Ogre::ScriptTranslator
{
public:
    void translate(Ogre::ScriptCompiler *compiler, const Ogre::AbstractNodePtr &node);
};



#endif // PARTICLE_TECHNIQUE_TRANSLATOR_H
