// $Id$

#ifndef BATTLE_MODULE_h
#define BATTLE_MODULE_h

#include "BattleCamera.h"
#include "BattleScriptManager.h"
#include "Fighter.h"
#include "../core/Module.h"



struct RequestedBattleAction
{
    BattleActionType   type;
    Fighter*           actor;
    FighterVector      target;
    int                action_id;
};



class BattleModule : public Module
{
friend class BattleScriptManager;
friend class XmlAttackFile;
friend class XmlBattleFile;

public:
                  BattleModule(const int parameter);
    virtual      ~BattleModule(void);

    virtual void  Input(const Event& input);
    virtual void  OnStart(const float delta_time);
    virtual void  Update(const float delta_time);
    virtual void  OnFinish(const float delta_time);

    void          ScriptRunCommand(const BattleActionType action, const int action_id);

    void          SetVariableForFighter(const int fighter_id);

private:
    void          LoadBattle(const int battle_id);
    void          UnloadBattle();

    void          ExecuteLogic(const int id, const Ogre::String& function);
    void          ExecuteAction(const RequestedBattleAction& action);
    void          ExecuteDamage(Fighter* attacker, Fighter* target, const AttackData& attack);

    const int     FindAttack(const int id) const;

private:
    int                                m_BattleId;

    Ogre::Entity*                      m_Background;
    FighterVector                      m_Fighters;
    std::vector<AttackData>            m_AttacksData;

    BattleCamera*                      m_Camera;
    BattleScriptManager*               m_ScriptManager;

    std::queue<RequestedBattleAction>  m_BattleActionQueue[8];
    int                                m_BattleActionCurrentPriority;
};



#endif // BATTLE_MODULE_h
