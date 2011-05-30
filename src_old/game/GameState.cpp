// $Id$

#include <OgreLogManager.h>
#include <OgreOverlayManager.h>
#include <OgreStringConverter.h>

#include "GameState.h"
#include "XmlCharacterFile.h"
#include "../main.h"
#include "../core/Configuration.h"



GameState* g_GameState = NULL; // global and accessable from anywhere in our program



GameState::GameState(void):
    m_PlayerCharacterPosition(0, 0, 0),
    m_PlayerCharacterDirection(0)
{
    // debug party info
    m_DebugPartyText = new TextArea("DebugPartyText");
    m_DebugPartyText->setCaption("");
    m_DebugPartyText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugPartyText->setPosition(5, 5);
    m_DebugPartyText->setTextAlignment(TextArea::LEFT);
    m_DebugPartyText->setFontName("DebugText");
    m_DebugPartyText->setCharHeight(18);

    m_DebugPartyOverlay = Ogre::OverlayManager::getSingleton().create("DebugPartyOverlay");
    m_DebugPartyOverlay->setZOrder(QGOO_GAMESTATE_DEBUG);
    m_DebugPartyOverlay->add2D((Ogre::OverlayContainer*)m_DebugPartyText);
    if (Configuration::getSingleton().GetOptionBool("debug_game_party") == true)
    {
        m_DebugPartyOverlay->show();
    }
    else
    {
        m_DebugPartyOverlay->hide();
    }

    // debug items info
    m_DebugItemsText = new TextArea("DebugItemsText");
    m_DebugItemsText->setCaption("");
    m_DebugItemsText->setMetricsMode(Ogre::GMM_PIXELS);
    m_DebugItemsText->setPosition(5, 5);
    m_DebugItemsText->setTextAlignment(TextArea::LEFT);
    m_DebugItemsText->setFontName("DebugText");
    m_DebugItemsText->setCharHeight(18);

    m_DebugItemsOverlay = Ogre::OverlayManager::getSingleton().create("DebugItemsOverlay");
    m_DebugItemsOverlay->setZOrder(QGOO_GAMESTATE_DEBUG);
    m_DebugItemsOverlay->add2D((Ogre::OverlayContainer*)m_DebugItemsText);
    if (Configuration::getSingleton().GetOptionBool("debug_game_items") == true)
    {
        m_DebugItemsOverlay->show();
    }
    else
    {
        m_DebugItemsOverlay->hide();
    }



    XmlCharacterFile file(Configuration::getSingleton().GetFileRoot() + "database/character.xml");
    file.GetCharacters(m_Characters);



    m_Party.clear();
    m_Party.resize(3);



    Ogre::LogManager::getSingletonPtr()->logMessage("GameState created.");
}



GameState::~GameState(void)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("GameState destroyed.");
}


void
GameState::Input(const Event& input)
{
    bool debug = false;
    if (input.name == "debug_game_party" ||
        input.name == "debug_game_items")
    {
        if (input.value.size() >= 1)
        {
            debug = Ogre::StringConverter::parseBool(input.value[0]);
        }
        else
        {
            debug = Configuration::getSingleton().GetOptionBool(input.name);
            debug = (debug == true) ? false : true;
        }

        Configuration::getSingleton().SetOption(input.name, debug);
    }

    if (input.name == "debug_game_party")
    {
        if (debug == true)
        {
            m_DebugPartyOverlay->show();
        }
        else
        {
            m_DebugPartyOverlay->hide();
        }
    }
    else if (input.name == "debug_game_items")
    {
        if (debug == true)
        {
            m_DebugItemsOverlay->show();
        }
        else
        {
            m_DebugItemsOverlay->hide();
        }
    }
}



void
GameState::Update(const float delta_time)
{
    // party debug
    if (m_DebugPartyOverlay->isVisible() == true)
    {
        Ogre::String caption = "Party debug:";

        for (int i = 0; i < m_Party.size(); ++i)
        {
            caption += " " + Ogre::StringConverter::toString(i);

            if (m_Party[i].character_id == -1)
            {
                caption += "[none]";
            }
            else
            {
                int id = FindCharacter(m_Party[i].character_id);
                if (id != -1)
                {
                    caption += "[id" + Ogre::StringConverter::toString(m_Party[i].character_id) + " " + m_Characters[id].name + "]";
                }
                else
                {
                    caption += "[invalid character id " + Ogre::StringConverter::toString(m_Party[i].character_id) + "]";
                }
            }
        }

        for (int i = 0; i < m_Characters.size(); ++i)
        {
            caption += "\nCharacter: " + m_Characters[i].name;
        }

        m_DebugPartyText->setCaption(caption);
    }



    // items debug
    if (m_DebugItemsOverlay->isVisible() == true)
    {
        Ogre::String caption = "Items debug:\n";

        for (int i = 0; i < m_Items.size(); ++i)
        {
            caption += "Id: " + Ogre::StringConverter::toString(m_Items[i].first) + " amount: " + Ogre::StringConverter::toString(m_Items[i].second) + "\n";
        }

        m_DebugItemsText->setCaption(caption);
    }
}



void
GameState::ScriptVariableSet(const char* name, const int value)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:variable_set: set variable with name '" + Ogre::String(name) + "' to value '" + Ogre::StringConverter::toString(value) + "'.");
    SetVariable(name, value);
}



const int
GameState::ScriptVariableGet(const char* name)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:variable_get: get variable with name '" + Ogre::String(name) + "'.");
    return GetVariable(name);
}



