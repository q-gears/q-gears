barret = {
    on_start = function(self)
        fighter_self.data.auto_action = true;

        return 0;
    end;

    on_action = function(self)
        set_random_enemy_as_target();
        battle:run_command(Battle.MONSTER_ACTION, 1000);

        return 0;
    end;



    action_idle = function(self)
        fighter_self:play_animation("0");

        return 0;
    end;
};
