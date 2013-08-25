#include "ParticleEntityRendererDictionary.h"
#include "ParticleEntityRenderer.h"

#include <OgreLogManager.h>



namespace ParticleEntityRendererDictionary
{
    void
    MeshName::doSet(void* target, const Ogre::String& val)
    {
        static_cast<ParticleEntityRenderer*>(target)->SetMeshName(val);
    }
}
