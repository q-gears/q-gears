sweeper = {
    count = math.random(3);

    on_start = function(self)
        return 0;
    end;

    on_action = function(self)
        local action_id;

        if self.count == 0 then
            if true then
            --if is_all_enemy_in_darkness_status() == false then
                set_random_enemy_as_target();
                --set_random_enemy_without_darkness_status_as_target();
            else
                set_random_enemy_as_target();
            end;

            action_id = 281; -- Smoke Shot
            self.count = 1;
        elseif self.count == 1 then
            set_random_enemy_as_target();
            --set_random_enemy_with_highest_current_hp_as_target();
            action_id = 272; -- Machine Gun
            self.count = 2;
        else
            set_random_enemy_as_target();
            --set_random_enemy_with_highest_current_hp_as_target();
            action_id = 280; -- W Machine Gun
            self.count = 0;
        end;

        battle:run_command(Battle.MONSTER_ACTION, action_id);

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

    action_machine_gun = function(self)
        fighter_self:play_animation("2");
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_w_machine_gun = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        fighter_self:play_animation("8");
        fighter_self:play_animation("9");

        return 0;
    end;

    action_smoke_shot = function(self)
        fighter_self:play_animation("10");
        fighter_self:play_animation("11");
        fighter_self:play_animation("12");
        fighter_self:play_animation("13");

        return 0;
    end;
};
