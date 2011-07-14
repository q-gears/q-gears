#include "Main.h"

#include <Ogre.h>

#include <stdio.h>
#include <iostream>

#include "../../common/BinGZipFile.h"
#include "../../common/FileSystem.h"
#include "../../common/Logger.h"
#include "../../common/TimToVram.h"
#include "../../common/OgreGenUtilites.h"

#include "FontFile.h"



int state;



int
main( int argc, char *argv[] )
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



    FILESYSTEM = new FileSystem();
    LOGGER = new Logger( "game.log" );

    state = GAME;



    {
        BinGZipFile* file = new BinGZipFile( "data/en/WINDOW.BIN" );
        File* font_graf    = file->ExtractGZip( 1 );
        File* font_padding = file->ExtractGZip( 2 );
        FontFile font( font_padding );
        font.Export( "export_en/ui/fonts/ffvii_en.xml", true );
        //font_graf->WriteFile( "font.tim" );

        Vram* vram = new Vram();
        LoadTimFileToVram( font_graf, 0, vram );
        //vram->Save( "text" );

        Ogre::TexturePtr ptex;
        Ogre::HardwarePixelBufferSharedPtr buffer;
        ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, 256, 256, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
        buffer = ptex->getBuffer( 0, 0 );
        buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
        const Ogre::PixelBox& pb = buffer->getCurrentLock();
        CreateTextureFromVram( pb, vram, 0, 0, 0x80, 0x1f7, 0x380, 0x100, 0 , false );
        Ogre::Image image;
        image.loadDynamicImage( ( Ogre::uchar* )pb.data, 256, 256, Ogre::PF_R8G8B8A8 );
        image.save( "export_en/ui/fonts/ffvii_en.png" );
        buffer->unlock();

        delete file;
    }

    {
        BinGZipFile* file = new BinGZipFile( "data/jp/WINDOW.BIN" );
        File* font_graf    = file->ExtractGZip( 1 );
        File* font_padding = file->ExtractGZip( 2 );
        FontFile font( font_padding );
        font.Export( "export_jp/ui/fonts/ffvii_jp.xml", false );
        delete file;
    }



    LOGGER->Log("===================== Stop the game!!!");



    delete FILESYSTEM;
    delete LOGGER;



    delete root;

    return 0;
}
