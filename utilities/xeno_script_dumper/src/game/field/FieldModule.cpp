// $Id: FieldModule.cpp 103 2006-11-26 07:19:38Z crazy_otaku $

#include "../../common/utilites/Logger.h"

#include "ScriptFile.h"
#include "FieldPackFile.h"
#include "FieldModule.h"



FieldModule::FieldModule()
{
    LOGGER->Log("Field module start.");
}



FieldModule::~FieldModule()
{
    LOGGER->Log("Field module stopped (%08x).", this);
}



void
FieldModule::LoadMap(const RString& name)
{
    LOGGER->Log("Start load field %s.", name.c_str());

    FieldPackFile *field_pack  = new FieldPackFile(name);
    File* temp;

    // part 0
    temp = field_pack->Extract(0);
    temp->WriteFile("0");
    delete temp;

    // part 1
    temp = field_pack->Extract(1);
    temp->WriteFile("1_walkmesh");
    delete temp;

    // part 2
    temp = field_pack->Extract(2);
    temp->WriteFile("2_3dmodel");
    delete temp;

    // part 3
    temp = field_pack->Extract(3);
    temp->WriteFile("3_2dsprite");
    delete temp;

    // part 4
    temp = field_pack->Extract(4);
    temp->WriteFile("4_2dsprite_tex");
    delete temp;

    // script
    temp = field_pack->Extract(5);
    ScriptFile* script_file = new ScriptFile(temp);
    temp->WriteFile("5_script");
    delete temp;
    script_file->GetScripts();
    delete script_file;

    // part 6
    temp = field_pack->Extract(6);
    temp->WriteFile("6");
    delete temp;

    // part 7
    temp = field_pack->Extract(7);
    temp->WriteFile("7_dialogs");
    delete temp;

    // part 8
    temp = field_pack->Extract(8);
    temp->WriteFile("8");
    delete temp;


    delete field_pack;
}
