mono_drive = {
    prepare = false;

    on_start = function(self)
        return 0;
    end;

    on_action = function(self)
        if self.prepare == false then
            self.prepare = true;

            if math.random(2) == 1 then
                -- DisplayText(254e454d59003349474854454401ff)(Enemy Sighted!)
            else
                --DisplayText(3741524e494e4701003741524e494e4701ff)(Warning! Warning!)
            end;
        else
            if math.random(3) == 1 then
                set_random_enemy_as_target();
                --set_random_enemy_with_lowest_magic_defense_as_target();
                attack_id = 27; -- Fire
                temp14 = 1;
            else
                set_random_enemy_as_target();
                --set_random_enemy_with_lowest_defence_as_target();
                attack_id = 276; -- Drilldrive
                temp14 = 0;
            end;
--[[
            if attack_id == 27 and fighter_self.data.current_mp < game:get_attack_cost(attack_id) then
                set_random_enemy_as_target();
                --set_random_enemy_with_lowest_defence_as_target();
                attack_id = 276;
            end;
]]
            battle:run_command(Battle.MONSTER_ACTION, attack_id);
        end;

        return 0;
    end;



    action_idle = function(self)
        fighter_self:play_animation("0");

        return 0;
    end;

    action_hurt = function(self)
        fighter_self:play_animation("1");

        return 0;
    end;

    action_drilldrive = function(self)
        fighter_self:play_animation("2");
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_fire = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        fighter_self:play_animation("8");
        fighter_self:play_animation("9");

        return 0;
    end;
};
