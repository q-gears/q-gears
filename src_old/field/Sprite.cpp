// $Id$

#include <Ogre.h>
#include "Math.h"
#include "Sprite.h"
#include "../Main.h"



Sprite::Sprite(const Ogre::String& name, const Ogre::String file_name, Ogre::SceneNode* node, FieldScriptManager* script, Walkmesh* walkmesh):
    Entity(name, node, script, walkmesh)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    m_SpriteSet = scene_manager->createBillboardSet(m_Name);
    m_SpriteSet->setVisible(false);
    m_SpriteSet->setBillboardOrigin(Ogre::BBO_BOTTOM_CENTER);
    m_SpriteSet->setMaterialName("sprite_timemage");
    m_SpriteSet->setDefaultDimensions(64, 76);

    Ogre::FloatRect coord[8] = {Ogre::FloatRect(128.0f / 158.0f, 0, 159.0f / 158.0f, 1),
                                Ogre::FloatRect(127.0f / 158.0f, 0,  96.0f / 158.0f, 1),
                                Ogre::FloatRect( 31.0f / 158.0f, 0,  0,              1),
                                Ogre::FloatRect( 63.0f / 158.0f, 0,  32.0f / 158.0f, 1),
                                Ogre::FloatRect( 64.0f / 158.0f, 0,  95.0f / 158.0f, 1),
                                Ogre::FloatRect( 32.0f / 158.0f, 0,  63.0f / 158.0f, 1),
                                Ogre::FloatRect( 0,              0,  31.0f / 158.0f, 1),
                                Ogre::FloatRect( 96.0f / 158.0f, 0, 127.0f / 158.0f, 1)};

    m_SpriteSet->setTextureCoords(coord, 8);

    m_Sprite = m_SpriteSet->createBillboard(Ogre::Vector3(0, 0, 0));
    m_Sprite->setTexcoordIndex(1);

    m_ModelNode->attachObject(m_SpriteSet);

    Ogre::LogManager::getSingletonPtr()->logMessage("Sprite created.");
}



Sprite::~Sprite(void)
{
    m_SpriteSet->removeBillboard(m_Sprite);

    m_ModelNode->detachObject(m_SpriteSet);

    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->destroyBillboardSet(m_SpriteSet);

    Ogre::LogManager::getSingletonPtr()->logMessage("Sprite destroyed.");
}



void
Sprite::Input(const Event& input)
{
    Entity::Input(input);
}



void
Sprite::Update(const float delta_time)
{
    Ogre::Camera* camera = Ogre::Root::getSingleton().getAutoCreatedWindow()->getViewport(0)->getCamera();
    Ogre::Vector3 cam_dir = camera->getDirection();
    Ogre::Vector3 cam_pos = camera->getPosition();
    cam_dir = cam_dir - cam_pos;
    cam_dir.z = 0;

    Ogre::Quaternion q = m_ModelNode->getOrientation();
    Ogre::Vector3 ent_dir(0.0f, -1.0f, 0.0f);
    ent_dir = q * ent_dir;

    // angle between vectors
    float side = cam_dir.x * ent_dir.y - cam_dir.y * ent_dir.x;

    float angle = Ogre::Radian(acosf(cam_dir.dotProduct(ent_dir) / (cam_dir.length() * ent_dir.length()))).valueDegrees();
    angle = (side > 0) ? 360 - angle : angle;

    if (angle < 23 || angle >= 338)
    {
        m_Sprite->setTexcoordIndex(0);
    }
    else if (angle >= 23 && angle < 68)
    {
        m_Sprite->setTexcoordIndex(1);
    }
    else if (angle >= 68 && angle < 113)
    {
        m_Sprite->setTexcoordIndex(2);
    }
    else if (angle >= 113 && angle < 158)
    {
        m_Sprite->setTexcoordIndex(3);
    }
    else if (angle >= 158 && angle < 203)
    {
        m_Sprite->setTexcoordIndex(4);
    }
    else if (angle >= 203 && angle < 248)
    {
        m_Sprite->setTexcoordIndex(5);
    }
    else if (angle >= 248 && angle < 293)
    {
        m_Sprite->setTexcoordIndex(6);
    }
    else if (angle >= 293 && angle < 338)
    {
        m_Sprite->setTexcoordIndex(7);
    }



    Entity::Update(delta_time);
}



void
Sprite::SetVisible(const bool visible)
{
    m_SpriteSet->setVisible(visible);
}



const bool
Sprite::IsVisible(void) const
{
    return m_SpriteSet->isVisible();
}



void
Sprite::AnimationUpdate(const float delta_time)
{
}



bool
Sprite::SetAnimationState(const Ogre::String& animation, const float start, const float end, const float speed, const ModelAnimation state)
{
    return true;
}



void
Sprite::PlayAnimationLooped(const Ogre::String& animation, const float relative_speed)
{
}
