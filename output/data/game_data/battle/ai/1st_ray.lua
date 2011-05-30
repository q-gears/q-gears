first_ray = {
    turn = true;

    on_start = function(self)
        return 0;
    end;

    on_action = function(self)
        if self.turn == true then
            set_random_enemy_as_target();
            --set_random_enemy_with_highest_current_hp_as_target();
            battle:run_command(Battle.MONSTER_ACTION, 279);
            self.turn = false;
        else
            self.turn = true;
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

    action_laser_cannon = function(self)
        fighter_self:play_animation("0");
        fighter_self:play_animation("2");
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;
};
