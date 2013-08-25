#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "EnemyFile.h"
#include "PlayerFile.h"



int
main( int argc, char *argv[] )
{
    InitializeOgreBase( "FFVII Battle Scene Exporter" );



    EnemyFile* enemy = new EnemyFile( "./data/scene82" );
    delete enemy;

    //PlayerFile* player = new PlayerFile( "player_ai" );
    //delete player;



    DeinitializeOgreBase();

    return 0;
}
