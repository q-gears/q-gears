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
        MeshData data;
        data.name = "weltall";
        data.tex_width = 4096;
        data.tex_height = 256;

        ModelInfo model_info;
        model_info.data = data;
        model_info.model_file = "2145.model";
        model_info.animation_file = "2144.animation";
        model_info.animations.push_back( "Idle" );
        model_info.animations.push_back( "Walk" );
        model_info.animations.push_back( "Run" );

        AnimatedModel model;
        model.Export( model_info );
    }



    Ogre::Root::getSingleton().startRendering();



    DeinitializeOgreBase();



    return 0;
}
