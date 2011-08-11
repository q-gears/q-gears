#include <Ogre.h>
#include <OgreTextAreaOverlayElement.h>
#include <OIS.h>
#include <stdio.h>
#include <iostream>

#include "../../common/FileSystem.h"
#include "../../common/Logger.h"

#include "EnemyFile.h"
#include "RamEffectFile.h"
#include "StageFile.h"


std::vector<EnemyInfo> models_all;
std::vector<EffectInfo> effects_all;
std::vector<StageInfo> stages_all;
std::vector<Ogre::Entity*> entitys;
Ogre::Camera* camera;

Ogre::TextAreaOverlayElement* info_text;
Ogre::Overlay* info_overlay;







void
fill_names()
{
    EnemyInfo info;

    Ogre::ConfigFile cf;
    cf.load("export_models.cfg");
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        if (names != "")
        {
            Ogre::StringVector name = Ogre::StringUtil::split(names, ":", 3);
            if (name.size() < 3)
            {
                LOGGER->Log("In '" + names + "' not enough names. Must be 3.\n");
                continue;
            }
            info.file_name = name[0];
            info.data.name = name[1];

            Ogre::StringVector tex_size = Ogre::StringUtil::split(name[2], "x", 2);
            info.data.tex_width = Ogre::StringConverter::parseInt(tex_size[0]);
            info.data.tex_height = Ogre::StringConverter::parseInt(tex_size[1]);

            if (info.file_name != "")
            {
                Ogre::ConfigFile::SettingsMultiMap::iterator i;
                for (i = settings->begin(); i != settings->end(); ++i)
                {
                    info.animations.push_back(i->second);
                    LOGGER->Log("Animation add:" + info.file_name + " " + i->second + "\n");
                }

                models_all.push_back(info);
                info.animations.clear();
            }
        }
    }



    EffectInfo effect;
    cf.load("export_effects.cfg");
    seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        if (names == "")
        {
            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                effect.data.name = i->second;
                effect.data.tex_width = 256;
                effect.data.tex_height = 256;
                effect.offset = Ogre::StringConverter::parseInt(i->first);

                LOGGER->Log("Effect: " + i->second + ": " + i->first);

                effects_all.push_back(effect);
            }
        }
    }



    StageInfo stage;
    cf.load("export_stages.cfg");
    seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        if (names == "")
        {
            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                stage.file_name = i->first;

                Ogre::StringVector name = Ogre::StringUtil::split(i->second, ":", 2);
                if (name.size() < 2)
                {
                    LOGGER->Log("In '" + names + "' not enough names. Must be 2.\n");
                    continue;
                }

                stage.data.name = name[0];

                Ogre::StringVector tex_size = Ogre::StringUtil::split(name[1], "x", 2);
                stage.data.tex_width = Ogre::StringConverter::parseInt(tex_size[0]);
                stage.data.tex_height = Ogre::StringConverter::parseInt(tex_size[1]);

                LOGGER->Log("Stage: " + i->first + ": " + i->second + "\n");

                stages_all.push_back(stage);
            }
        }
    }


    LOGGER->Log("Initialize export list finished.\n\n\n\n");
}



class DisplayFrameListener : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener
{
public:
    // Constructor takes a RenderWindow because it uses that to determine input context
    DisplayFrameListener( Ogre::RenderWindow* win ):

        m_Window( win ),
        m_InputManager( 0 ),
        m_Keyboard( 0 ),
        m_Mouse( 0 ),
        m_MouseRotate( false ),
        m_MouseMoveX( 0 ),
        m_MouseMoveY( 0 ),
        m_Exit( false )
    {
        using namespace OIS;

        Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
        ParamList pl;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;

        win->getCustomAttribute("WINDOW", &windowHnd);
        windowHndStr << windowHnd;
        pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

        m_InputManager = InputManager::createInputSystem(pl);

        m_Keyboard = static_cast<Keyboard*>(m_InputManager->createInputObject(OIS::OISKeyboard, true));
        m_Keyboard->setEventCallback(this);

        m_Mouse = static_cast<OIS::Mouse*>(m_InputManager->createInputObject(OIS::OISMouse, true));
        m_Mouse->setEventCallback(this);

        //Register as a Window listener
        Ogre::WindowEventUtilities::addWindowEventListener(m_Window, this);
    }

    virtual
    ~DisplayFrameListener()
    {
        m_InputManager->destroyInputObject(m_Keyboard);

        OIS::InputManager::destroyInputSystem(m_InputManager);

        //Remove ourself as a Window listener
        Ogre::WindowEventUtilities::removeWindowEventListener(m_Window, this);
        windowClosed(m_Window);
    }

    //Unattach OIS before window shutdown (very important under Linux)
    virtual void
    windowClosed(Ogre::RenderWindow* rw)
    {
        m_Exit = true;
    }

