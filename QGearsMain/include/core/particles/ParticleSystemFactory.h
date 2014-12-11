#ifndef PARTICLE_SYSTEM_FACTORY_H
#define PARTICLE_SYSTEM_FACTORY_H

#include <OgreMovableObject.h>



class ParticleSystemFactory : public Ogre::MovableObjectFactory
{
public:
    ParticleSystemFactory() {};
    ~ParticleSystemFactory() {};

    static Ogre::String FACTORY_TYPE_NAME;

    const Ogre::String& getType() const;

    void destroyInstance(Ogre::MovableObject* obj);

private:
    Ogre::MovableObject* createInstanceImpl(const Ogre::String& name, const Ogre::NameValuePairList* params);
};



#endif // PARTICLE_SYSTEM_FACTORY_H
