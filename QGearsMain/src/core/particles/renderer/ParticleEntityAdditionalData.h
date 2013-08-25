#ifndef PARTICLE_ENTITY_ADDITIONAL_DATA_H
#define PARTICLE_ENTITY_ADDITIONAL_DATA_H



#include "../ParticleAdditionalData.h"



struct ParticleEntityAdditionalData : public ParticleAdditionalData
{
    ParticleEntityAdditionalData(Ogre::SceneNode* scene_node):
        node(scene_node)
    {
    };

    void SetVisible(bool visible)
    {
        if (node != NULL)
        {
            node->setVisible(visible);
        }
    }

    Ogre::SceneNode* node;
};


#endif // PARTICLE_ENTITY_ADDITIONAL_DATA_H
