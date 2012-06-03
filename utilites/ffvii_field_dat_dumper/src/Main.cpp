#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "DatFile.h"
#include "MimFile.h"



std::vector< Field > fields;

int state;



void
fill_names()
{
    Ogre::ConfigFile cf;
    cf.load( "export.cfg" );
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    while( seci.hasMoreElements() )
    {
        Field field;

        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();

        if( names == "" )
        {
            continue;
        }

        Ogre::StringVector name = Ogre::StringUtil::split( names, ":", 3 );
        if( name.size() < 3 )
        {
            LOGGER->Log( "In \"" + names + "\" not enough data. Must be 3.\n" );
            continue;
        }
        field.name = name[ 0 ];
        field.scale = Ogre::StringConverter::parseReal( name[ 2 ] );

        Ogre::StringVector tex_size = Ogre::StringUtil::split( name[ 1 ], "x", 2 );
        field.tex_width = Ogre::StringConverter::parseInt( tex_size[ 0 ] );
        field.tex_height = Ogre::StringConverter::parseInt( tex_size[ 1 ] );

        LOGGER->Log( "Export map \"" + field.name + "\" with tex_width=" + IntToString( field.tex_width ) + ", tex_height=" + IntToString( field.tex_height ) + ".\n" );

        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for( i = settings->begin(); i != settings->end(); ++i )
        {
            FiledAnimation animation;
            animation.name = i->first;

            Ogre::StringVector anim = Ogre::StringUtil::split( i->second, ";", 2 );
            if( anim.size() < 2 )
            {
                LOGGER->Log("In \"" + i->second + "\" not enough data separated by \";\". Must be 2.\n");
                continue;
            }

            Ogre::StringVector anim_data = Ogre::StringUtil::split( anim[ 0 ], ":", 2 );
            if( anim_data.size() < 2 )
            {
                LOGGER->Log("In \"" + anim[ 0 ] + "\" not enough data. Must be 2.\n");
                continue;
            }

            animation.time = Ogre::StringConverter::parseReal( anim_data[ 0 ] );

            Ogre::StringVector anim_type = Ogre::StringUtil::split( anim_data[ 1 ], "-", 2 );
            if( anim_type.size() < 2 )
            {
                LOGGER->Log("In \"" + anim_data[ 1 ] + "\" not enough data. Must be 2.\n");
                continue;
            }

            if( anim_type[ 0 ] == "anim" )
            {
                animation.type = FAT_ANIMATION;
                animation.animation = Ogre::StringConverter::parseInt( anim_type[ 1 ] );
            }
            else if( anim_type[ 0 ] == "clut" )
            {
                animation.type = FAT_CLUT;
                animation.clut = Ogre::StringConverter::parseInt( anim_type[ 1 ] );
            }
            else
            {
                LOGGER->Log( "Unknown animation type \"" + anim_type[ 0 ] + "\".\n");
                continue;
            }

            LOGGER->Log("Animation \"" + animation.name + "\" add with total time \"" + FloatToString( animation.time ) + "\" and animation_id \"" + IntToString( animation.animation ) + "\", clut \"" + IntToString( animation.clut ) + "\".\n" );

            Ogre::StringVector anim_keyframes = Ogre::StringUtil::split( anim[ 1 ], "," );
            for( unsigned int j = 0; j < anim_keyframes.size(); ++j )
            {
                Ogre::StringVector anim_frame = Ogre::StringUtil::split( anim_keyframes[ j ], ":", 2 );
                if( anim_frame.size() < 2 )
                {
                    LOGGER->Log("In \"" + anim_keyframes[ j ] + "\" not enough data. Must be 2.\n");
                    continue;
                }

                FieldKeyFrame frame;
                frame.time = Ogre::StringConverter::parseReal( anim_frame[ 0 ] );

                if( animation.type == FAT_ANIMATION )
                {
                    if( anim_frame[ 1 ] == "blank" )
                    {
                        frame.blank = true;
                        frame.animation_index = 0;
                    }
                    else
                    {
                        frame.blank = false;
                        frame.animation_index = Ogre::StringConverter::parseInt( anim_frame[ 1 ] );
                    }

                    LOGGER->Log( "Animation keyframe add at time \"" + FloatToString( frame.time ) + "\". Settings blank=\"" + BoolToString( frame.blank ) + "\", animation_index=\"" + IntToString( frame.animation_index ) + "\".\n" );
                }
                else if( animation.type == FAT_CLUT )
                {
                    Ogre::StringVector anim_frame_data = Ogre::StringUtil::split( anim_frame[ 1 ], "-", 2 );
                    if( anim_frame_data.size() < 2 )
                    {
                        LOGGER->Log("In \"" + anim_frame[ 1 ] + "\" not enough data separated by \"-\". Must be 2.\n");
                        continue;
                    }

                    frame.type = anim_frame_data[ 0 ];
                    Ogre::Vector3 rgb = Ogre::StringConverter::parseVector3( anim_frame_data[ 1 ] );
                    frame.r_mod = rgb.x;
                    frame.g_mod = rgb.y;
                    frame.b_mod = rgb.z;

                    LOGGER->Log( "Clut keyframe add at time \"" + FloatToString( frame.time ) + "\". Settings type=\"" + frame.type + "\", r_mod=\"" + FloatToString( frame.r_mod ) + "\", g_mod=\"" + FloatToString( frame.g_mod ) + "\", b_mod=\"" + FloatToString( frame.b_mod ) + "\".\n" );
                }

                animation.keyframes.push_back( frame );
            }

            field.animations.push_back( animation );
        }

        fields.push_back( field );
    }
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "FFVII Field Dat Exporter" );

    fill_names();

/*
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
*/
    for( int f = 0; f < fields.size(); ++f )
    {
        DatFile dat( "data/en/" + fields[ f ].name + ".dat" );
        MimFile mim( "data/en/" + fields[ f ].name + ".mim" );
        dat.DumpScript(  "export_en/", fields[ f ] );
        dat.DumpText( "export_en/", fields[ f ], true );
        dat.DumpTriggersMovements( "export_en/", fields[ f ] );
        dat.DumpWalkmesh( "export_en/", fields[ f ] );
        dat.DumpBackground( "export_en/", fields[ f ], mim );
    }

    //DatFile::DumpSoundOpcodesData("sound.txt");



    LOGGER->Log( "===================== Stop the game!!!" );



    DeinitializeOgreBase();

    return 0;
}
