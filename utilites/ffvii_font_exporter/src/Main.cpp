#include "Main.h"

#include <Ogre.h>

#include <stdio.h>
#include <iostream>

#include "../../common/BinGZipFile.h"
#include "../../common/FileSystem.h"
#include "../../common/Logger.h"
#include "../../common/TimToVram.h"

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

        font_graf->WriteFile( "font.tim" );

        Vram* vram = new Vram();
        LoadTimFileToVram( font_graf, 0, vram );
        vram->Save( "text.jpg" );
        //CreateTextureFromVram(const Ogre::PixelBox& pb, vram, const int start_x, const int start_y, 0x100, 0x1f0, const int texture_x, const int texture_y, 0);

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
