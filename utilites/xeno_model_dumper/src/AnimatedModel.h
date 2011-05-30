#ifndef ANIMATEDMODEL_H
#define ANIMATEDMODEL_H

#include <Ogre.h>



class AnimatedModel
{
public:
    AnimatedModel();
    virtual ~AnimatedModel();

    void Export(const Ogre::String& model_file, const Ogre::String& animation_file);
};



#endif // ANIMATEDMODEL_H