    bool
    frameStarted(const Ogre::FrameEvent& evt)
    {
        if( m_Exit == true )
        {
            return false;
        }


        if (m_Keyboard)
        {
            m_Keyboard->capture();
        }

        if (m_Mouse)
        {
            m_Mouse->capture();
        }

        for (int i = 0; i < entitys.size(); ++i)
        {
            if (entitys[i]->isVisible() == true)
            {
                if (entitys[i]->getAllAnimationStates() != NULL)
                {
                    Ogre::AnimationStateIterator animations = entitys[i]->getAllAnimationStates()->getAnimationStateIterator();

                    while (animations.hasMoreElements() == true)
                    {
                        Ogre::AnimationState* state = animations.getNext();

                        if (state->getEnabled() == true)
                        {
                            state->addTime(evt.timeSinceLastFrame);

                            info_text->setCaption(entitys[i]->getName() + ": " + state->getAnimationName());
                        }
                    }
                }
                break;
            }
        }

        if (m_Keyboard->isKeyDown(OIS::KC_A))
        {
            camera->moveRelative(Ogre::Vector3(-0.01, 0,  0));
        }
        if (m_Keyboard->isKeyDown(OIS::KC_D))
        {
            camera->moveRelative(Ogre::Vector3( 0.01, 0,  0));
        }
        if (m_Keyboard->isKeyDown(OIS::KC_W))
        {
            camera->moveRelative(Ogre::Vector3( 0, 0, -0.01));
        }
        if (m_Keyboard->isKeyDown(OIS::KC_S))
        {
            camera->moveRelative(Ogre::Vector3( 0, 0,  0.01));
        }
        if (m_MouseRotate == true)
        {
            camera->rotate(Ogre::Vector3::UNIT_Y, Ogre::Radian(Ogre::Degree(-m_MouseMoveX * 0.13)));
            camera->pitch(Ogre::Degree(-m_MouseMoveY * 0.13));
            m_MouseMoveX = 0;
            m_MouseMoveY = 0;
        }

        return true;
    }

    // KeyListener
    bool
    keyPressed(const OIS::KeyEvent& e)
    {
        switch (e.key)
        {
            case OIS::KC_RIGHT:
            {
                bool change = false;
                for (int i = 0; i < entitys.size(); ++i)
                {
                    if (change == true)
                    {
                        entitys[i]->setVisible(true);
                        break;
                    }
                    if (entitys[i]->isVisible() == true && (i != entitys.size() - 1))
                    {
                        entitys[i]->setVisible(false);
                        change = true;
                    }
                }
            }
            break;

            case OIS::KC_LEFT:
            {
                bool change = false;
                for (int i = entitys.size() - 1; i >= 0; --i)
                {
                    if (change == true)
                    {
                        entitys[i]->setVisible(true);
                        break;
                    }
                    if (entitys[i]->isVisible() == true && i != 0)
                    {
                        entitys[i]->setVisible(false);
                        change = true;
                    }
                }
            }
            break;

            case OIS::KC_UP:
            {
                bool change = false;
                for (int i = 0; i < entitys.size(); ++i)
                {
                    if (entitys[i]->isVisible() == true)
                    {
                        if (entitys[i]->getAllAnimationStates() != NULL)
                        {
                            Ogre::AnimationStateIterator animations = entitys[i]->getAllAnimationStates()->getAnimationStateIterator();

                            Ogre::AnimationState* old_state;
                            Ogre::AnimationState* new_state = animations.getNext();

                            while (animations.hasMoreElements() == true)
                            {
                                old_state = new_state;
                                new_state = animations.getNext();

                                if (new_state->getEnabled() == true)
                                {
                                    new_state->setEnabled(false);
                                    new_state->setLoop(false);
                                    old_state->setEnabled(true);
                                    old_state->setLoop(true);
                                }
                            }
                        }
                        break;
                    }
                }
            }
            break;

            case OIS::KC_DOWN:
            {
                bool change = false;
                for (int i = 0; i < entitys.size(); ++i)
                {
                    if (entitys[i]->isVisible() == true)
                    {
                        if (entitys[i]->getAllAnimationStates() != NULL)
                        {
                            Ogre::AnimationStateIterator animations = entitys[i]->getAllAnimationStates()->getAnimationStateIterator();

                            while (animations.hasMoreElements() == true)
                            {
                                Ogre::AnimationState* state = animations.getNext();

                                if (change == true)
                                {
                                    state->setEnabled(true);
                                    state->setLoop(true);
                                    break;
                                }
                                if (state->getEnabled() == true && animations.hasMoreElements() != false)
                                {
                                    state->setEnabled(false);
                                    state->setLoop(false);
                                    change = true;
                                }
                            }
                        }
                        break;
                    }
                }
            }
            break;
        }

        return true;
    }

