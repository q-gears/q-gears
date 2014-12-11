#include "core/particles/renderer/ParticleEntityRendererDictionary.h"
#include "core/particles/renderer/ParticleEntityRenderer.h"

#include <OgreLogManager.h>

namespace ParticleEntityRendererDictionary
{
    //--------------------------------------------------------------------------
    void
    MeshName::doSet(void* target, const Ogre::String& val)
    {
        static_cast<ParticleEntityRenderer*>(target)->SetMeshName(val);
    }

    //--------------------------------------------------------------------------
}
