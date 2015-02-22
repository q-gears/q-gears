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

        Ogre::StringVector name = Ogre::StringUtil::split( names, ":", 2 );
        if( name.size() < 3 )
        {
            LOGGER->Log( "In \"" + names + "\" not enough data. Must be 3.\n" );
            continue;
        }
        field.name = name[ 0 ];
        field.scale = Ogre::StringConverter::parseReal( name[ 2 ] );

        Ogre::StringVector tex_size = Ogre::StringUtil::split( name[ 1 ], "x", 1 );
        field.tex_width = Ogre::StringConverter::parseInt( tex_size[ 0 ] );
        field.tex_height = Ogre::StringConverter::parseInt( tex_size[ 1 ] );

        LOGGER->Log( "Export map \"" + field.name + "\" with tex_width=" + IntToString( field.tex_width ) + ", tex_height=" + IntToString( field.tex_height ) + ".\n" );

        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for( i = settings->begin(); i != settings->end(); ++i )
        {
            FiledAnimation animation;
            animation.name = i->first;

            Ogre::StringVector anim = Ogre::StringUtil::split( i->second, "|" );
            if( anim.size() < 1 )
            {
                LOGGER->Log( "In \"" + i->second + "\" not enough data separated by \"|\". Must be at least 1.\n" );
                continue;
            }

            float total_time = 0;

            LOGGER->Log( "Animation \"" + animation.name + "\" added.\n" );

            // go through all frames
            for( unsigned int j = 0; j < anim.size(); ++j )
            {
                Ogre::StringVector frame_data = Ogre::StringUtil::split( anim[ j ], ";", 2 );
                if( frame_data.size() < 2 )
                {
                    total_time += Ogre::StringConverter::parseReal( anim[ j ] );
                    LOGGER->Log( "In \"" + anim[ j ] + "\" not enough data separated by \";\". Must be more than 1. Insert pause this way.\n" );
                    continue;
                }

                FieldKeyFrame frame;
                total_time += Ogre::StringConverter::parseReal( frame_data[ 0 ] );
                frame.time = total_time;

                for( unsigned int k = 1; k < frame_data.size(); ++k )
                {
                    Ogre::StringVector frame_data_settings = Ogre::StringUtil::split( frame_data[ k ], "=", 1 );
                    if( frame_data_settings.size() != 2 )
                    {
                        LOGGER->Log( "In \"" + frame_data[ k ] + "\" not enough data separated by \"=\". Must be 2.\n" );
                        continue;
                    }

                    if( frame_data_settings[ 0 ] == "animation" )
                    {
                        Ogre::StringVector animation_settings = Ogre::StringUtil::split( frame_data_settings[ 1 ], " ", 1 );
                        if( animation_settings.size() != 2 )
                        {
                            LOGGER->Log( "In \"" + frame_data_settings[ 1 ] + "\" not enough data separated by \" \". Must be 2.\n" );
                            continue;
                        }

                        frame.animation_id = Ogre::StringConverter::parseInt( animation_settings[ 0 ] );
                        if( animation_settings[ 1 ] == "blank" )
                        {
                            frame.blank = true;
                        }
                        else
                        {
                            frame.animation_frame = Ogre::StringConverter::parseInt( animation_settings[ 1 ] );
                        }
                    }
                    else if( frame_data_settings[ 0 ] == "clut" )
                    {
                        Ogre::StringVector clut_total_settings = Ogre::StringUtil::split( frame_data_settings[ 1 ], ",", 1 );
                        if( clut_total_settings.size() != 2 )
                        {
                            LOGGER->Log( "In \"" + frame_data_settings[ 1 ] + "\" not enough data separated by \",\". Must be 2.\n" );
                            continue;
                        }

                        Ogre::StringVector clut_palette_settings = Ogre::StringUtil::split( clut_total_settings[ 0 ], " ", 2 );
                        if( clut_palette_settings.size() != 3 )
                        {
                            LOGGER->Log( "In \"" + clut_total_settings[ 0 ] + "\" not enough data separated by \" \". Must be 3.\n" );
                            continue;
                        }

                        frame.clut_y      = Ogre::StringConverter::parseInt( clut_palette_settings[ 0 ] ) + 0x1e0;
                        frame.clut_start  = Ogre::StringConverter::parseInt( clut_palette_settings[ 1 ] );
                        frame.clut_width = Ogre::StringConverter::parseInt( clut_palette_settings[ 2 ] );

                        Ogre::StringVector clut_mod_settings = Ogre::StringUtil::split( clut_total_settings[ 1 ], ":", 1 );
                        if( clut_mod_settings.size() != 2 )
                        {
                            LOGGER->Log( "In \"" + clut_total_settings[ 1 ] + "\" not enough data separated by \":\". Must be 2.\n" );
                            continue;
                        }

                        frame.mod_type = clut_mod_settings[ 0 ];
                        Ogre::Vector3 rgb = Ogre::StringConverter::parseVector3( clut_mod_settings[ 1 ] );
                        frame.mod_r = rgb.x;
                        frame.mod_g = rgb.y;
                        frame.mod_b = rgb.z;
                    }
                    else
                    {
                        LOGGER->Log( "Unknown animation type \"" + frame_data_settings[ 0 ] + "\".\n");
                        continue;
                    }
                }

                animation.keyframes.push_back( frame );
                LOGGER->Log( "Keyframe added at time \"" + FloatToString( frame.time ) + "\". Settings blank=\"" + BoolToString( frame.blank ) + "\", animation_id=\"" + IntToString( frame.animation_id ) + "\", animation_frame=\"" + IntToString( frame.animation_frame ) + "\" clut_y=\"" + IntToString( frame.clut_y ) + "\", clut_start=\"" + IntToString( frame.clut_start ) + "\", clut_width=\"" + IntToString( frame.clut_width ) + "\", mod_type=\"" + frame.mod_type + "\", mod_r=\"" + FloatToString( frame.mod_r ) + "\", mod_g=\"" + FloatToString( frame.mod_g ) + "\", mod_b=\"" + FloatToString( frame.mod_b ) + "\".\n" );
            }

            animation.time = total_time;
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
    // can use this for debugging if not using export.cfg
    Field f = {};
    f.tex_width = 1024;
    f.tex_height = 512;
    // Note: Must create path CWD\export_en\maps\ffvii_field
    f.name = "md1_2"; // DO NOT put a full path here, else it will attempt to save with full output path and fail
    fields.push_back(f);
    */


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
    for (unsigned int f = 0; f < fields.size(); ++f)
    {
        DatFile dat( fields[ f ].name + ".dat" );
        MimFile mim( fields[ f ].name + ".mim" );
        dat.DumpScript(  "export_en/", fields[ f ] );
        dat.DumpText( "export_en/", fields[ f ], true );
        dat.DumpTriggersMovements( "export_en/", fields[ f ] );
        dat.DumpWalkmesh( "export_en/", fields[ f ] );
        dat.DumpBackground( "export_en/", fields[ f ], mim );
    }

    //DatFile::DumpSoundOpcodesData("sound.txt");



    DeinitializeOgreBase();

    return 0;
}
