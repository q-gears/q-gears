#include "Main.h"

#include <Ogre.h>

#include <stdio.h>
#include <iostream>

#include "../../common/FileSystem.h"
#include "../../common/Logger.h"

#include "DatFile.h"
#include "MimFile.h"



std::vector<Field> fields;

int state;



void
fill_names()
{
    Field field;

    Ogre::ConfigFile cf;
    cf.load("export.cfg");
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        field.name = seci.peekNextKey();
        seci.moveNext();

        if (field.name != "")
        {
            fields.push_back(field);
        }
    }
}



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

    fill_names();

    state = GAME;



    for (int f = 0; f < fields.size(); ++f)
    {
        DatFile dat("data/jp/" + fields[f].name + ".dat");
        dat.DumpScriptData("export_jp/" + fields[f].name + "_script.txt");
        dat.DumpTextData("export_jp/" + fields[f].name + "_text.txt", false);
        dat.DumpWalkmeshData("export_jp/" + fields[f].name + "_wm.xml");
    }
    for (int f = 0; f < fields.size(); ++f)
    {
        DatFile dat("data/jp_in/" + fields[f].name + ".dat");
        dat.DumpScriptData("export_jp_in/" + fields[f].name + "_script.txt");
        dat.DumpTextData("export_jp_in/" + fields[f].name + "_text.txt", false);
        dat.DumpWalkmeshData("export_jp_in/" + fields[f].name + "_wm.xml");
    }
    for( int f = 0; f < fields.size(); ++f )
    {
        DatFile dat( "data/en/" + fields[ f ].name + ".dat" );
        MimFile mim( "data/en/" + fields[ f ].name + ".mim" );
        dat.DumpScriptData( "export_en/" + fields[ f ].name + "_script.txt" );
        dat.DumpTextData( "export_en/" + fields[ f ].name + "_text.txt", true );
        dat.DumpWalkmeshData( "export_en/" + fields[ f ].name + "_wm.xml" );
        dat.DumpBackground( "export_en/" + fields[ f ].name + "_bg.xml", mim );
    }

    DatFile::DumpSoundOpcodesData("sound.txt");



    LOGGER->Log("===================== Stop the game!!!");



    delete FILESYSTEM;
    delete LOGGER;



    delete root;

    return 0;
}
