guard_hound = {
    on_start = function(self)
        return 0;
    end;

    on_action = function(self)
        local attack_id;

        if math.random(3) == 1 then
            attack_id = 275; -- Tentacle
        else
            attack_id = 274; -- Bite
        end;

        set_random_enemy_as_target();
        --set_random_enemy_with_lowest_current_hp_as_target();
        battle:run_command(Battle.MONSTER_ACTION, attack_id);

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

    action_bite = function(self)
        fighter_self:play_animation("2");
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_tentacle = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        fighter_self:play_animation("8");
        fighter_self:play_animation("9");

        return 0;
    end;
};
