#include "GuiManager.h"

#include <OgreOverlayManager.h>
#include <Ogre.h>

#include "../../Main.h"



template<>GuiManager *Ogre::Singleton< GuiManager >::ms_Singleton = NULL;



GuiManager::GuiManager()
{
    //m_Overlay = Ogre::OverlayManager::getSingleton().create( "Gui" );
    //m_Overlay->setZOrder( QGOO_GUI );
    //m_Overlay->show();

    //m_GuiEffect = new GuiEffect( "GuiEffect" );
    //m_GuiEffect->setMaterialName( "viewer/grid" );
    //m_Overlay->add2D( ( Ogre::OverlayContainer* )m_GuiEffect );

    //Ogre::Entity* entity = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createEntity( "models/battle/units/mp.mesh" );
    //Ogre::AnimationState* animation = entity->getAnimationState( "idle" );
    //animation->setEnabled( true );
    //animation->setLoop( true );
    //Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager( "Scene" )->createSceneNode();
    //node->setPosition( 0, -0.5, -1 );
    //node->pitch( Ogre::Radian( Ogre::Degree( -90 ) ) );
    //node->scale( 0.5, 0.5, 0.5 ); //масштабируем объект
    //node->attachObject( ( Ogre::MovableObject* )entity );
    //node->setScale(Vector3(0.02,0.02,0.1));
    //node->getMaterial()->setDepthCheckEnabled(false);
    //node->setPosition(0,0,0);
    //m_Overlay->add3D( node );
}



GuiManager::~GuiManager()
{
    //m_Overlay->remove2D( ( Ogre::OverlayContainer* )m_GuiEffect );
    //delete m_GuiEffect;

    //Ogre::OverlayManager::getSingleton().destroy( "Gui" );
}




void
GuiManager::Input( const Event& event )
{
}



void
GuiManager::Update()
{
}
