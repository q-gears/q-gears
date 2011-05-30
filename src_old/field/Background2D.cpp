// $Id$

#include <Ogre.h>

#include "Background2D.h"



Background2D::Background2D(void)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    Ogre::SceneNode* node = scene_manager->getRootSceneNode()->createChildSceneNode("Background");

    for (int x = 0; x < 128; x += 16)
    {
        for (int y = 0; y < 128; y += 16)
        {
            AddTileBottom(150 + x, 150 + y, 16, 16, x, y);
        }
    }
}



Background2D::~Background2D(void)
{
    for (int i = 0; i < m_LayerBottom.size(); ++i)
    {
        delete m_LayerBottom[i];
    }
}



void
Background2D::Input(const Event& input)
{
}



void
Background2D::Update(const float delta_time)
{
}



void
Background2D::AddTileBottom(const int x, const int y, const int width, const int height, const int src_x, const int src_y)
{
    Ogre::SceneManager* scene_manager;
    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    Ogre::SceneNode* node = scene_manager->getSceneNode("Background");

    BackgroundTile* back = new BackgroundTile();
    back->SetTile(x, y, width, height, src_x, src_y);
    back->setRenderQueueGroup(Ogre::RENDER_QUEUE_BACKGROUND);
    Ogre::AxisAlignedBox aabInf;
    aabInf.setInfinite();
    back->setBoundingBox(aabInf);
    node->attachObject(back);
    m_LayerBottom.push_back(back);
}
