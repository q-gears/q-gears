#include "../../common/FileSystem.h"
#include "../../common/Logger.h"

#include "ScriptFile.h"
#include "TextFile.h"



int
main(int argc, char *argv[])
{
    FILESYSTEM = new FileSystem();
    LOGGER = new Logger("game.log");

    TextFile* text_file = new TextFile("data/1.text");
    text_file->DumpTexts();
    delete text_file;

    ScriptFile* script_file = new ScriptFile("data/1.script");
    script_file->DumpScripts();
    delete script_file;

    delete LOGGER;
    delete FILESYSTEM;

    return 0;
}
