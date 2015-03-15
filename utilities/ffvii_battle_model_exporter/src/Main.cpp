#include <Ogre.h>
#include "../../common/OgreBase.h"
#include "../../common/Logger.h"

#include "EnemyFile.h"
#include "RamEffectFile.h"
#include "StageFile.h"


std::vector<EnemyInfo> models_all;
std::vector<EffectInfo> effects_all;
std::vector<StageInfo> stages_all;



void
fill_names()
{
    EnemyInfo info;

    Ogre::ConfigFile cf;
    cf.load("export_models.cfg");
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        if (names != "")
        {
            Ogre::StringVector name = Ogre::StringUtil::split(names, ":", 3);
            if (name.size() < 3)
            {
                LOGGER->Log("In '" + names + "' not enough names. Must be 3.\n");
                continue;
            }
            info.file_name = name[0];
            info.data.name = name[1];

            Ogre::StringVector tex_size = Ogre::StringUtil::split(name[2], "x", 2);
            info.data.tex_width = Ogre::StringConverter::parseInt(tex_size[0]);
            info.data.tex_height = Ogre::StringConverter::parseInt(tex_size[1]);

            if (info.file_name != "")
            {
                Ogre::ConfigFile::SettingsMultiMap::iterator i;
                for (i = settings->begin(); i != settings->end(); ++i)
                {
                    info.animations.push_back(i->second);
                    LOGGER->Log("Animation add:" + info.file_name + " " + i->second + "\n");
                }

                models_all.push_back(info);
                info.animations.clear();
            }
        }
    }



    EffectInfo effect;
    cf.load("export_effects.cfg");
    seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        if (names == "")
        {
            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                effect.data.name = i->second;
                effect.data.tex_width = 256;
                effect.data.tex_height = 256;
                effect.offset = Ogre::StringConverter::parseInt(i->first);

                LOGGER->Log("Effect: " + i->second + ": " + i->first);

                effects_all.push_back(effect);
            }
        }
    }



    StageInfo stage;
    cf.load("export_stages.cfg");
    seci = cf.getSectionIterator();

    while (seci.hasMoreElements())
    {
        Ogre::String names = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        if (names == "")
        {
            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                stage.file_name = i->first;

                Ogre::StringVector name = Ogre::StringUtil::split(i->second, ":", 2);
                if (name.size() < 2)
                {
                    LOGGER->Log("In '" + names + "' not enough names. Must be 2.\n");
                    continue;
                }

                stage.data.name = name[0];

                Ogre::StringVector tex_size = Ogre::StringUtil::split(name[1], "x", 2);
                stage.data.tex_width = Ogre::StringConverter::parseInt(tex_size[0]);
                stage.data.tex_height = Ogre::StringConverter::parseInt(tex_size[1]);

                LOGGER->Log("Stage: " + i->first + ": " + i->second + "\n");

                stages_all.push_back(stage);
            }
        }
    }


    LOGGER->Log("Initialize export list finished.\n\n\n\n");
}

int
main(int argc, char *argv[])
{
    InitializeOgreBase( "FFVII Battle Model Exporter" );



    fill_names();




    for (size_t i = 0; i < models_all.size(); ++i)
    {
        EnemyFile model("data/" + models_all[i].file_name + ".LZS");

        //model.WriteFile(models_all[i].file_name + "_u.LZS");
        Ogre::Entity* exported_entity = model.GetModel(models_all[i]);

        if (exported_entity != NULL)
        {
            entitys.push_back(exported_entity);
        }
    }

    for (size_t i = 0; i < effects_all.size(); ++i)
    {
        RamEffectFile effect("data/ram.bin");
        Ogre::Entity* exported_entity = effect.GetModel(effects_all[i]);
        if (exported_entity != NULL)
        {
            entitys.push_back(exported_entity);
        }
    }

    for (size_t i = 0; i < stages_all.size(); ++i)
    {
        StageFile model("data/" + stages_all[i].file_name + ".LZS");

        //model.WriteFile(models_all[i].file_name + "_u.LZS");
        Ogre::Entity* exported_entity = model.GetModel(stages_all[i]);

        if (exported_entity != NULL)
        {
            entitys.push_back(exported_entity);
        }
    }

    entitys[ 0 ]->setVisible(true);



    Ogre::Root::getSingleton().startRendering();



    DeinitializeOgreBase();



    return 0;
}
