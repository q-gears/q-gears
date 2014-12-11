// $Id: Main.cpp 147 2007-02-24 06:13:17Z super_gb $

#include "Define.h"
#include "GameDefine.h"
#include "Main.h"
#include "common/filesystem/RealFileSystem.h"
#include "common/utilites/Logger.h"

#include "game/field/FieldModule.h"



int
main(int argc, char *argv[])
{
    REALFILESYSTEM   = new RealFileSystem();
    LOGGER           = new Logger(DEFAULT_LOG);



    LOGGER->Log("===================== Start Dump!!!");

    FieldModule* field = new FieldModule();
    //field->LoadMap("data/0614");
    field->LoadMap("data/0632");
    delete field;

    LOGGER->Log("===================== Stop Dump!!!");




    delete LOGGER;
    delete REALFILESYSTEM;

    return 0;
}
