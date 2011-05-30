// $Id$

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../core/Actor.h"
#include "../core/ui/TextArea.h"



struct CharacterData
{
    void Copy(const CharacterData& data)
    {
        id                       = data.id;
        name                     = data.name;

        level                    = data.level;

        max_hp                   = data.max_hp;
        current_hp               = data.current_hp;
        max_mp                   = data.max_mp;
        current_mp               = data.current_mp;

        attack                   = data.attack;
        defense                  = data.defense;
        magic_attack             = data.magic_attack;
        magic_defense            = data.magic_defense;
        speed                    = data.speed;

        status_death             = data.status_death;
        status_death_immunity    = data.status_death_immunity;
        status_darkness          = data.status_darkness;
        status_darkness_immunity = data.status_darkness_immunity;

        row                      = data.row;
    };

    int                 id;
    Ogre::String        name;

    int                 level;

    int                 max_hp;
    int                 current_hp;
    int                 max_mp;
    int                 current_mp;

    int                 attack;
    int                 defense;
    int                 magic_attack;
    int                 magic_defense;
    int                 speed;

    bool                status_death;
    bool                status_death_immunity;
    bool                status_darkness;
    bool                status_darkness_immunity;

    int                 row;
};



struct Character : public CharacterData
{
    bool         available;
    bool         locked;
};



struct PartySlot
{
    PartySlot(void):
        character_id(-1)
    {
    }

    int character_id;
};



class GameState : public Actor
{
public:
                        GameState();
    virtual            ~GameState();

    void                Input(const Event& input);
    void                Update(const float delta_time);

    // functions for script access
    void                ScriptVariableSet(const char* name, const int value);
    const int           ScriptVariableGet(const char* name);
    void                ScriptItemAdd(const int item_id, const int quantity);
    const int           ScriptItemGet(const int item_id) const;
    void                ScriptPartySetSize(const int size);
    void                ScriptPartyClear();
    void                ScriptCharacterAddToParty(const int character_id);
    void                ScriptCharacterRemoveFromParty(const int character_id);

    // variable to store
    void                SetVariable(const Ogre::String& name, const int value);
    const int           GetVariable(const Ogre::String& name);

    // items
    void                ItemAdd(const int item_id, const int quantity);
    const int           ItemGet(const int item_id) const;

    // party and character
    const Character     CharacterGet(const int character_id);
    void                CharacterSet(const Character& character, const int character_id);
    void                CharacterAddToParty(const int character_id);
    void                CharacterRemoveFromParty(const int character_id);
    int                 PartyGetSize() const;
    const int           GetPartyCharacter(const int party_slot_id) const;

    void                SetCharacterLock(const int character_id, const bool locked);

    void                SetPlayerCharacterPosition(const Ogre::Vector3& position);
    const Ogre::Vector3 GetPlayerCharacterPosition() const;
    void                SetPlayerCharacterDirection(const Ogre::Degree& direction);
    const Ogre::Degree  GetPlayerCharacterDirection() const;

private:
    const int           FindItem(const int item_id) const;
    const int           FindCharacter(const int character_id) const;
    const bool          CheckParty(const int party_id) const;

private:
    TextArea*                         m_DebugPartyText;
    Ogre::Overlay*                    m_DebugPartyOverlay;
    TextArea*                         m_DebugItemsText;
    Ogre::Overlay*                    m_DebugItemsOverlay;

    std::map<Ogre::String, int>       m_Variable;

    std::vector<Character>            m_Characters;
    std::vector<PartySlot>            m_Party;

    int                               m_Money;
    std::vector<std::pair<int, int> > m_Items;

    Ogre::Vector3                     m_PlayerCharacterPosition;
    Ogre::Degree                      m_PlayerCharacterDirection;
};



// Visible from every part of program
extern GameState* g_GameState;



#endif // GAMESTATE_H