void
GameState::ScriptItemAdd(const int item_id, const int quantity)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:item_add: add or remove item with id '" + Ogre::StringConverter::toString(item_id) + "' with amount of '" + Ogre::StringConverter::toString(quantity) + "'.");
    ItemAdd(item_id, quantity);
}



const int
GameState::ScriptItemGet(const int item_id) const
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:item_get_quantity: get amount of item with id '" + Ogre::StringConverter::toString(item_id) + "'.");
    return ItemGet(item_id);
}



void
GameState::ScriptPartySetSize(const int size)
{
    if (size > 0)
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:party_set_size: size set to '" + Ogre::StringConverter::toString(size) + "'.");
        m_Party.resize(size);
    }
    else
    {
        Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT ERROR] game:party_set_size: wrong size '" + Ogre::StringConverter::toString(size) + "'.");
    }
}



void
GameState::ScriptPartyClear()
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:party_clear: remove all characters from party.");

    for (int i = 0; i < m_Party.size(); ++i)
    {
        m_Party[i].character_id = -1;
    }
}



void
GameState::ScriptCharacterAddToParty(const int character_id)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] game:character_add_to_party: character with id '" + Ogre::StringConverter::toString(character_id) + "' added to party.");
    CharacterAddToParty(character_id);
}



void
GameState::ScriptCharacterRemoveFromParty(const int character_id)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("[SCRIPT] character_remove_from_party: character with id '" + Ogre::StringConverter::toString(character_id) + "' removed from party.");
    CharacterRemoveFromParty(character_id);
}



void
GameState::SetVariable(const Ogre::String& name, const int value)
{
    m_Variable[name] = value;
}



const int
GameState::GetVariable(const Ogre::String& name)
{
    return m_Variable[name];
}



void
GameState::ItemAdd(const int item_id, const int quantity)
{
    int slot_id = FindItem(item_id);

    if (slot_id == -1)
    {
        m_Items.push_back(std::make_pair(item_id, quantity));
    }
    else
    {
        m_Items[slot_id].second += quantity;

        m_Items[slot_id].second = (m_Items[slot_id].second > 99) ? 99 : m_Items[slot_id].second;
        m_Items[slot_id].second = (m_Items[slot_id].second <  0) ?  0 : m_Items[slot_id].second;
    }
}



const int
GameState::ItemGet(const int item_id) const
{
    int slot_id = FindItem(item_id);

    if (slot_id == -1)
    {
        return 0;
    }
    else
    {
        return m_Items[slot_id].second;
    }
}



const Character
GameState::CharacterGet(const int character_id)
{
    int id = FindCharacter(character_id);
    if (id == -1)
    {
        return Character();
    }

    return m_Characters[id];
}



void
GameState::CharacterSet(const Character& character, const int character_id)
{
    int id = FindCharacter(character_id);
    if (id != -1)
    {
        m_Characters[id] = character;
    }
}



void
GameState::CharacterAddToParty(const int character_id)
{
    int id = FindCharacter(character_id);
    if (id != -1)
    {
        for (int i = 0; i < m_Party.size(); ++i)
        {
            if (m_Party[i].character_id == character_id)
            {
                return;
            }
        }

        for (int i = 0; i < m_Party.size(); ++i)
        {
            if (m_Party[i].character_id == -1)
            {
                SetCharacterLock(character_id, false);
                m_Party[i].character_id = character_id;
                return;
            }
        }

        SetCharacterLock(character_id, false);
        m_Party[m_Party.size() - 1].character_id = character_id;
    }
}



void
GameState::CharacterRemoveFromParty(const int character_id)
{
    for (int i = 0; i < m_Party.size(); ++i)
    {
        if (m_Party[i].character_id == character_id)
        {
            m_Party[i].character_id = -1;
            return;
        }
    }
}



int
GameState::PartyGetSize() const
{
    return m_Party.size();
}



const int
GameState::GetPartyCharacter(const int party_slot_id) const
{
    if (this->CheckParty(party_slot_id) == false)
    {
        return -1;
    }

    return m_Party[party_slot_id].character_id;
}



void
GameState::SetCharacterLock(const int character_id, const bool locked)
{
    int id = FindCharacter(character_id);
    if (id == -1)
    {
        return;
    }

    m_Characters[id].locked = locked;
}



void
GameState::SetPlayerCharacterPosition(const Ogre::Vector3& position)
{
    m_PlayerCharacterPosition = position;
}



const Ogre::Vector3
GameState::GetPlayerCharacterPosition() const
{
    return m_PlayerCharacterPosition;
}



void
GameState::SetPlayerCharacterDirection(const Ogre::Degree& direction)
{
    m_PlayerCharacterDirection = direction;
}



const Ogre::Degree
GameState::GetPlayerCharacterDirection() const
{
    return m_PlayerCharacterDirection;
}



const int
GameState::FindItem(const int item_id) const
{
    for (int i = 0; i < m_Items.size(); ++i)
    {
        if (m_Items[i].first == item_id)
        {
            return i;
        }
    }

    return -1;
}



const int
GameState::FindCharacter(const int character_id) const
{
    for (int i = 0; i < m_Characters.size(); ++i)
    {
        if (m_Characters[i].id == character_id)
        {
            return i;
        }
    }

    Ogre::LogManager::getSingletonPtr()->logMessage("[ERROR] GameState::FindCharacter: character with id " + Ogre::StringConverter::toString(character_id) + " doesn't exist.");
    return -1;
}



const bool
GameState::CheckParty(const int party_id) const
{
    return !(party_id >= m_Party.size() || party_id < 0);
}
