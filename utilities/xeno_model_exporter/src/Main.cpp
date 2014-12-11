#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"
#include "FieldModel.h"
#include "AnimatedModel.h"
#include "ModelFile.h"



int
main( int argc, char* argv[] )
{
    InitializeOgreBase( "Xenogears Model Exporter" );



    {
        //FieldModel model;
        //model.Export("data/0634", "data/0635.raw2");
        //model.Export("data/0632", "data/0633.raw2");
        //model.Export("data/0608", "data/0609.raw2"); // lahan
    }

    {
/*
        MeshData data;
        data.name = "robo1";
        data.tex_width = 4096;
        data.tex_height = 256;
        ModelInfo model_info;
        model_info.data = data;
        model_info.model_file = "2203.model";
        model_info.animation_file = "2202.animation";
        model_info.animations.push_back( "Idle" );
        model_info.animations.push_back( "ToIdle" );
        model_info.animations.push_back( "ToFire" );
*/

        MeshData data;
        data.name = "weltall";
        data.tex_width = 4096;
        data.tex_height = 256;

        ModelInfo model_info;
        model_info.data = data;
        model_info.model_file = "2145.model";
        model_info.animation_file = "2144.animation";
        model_info.animations.push_back( "Idle" );
        model_info.animations.push_back( "1" );
        model_info.animations.push_back( "2" );
        model_info.animations.push_back( "3" );
        model_info.animations.push_back( "4" );
        model_info.animations.push_back( "5" );
        model_info.animations.push_back( "6" );
        model_info.animations.push_back( "7" );
        model_info.animations.push_back( "8" );
        model_info.animations.push_back( "9" );
        model_info.animations.push_back( "10" );
        model_info.animations.push_back( "11" );
        model_info.animations.push_back( "12" );
        model_info.animations.push_back( "14" );
        model_info.animations.push_back( "15" );
        model_info.animations.push_back( "16" );
        model_info.animations.push_back( "17" );
        model_info.animations.push_back( "18" );
        model_info.animations.push_back( "19" );
        model_info.animations.push_back( "20" );
        model_info.animations.push_back( "21" );
        model_info.animations.push_back( "22" );
        model_info.animations.push_back( "23" );
        model_info.animations.push_back( "24" );
        model_info.animations.push_back( "25" );
        model_info.animations.push_back( "26" );
        model_info.animations.push_back( "27" );

        AnimatedModel model;
        Ogre::Entity* exported_entity = model.Export( model_info );

        if( exported_entity != NULL )
        {
            entitys.push_back( exported_entity );
            entitys[ 0 ]->setVisible( true );
        }
    }




    Ogre::Root::getSingleton().startRendering();



    DeinitializeOgreBase();



    return 0;
}