    bool
    keyReleased(const OIS::KeyEvent& e)
    {
        return true;
    }

    bool
    mouseMoved(const OIS::MouseEvent& e)
    {
        m_MouseMoveX = e.state.X.rel;
        m_MouseMoveY = e.state.Y.rel;
        return true;
    }

    bool
    mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id)
    {
        if (id == OIS::MB_Right)
        {
            m_MouseRotate = true;
        }
        return true;
    }

    bool
    mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id)
    {
        if (id == OIS::MB_Right)
        {
            m_MouseRotate = false;
        }

        return true;
    }

protected:
    Ogre::RenderWindow* m_Window;

    //OIS Input devices
    OIS::InputManager*  m_InputManager;
    OIS::Keyboard*      m_Keyboard;
    OIS::Mouse*         m_Mouse;
    float               m_MouseMoveX;
    float               m_MouseMoveY;
    bool                m_MouseRotate;
    bool                m_Exit;
};



int
main(int argc, char *argv[])
{
    Ogre::Root*         root;
    Ogre::RenderWindow* window;

    root = new Ogre::Root( "", "" );
#ifndef _DEBUG
    root->loadPlugin( "RenderSystem_GL.dll" );
#else
    root->loadPlugin( "RenderSystem_GL_d.dll" );
#endif
    root->setRenderSystem( root->getAvailableRenderers()[ 0 ] );
    root->initialise( false );
    Ogre::NameValuePairList misc;
    misc[ "title" ] = "FFVII Exporter";
    window = root->createRenderWindow( "QGearsWindow", 800, 600, false, &misc );


    Ogre::SceneManager* scene_manager;
    Ogre::Camera*       camera;
    Ogre::Viewport*     viewport;



    DisplayFrameListener* frame_listener = new DisplayFrameListener(window);
    root->addFrameListener(frame_listener);

    scene_manager = root->createSceneManager(Ogre::ST_GENERIC, "Scene");
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    camera = scene_manager->createCamera("Camera");
    camera->setNearClipDistance(0.05);

    viewport = window->addViewport(camera);
    viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    camera->setAspectRatio(Ogre::Real(viewport->getActualWidth()) / Ogre::Real(viewport->getActualHeight()));

    Ogre::ResourceGroupManager::getSingleton().addResourceLocation( "./exported", "FileSystem", "Game", true );
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();



    FILESYSTEM = new FileSystem();
    LOGGER = new Logger("game.log");



    fill_names();



    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    scene_manager->clearScene();
    scene_manager->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    scene_manager = Ogre::Root::getSingleton().getSceneManager("Scene");
    camera = scene_manager->getCamera("Camera");
    camera->setPosition(10, 5, 10);
    camera->lookAt(0, 0, 0);



    for (int i = 0; i < models_all.size(); ++i)
    {
        EnemyFile model("data/" + models_all[i].file_name + ".LZS");

        //model.WriteFile(models_all[i].file_name + "_u.LZS");
        Ogre::Entity* exported_entity = model.GetModel(models_all[i]);

        if (exported_entity != NULL)
        {
            entitys.push_back(exported_entity);
        }
    }

    for (int i = 0; i < effects_all.size(); ++i)
    {
        RamEffectFile effect("data/ram.bin");
        Ogre::Entity* exported_entity = effect.GetModel(effects_all[i]);
        if (exported_entity != NULL)
        {
            entitys.push_back(exported_entity);
        }
    }

    for (int i = 0; i < stages_all.size(); ++i)
    {
        StageFile model("data/" + stages_all[i].file_name + ".LZS");

        //model.WriteFile(models_all[i].file_name + "_u.LZS");
        Ogre::Entity* exported_entity = model.GetModel(stages_all[i]);

        if (exported_entity != NULL)
        {
            entitys.push_back(exported_entity);
        }
    }



    //entitys[0]->setVisible(true);

    // debug info
    info_text = new Ogre::TextAreaOverlayElement("DebugText");
    info_text->setCaption("");
    info_text->setMetricsMode(Ogre::GMM_PIXELS);
    info_text->setPosition(5, 5);
    info_text->setFontName("BlueHighway");
    info_text->setCharHeight(18);

    info_overlay = Ogre::OverlayManager::getSingleton().create("DebugOverlay");
    info_overlay->setZOrder(1);
    info_overlay->add2D((Ogre::OverlayContainer*)info_text);
    info_overlay->show();



    Ogre::Root::getSingleton().startRendering();



    LOGGER->Log("===================== Stop the game!!!");



    delete LOGGER;
    delete FILESYSTEM;

    delete root;
    delete frame_listener;

    return 0;
}
