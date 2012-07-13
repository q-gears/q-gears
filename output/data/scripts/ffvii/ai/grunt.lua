grunt = {
    on_start = function(self)
        return 0;
    end;

    on_action = function(self)
        if is_self_in_front_row() == true then
            if math.random(2) == 1 then
                attack_id = 278; -- Beam Gun
            else
                attack_id = 277; -- Handclaw
            end;
        else
            if math.random(12) == 1 then
                attack_id = 277; -- Handclaw
            else
                attack_id = 278; -- Beam Gun
            end;
        end;

        set_random_enemy_as_target();
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

    action_handclaw = function(self)
        fighter_self:play_animation("2");
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_beam_gun = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        fighter_self:play_animation("8");
        fighter_self:play_animation("9");

        return 0;
    end;
};
