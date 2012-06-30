first_ray = {
--[[
    <enemy
        id="20"

        level="4"

        max_hp="28"
        current_hp="28"
        max_mp="28"
        current_mp="28"

        attack="10"
        defense="1"
        magic_attack="0"
        magic_defense="0"
        speed="40"

        status_death="false"
        status_death_immunity="false"
        status_darkness="false"
        status_darkness_immunity="false"

        action_idle="action_idle"
        action_hurt="action_hurt"
    >
        <action attack_id="279" action="action_laser_cannon" />
    </enemy>
]]

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
