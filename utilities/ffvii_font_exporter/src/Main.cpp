#include "Main.h"

#include <Ogre.h>

#include <stdio.h>
#include <iostream>

#include "../../common/BinGZipFile.h"
#include "common/FileSystem.h"
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
        CreateTextureFromVram( pb, vram, 0, 0, 0x80, 0x1f7, 0x380, 0x100, BPP_4 , false );
        Ogre::Image image;
        image.loadDynamicImage( ( Ogre::uchar* )pb.data, 256, 256, Ogre::PF_R8G8B8A8 );
        image.save( "export_en/ui/fonts/ffvii_en.png" );
        buffer->unlock();

        delete vram;
        delete file;
    }

    {
        BinGZipFile* file = new BinGZipFile( "data/jp/WINDOW.BIN" );
        File* font_graf    = file->ExtractGZip( 1 );
        File* font_graf2   = file->ExtractGZip( 2 );
        File* font_padding = file->ExtractGZip( 3 );
        font_padding->WriteFile( "font_padding.dat" );
        FontFile font( font_padding );
        font.Export( "export_jp/ui/fonts/ffvii_jp.xml", false );
        font_graf->WriteFile( "font.tim" );
        font_graf2->WriteFile( "font2.tim" );

        Vram* vram = new Vram();
        LoadTimFileToVram( font_graf, 0, vram );
        LoadTimFileToVram( font_graf2, 0, vram );
        //vram->Save( "text" );

        Ogre::TexturePtr ptex;
        Ogre::HardwarePixelBufferSharedPtr buffer;
        ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, 512, 256, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
        buffer = ptex->getBuffer( 0, 0 );
        buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
        const Ogre::PixelBox& pb = buffer->getCurrentLock();
        CreateTextureFromVram( pb, vram, 0, 0, 0x80, 0x1f7, 0x380, 0x100, BPP_4 , false );
        CreateTextureFromVram( pb, vram, 256, 0, 0x90, 0x1f7, 0x380, 0x100, BPP_4 , false );
        Ogre::Image image;
        image.loadDynamicImage( ( Ogre::uchar* )pb.data, 512, 256, Ogre::PF_R8G8B8A8 );
        image.save( "export_jp/ui/fonts/ffvii_jp.png" );
        buffer->unlock();

        delete vram;
        delete file;
    }

    {
        File sword( "sword.tim" );

        Vram* vram = new Vram();
        LoadTimFileToVram( &sword, 0, vram );
        //vram->Save( "sword" );

        Ogre::TexturePtr ptex;
        Ogre::HardwarePixelBufferSharedPtr buffer;
        ptex = Ogre::TextureManager::getSingleton().createManual( "DynaTex", "General", Ogre::TEX_TYPE_2D, 256, 256, 0, Ogre::PF_R8G8B8A8, Ogre::TU_STATIC );
        buffer = ptex->getBuffer( 0, 0 );
        buffer->lock( Ogre::HardwareBuffer::HBL_DISCARD );
        const Ogre::PixelBox& pb = buffer->getCurrentLock();
        CreateTextureFromVram( pb, vram, 0, 0, 0x0, 0x1e0, 0x0, 0x0, BPP_8 , false );

        Ogre::Image image;
        image.loadDynamicImage( ( Ogre::uchar* )pb.data, 256, 256, Ogre::PF_R8G8B8A8 );
        image.save( "sword.png" );
        buffer->unlock();

        delete vram;
    }

    LOGGER->Log("===================== Stop the game!!!");



    delete LOGGER;



    delete root;

    return 0;
}
