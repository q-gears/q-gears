// $Id$

#include <OgreLogManager.h>

#include "FieldModule.h"
#include "XmlBackground2DFile.h"
#include "XmlFieldMapFile.h"
#include "XmlWalkmeshFile.h"
#include "../core/Configuration.h"
#include "../core/TextManager.h"



XmlFieldMapFile::XmlFieldMapFile(const Ogre::String& file):
    XmlFile(file)
{
    if (m_File != NULL)
    {
        m_RootNode = xmlDocGetRootElement(m_File);

        if (m_RootNode == NULL || xmlStrEqual(m_RootNode->name, BAD_CAST "map") == false)
        {
            m_NormalFile = false;
            Ogre::LogManager::getSingletonPtr()->logMessage("Field Map XML Manager: " + file + " is not a valid field map file! No <map> in root.");
        }
        else
        {
            m_NormalFile = true;
        }
    }
    else
    {
        m_NormalFile = false;
    }
}



XmlFieldMapFile::~XmlFieldMapFile()
{
}



void
XmlFieldMapFile::LoadMap(FieldModule* field_module)
{
    if (m_NormalFile != true)
    {
        return;
    }

    for (xmlNodePtr node = m_RootNode->xmlChildrenNode; node != NULL; node = node->next)
    {
        if (xmlStrEqual(node->name, BAD_CAST "walkmesh"))
        {
            Ogre::String name = GetString(node, "file_name");
            if (name != "")
            {
                XmlWalkmeshFile walkmesh_file(Configuration::getSingleton().GetFileRoot() + name);
                walkmesh_file.Load(field_module->m_Walkmesh);
                field_module->m_Walkmesh->SetUpWalkmesh();
                Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getSceneNode("FieldModule")->createChildSceneNode("WalkMesh");
                node->attachObject(field_module->m_Walkmesh);
            }
        }
        else if (xmlStrEqual(node->name, BAD_CAST "camera"))
        {
            field_module->m_Camera->Set2_5DMatrixes(GetMatrix4(node, "view_matrix"), GetMatrix4(node, "projection_matrix"));
        }
        else if (xmlStrEqual(node->name, BAD_CAST "movement_rotation"))
        {
            field_module->m_MovementRotation = Ogre::Radian(Ogre::Degree(GetFloat(node, "angle")));
        }
        else if (xmlStrEqual(node->name, BAD_CAST "script"))
        {
            Ogre::String name = GetString(node, "file_name");
            if (name != "")
            {
                field_module->m_FieldScriptManager->LoadFile(name);
            }
        }
        else if (xmlStrEqual(node->name, BAD_CAST "texts"))
        {
            for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
            {
                if (xmlStrEqual(node2->name, BAD_CAST "dialog"))
                {
                    g_TextManager->LoadTexts(GetString(node2, "file_name"));
                }
            }
        }
        else if (xmlStrEqual(node->name, BAD_CAST "line_triggers"))
        {
            for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
            {
                if (xmlStrEqual(node2->name, BAD_CAST "line_trigger"))
                {
                    Ogre::SceneNode* scene_node = Ogre::Root::getSingleton().getSceneManager("Scene")->getSceneNode("FieldModule")->createChildSceneNode("LineTrigger" + Ogre::StringConverter::toString(field_module->m_LineTriggers.size()));
                    LineTrigger* line = new LineTrigger(GetString(node2, "name"), scene_node, GetVector3(node2, "point1"), GetVector3(node2, "point2"));
                    line->SetEnabled(GetBool(node2, "enabled"));
                    field_module->m_LineTriggers.push_back(line);
                }
            }
        }
        else if (xmlStrEqual(node->name, BAD_CAST "encounters"))
        {
            for (xmlNodePtr node2 = node->xmlChildrenNode; node2 != NULL; node2 = node2->next)
            {
                if (xmlStrEqual(node2->name, BAD_CAST "table"))
                {
                    FieldModule::EncounterTable table;
                    table.rate = GetFloat(node2, "rate");

                    for (xmlNodePtr node3 = node2->xmlChildrenNode; node3 != NULL; node3 = node3->next)
                    {
                        if (xmlStrEqual(node3->name, BAD_CAST "encounter"))
                        {
                            FieldModule::Encounter encounter;
                            encounter.percentage = GetInt(node3, "percentage");
                            encounter.battle_id = GetInt(node3, "battle_id");
                            table.encounter.push_back(encounter);
                        }
                    }

                    field_module->m_Encounters.push_back(table);
                }
            }
        }
    }
}
