#include "ParticleSystemFactory.h"

#include "ParticleSystem.h"
#include "ParticleSystemManager.h"



Ogre::String ParticleSystemFactory::FACTORY_TYPE_NAME = "QgearsParticleSystem";



const Ogre::String&
ParticleSystemFactory::getType() const
{
    return FACTORY_TYPE_NAME;
};



void
ParticleSystemFactory::destroyInstance(Ogre::MovableObject* obj)
{
    delete obj;
};



Ogre::MovableObject*
ParticleSystemFactory::createInstanceImpl( const Ogre::String& name, const Ogre::NameValuePairList* params)
{
    if (params != 0)
    {
        Ogre::NameValuePairList::const_iterator ni = params->find("template_name");
        if (ni != params->end())
        {
            Ogre::String template_name = ni->second;

            // Look up template
            ParticleSystem* pTemplate = ParticleSystemManager::getSingleton().GetParticleSystemTemplate(template_name);
            if (!pTemplate)
            {
                OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS, "Cannot find required template '" + template_name + "'", "ParticleSystemManager::CreateSystem");
            }

            ParticleSystem* sys = new ParticleSystem(name);

            // Copy template settings
            pTemplate->CopyAttributesTo(sys);
            return sys;
        }
    }

    // Not template based, just create one with the given name
    return new ParticleSystem(name);
}
