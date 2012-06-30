guard_scorpion = {
    default_defense;
    default_magic_defense;
    default_action_idle;
    default_action_hurt;
    new_defense       = 255;
    new_magic_defense = 384;
    new_action_idle   = "action_idle_stance_1";
    new_action_hurt   = "action_hurt_stance_1";

    stage = 0;
    count = 0;
    warning = false;



    on_start = function(self)
        self.default_defense       = fighter_self.data.defense;
        self.default_magic_defense = fighter_self.data.magic_defense;
        self.default_action_idle   = fighter_self.data.action_idle;
        self.default_action_hurt   = fighter_self.data.action_hurt;

        return 0;
    end;

    on_action = function(self)
        if self.count == 0 or self.count == 2 then
            set_random_enemy_as_target();
            temp_target = fighters_target;
            battle:run_command(Battle.MONSTER_ACTION, 284);
            -- DisplayText(2c4f434b4544002f4e00344152474554ff)(Locked On Target)
            self.count = self.count + 1;
        elseif self.count == 1 or self.count == 3 then
            fighters_target = temp_target;

            if math.random(3) == 1 then
                battle:run_command(Battle.MONSTER_ACTION, 283);
            else
                if fighter_self.data.current_hp < (fighter_self.data.max_hp / 2) then
                    battle:run_command(Battle.MONSTER_ACTION, 283);
                else
                    battle:run_command(Battle.MONSTER_ACTION, 282);
                end;
            end;

            self.count = self.count + 1;
        elseif self.count == 4 then
            set_self_as_target();
            battle:run_command(Battle.MONSTER_ACTION, 287);

            fighter_self.data.defense       = self.new_defense;
            fighter_self.data.macic_defense = self.new_magic_defense;
            fighter_self.data.action_idle   = self.new_action_idle;
            fighter_self.data.action_hurt   = self.new_action_hurt;

            self.stage = 1;

            if self.warning == false then
--[[
                if player1_is_dead() == false then
                    if player2_is_dead() == true then
                        --DisplayText([variableea0000]00b22954075300474f4e4e4100464952450054484154004c41534552a9b3ff)( “It's gonna fire that laser…”)
                        battle:run_command(Battle.DISPLAY_TEXT, 0);
                    else
                        --DisplayText([variableea0000]00b2[variableea0001]0c004245004341524546554c01b3ff)( “, be careful!”)
                        battle:run_command(Battle.DISPLAY_TEXT, 0);
                        --DisplayText(b221545441434b005748494c450049540753005441494c075300555001ff)(“Attack while it's tail's up!)
                        battle:run_command(Battle.DISPLAY_TEXT, 0);
                        --DisplayText(2954075300474f4e4e4100434f554e54455241545441434b005749544800495453004c415345520eb3ff)(It's gonna counterattack with its laser.”)
                        battle:run_command(Battle.DISPLAY_TEXT, 0);
                    end;
                else
                    --DisplayText([variableea0001]00b2290044554e4e4f0057484154075300474f494e07004f4e0c00425554a9ff)( “I dunno what's goin' on, but…)
                    battle:run_command(Battle.DISPLAY_TEXT, 0);
                    --DisplayText(004954004c4f4f4b5300505245545459004241440eff)( it looks pretty bad.)
                    battle:run_command(Battle.DISPLAY_TEXT, 0);
                    --DisplayText(002c4554075300534545005748415400495400444f4553005748454e0049540753005441494c0753005550a9b3ff)( Let's see what it does when it's tail's up…”)
                    battle:run_command(Battle.DISPLAY_TEXT, 0);
                end;
]]
                self.warning = true;
            end;

            self.count = self.count + 1;
        elseif self.count == 5 or self.count == 6 then
            self.count = self.count + 1;
        elseif self.count == 7 then
            set_self_as_target();
            battle:run_command(Battle.MONSTER_ACTION, 288);

            fighter_self.data.defense        = self.default_defense;
            fighter_self.data.magic_defense  = self.default_magic_defense;
            fighter_self.data.action_idle    = self.default_action_idle;
            fighter_self.data.action_hurt    = self.default_action_hurt;

            self.stage = 0;
            self.count = 0;
        end;

        return 0;
    end;



    on_counter = function(self)
        if self.stage == 1 then
            fighters_target = fighters_enemy;
            battle:run_command(Battle.MONSTER_ACTION, 286);
        end;

        return 0;
    end;



    on_death = function(self)
        if self.stage == 1 then
            set_self_as_target();
            battle:run_command(Battle.MONSTER_ACTION, 288);

            fighter_self.data.action_idle = self.default_action_idle;
            fighter_self.data.action_hurt = self.default_action_hurt;
        end;

        return 0;
    end;



    action_idle_stance_0 = function(self)
        fighter_self:play_animation("0");

        return 0;
    end;

    action_hurt_stance_0 = function(self)
        fighter_self:play_animation("1");

        return 0;
    end;

    action_idle_stance_1 = function(self)
        fighter_self:play_animation("20");

        return 0;
    end;

    action_hurt_stance_1 = function(self)
        fighter_self:play_animation("21");

        return 0;
    end;

    action_rifle_1 = function(self)
        fighter_self:play_animation("2");
        script:play_hurt_action(fighters_target[1], 0.5);
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_scorpion_tail = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        fighter_self:play_animation("8");
        script:play_hurt_action(fighters_target[1], 0.1);
        fighter_self:play_animation("9");

        return 0;
    end;

    action_search_scope = function(self)
        fighter_self:play_animation("10");
        fighter_self:play_animation("11");
        fighter_self:play_animation("12");
        fighter_self:play_animation("13");

        return 0;
    end;

    -- this is never used in real game
    action_rifle_2 = function(self)
        fighter_self:play_animation("22");
        script:play_hurt_action(fighters_target[1], 0.5);
        fighter_self:play_animation("23");
        fighter_self:play_animation("24");
        fighter_self:play_animation("25");

        return 0;
    end;

    action_tail_laser = function(self)
        fighter_self:play_animation("26");
        fighter_self:play_animation("27");
        fighter_self:play_animation("28");
        fighter_self:play_animation("29");

        return 0;
    end;

    action_go_to_stance_1 = function(self)
        fighter_self:play_animation("0");
        fighter_self:play_animation("14");
        fighter_self:play_animation("20");

        return 0;
    end;

    action_go_to_stance_0 = function(self)
        fighter_self:play_animation("20");
        fighter_self:play_animation("30");
        fighter_self:play_animation("0");

        return 0;
    end;
};
