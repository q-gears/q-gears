#include <iostream>
#include "../../common/FileSystem.h"
#include "../../common/Logger.h"
#include "EnemyFile.h"
#include "PlayerFile.h"



int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " scene_file" << std::endl;
        exit(EXIT_FAILURE);
    }

    FILESYSTEM = new FileSystem();
    LOGGER = new Logger("game.log");



    EnemyFile* enemy = new EnemyFile(argv[1]);
    delete enemy;

    PlayerFile* player = new PlayerFile("player_ai");
    delete player;


    delete FILESYSTEM;
    delete LOGGER;

    return 0;
}
