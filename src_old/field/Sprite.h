// $Id$

#ifndef SPRITE_h
#define SPRITE_h

#include <Ogre.h>
#include "Entity.h"
#include "FieldTypes.h"
#include "FieldScriptManager.h"
#include "Walkmesh.h"



class Sprite : public Entity
{
public:
                         Sprite(const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node, FieldScriptManager* script, Walkmesh* walkmesh);
    virtual             ~Sprite();

    virtual void         Input(const Event& input);
    virtual void         Update(const float delta_time);

    // model related
    virtual void                 SetVisible(const bool visible);
    virtual const bool           IsVisible() const;

    // animation related
    virtual void                 AnimationUpdate(const float delta_time);
    virtual bool                 SetAnimationState(const Ogre::String& animation, const float start, const float end, const float speed, const ModelAnimation state);
    virtual void                 PlayAnimationLooped(const Ogre::String& animation, const float relative_speed);

private:
    Sprite(void);

private:
    Ogre::BillboardSet* m_SpriteSet;
    Ogre::Billboard*    m_Sprite;
};



#endif // SPRITE_h
