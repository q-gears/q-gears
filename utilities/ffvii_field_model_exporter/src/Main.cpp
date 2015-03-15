#include <Ogre.h>
#include "common/OgreBase.h"
#include "common/Logger.h"

#include "BsxFile.h"
#include "DatFile.h"



std::vector< Field > fields;



void
fill_names()
{
    Unit unit;
    unit.name = "";
    Field field;


    Ogre::ConfigFile cf;
    cf.load( "export.cfg" );
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    while( seci.hasMoreElements() )
    {
        field.name = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();

        if( field.name != "" )
        {

            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for( i = settings->begin(); i != settings->end(); ++i )
            {
                if( i->second != "" )
                {
                    Ogre::StringVector export_data = Ogre::StringUtil::split( i->second, ":", 1 );

                    unit.name = export_data[ 0 ];

                    Ogre::StringVector animations = Ogre::StringUtil::split( export_data[ 1 ], ",", 0 );
                    //LOGGER->Log(LOGGER_INFO, "Export %s: %s", field.name.c_str(), unit.name.c_str());
                    for( size_t i = 0; i < animations.size(); ++i )
                    {
                        unit.animations.push_back( animations[ i ] );
                    }
                }

                field.units.push_back(unit);
                unit.name = "";
                unit.animations.clear();
            }

            //LOGGER->Log(LOGGER_INFO, "Add export field %s", field.name.c_str());
            fields.push_back(field);
            field.units.clear();
        }
    }
}



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "FFVII Field Model Exporter" );



    fill_names();



    for( size_t f = 0; f < fields.size(); ++f )
    {
        BsxFile model( "data/field/" + fields[ f ].name + ".bsx" );
        DatFile dat( "data/field/" + fields[ f ].name + ".dat" );

        for( size_t i = 0; i < fields[ f ].units.size(); ++i )
        {
            if( fields[ f ].units[ i ].name != "" )
            {
                Ogre::Entity* entity = NULL;
                for( size_t j = 0; j < entitys.size(); ++j )
                {
                    if( fields[ f ].units[ i ].name == entitys[ j ]->getName() )
                    {
                        entity = entitys[ j ];
                    }
                }

                DatModelData data;
                dat.GetModelData( i, data );

                Ogre::Entity* exported_entity = model.GetModel( entity, i, fields[ f ].units[ i ], data );

                if( exported_entity != NULL )
                {
                    entitys.push_back( exported_entity );
                }
            }
        }
    }

    entitys[ 0 ]->setVisible(true);



    Ogre::Root::getSingleton().startRendering();



    DeinitializeOgreBase();



    return 0;
}
