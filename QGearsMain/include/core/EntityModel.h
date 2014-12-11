#ifndef ENTITY_MODEL_H
#define ENTITY_MODEL_H

#include "Entity.h"



class EntityModel : public Entity
{
public:
                        EntityModel( const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node );
    virtual             ~EntityModel();

    virtual void        Update();

    // model related
    virtual void        SetVisible( const bool visible );
    virtual bool        IsVisible() const;

    // animation related
    virtual void        PlayAnimation( const Ogre::String& animation, AnimationState state, AnimationPlayType play_type, const float start, const float end );
    virtual void        PlayAnimationContinue( const Ogre::String& animation );
    virtual void        UpdateAnimation( const float delta );

private:
    EntityModel();

private:
    Ogre::Entity* m_Model;
    Ogre::AnimationState* m_AnimationCurrent;
};



#endif // ENTITY_MODEL_H
