FFVII.Enemies = {}



FFVII.Enemies.MP = {
    max_hp = 30,
    max_mp = 0,

    level = 2,
    physical_power = 6,
    physical_defense = 2,
    physical_dodge = 0,
    magic_power = 0,
    magic_defense = 0,
    speed = 50,
    luck = 4,

    reward_exp = 16,
    reward_ap = 2,
    reward_gil = 10,

    attacks = {
        MachineGun = {
            script_id = 3,
        },
        Tonfa = {
            script_id = 4,
        }
    },

    timer = 0,



    on_start = function( self )
        while true do
            local dir = self.entity:get_rotation()
            dir = dir + 1
            self.entity:set_rotation( dir )
            script:wait( 0 )
        end

        return 0;
    end;

    on_action = function( self )
        local attack_id;

        if is_self_in_front_row() == true then
            if (math.random(2)) == 1 then
                attack_id = 272; -- Mashingun
            else
                attack_id = 273; -- Tonfa
            end;
        else
            if (math.random(6)) == 1 then
                attack_id = 273; -- Tonfa
            else
                attack_id = 272; -- Mashingun
            end;
        end;

        set_random_enemy_as_target();
        battle:run_command(Battle.MONSTER_ACTION, attack_id);

        return 0;
    end;



    action_idle = function( self )
        fighter_self:play_animation("0");

        return 0;
    end;

    action_hurt = function(self)
        fighter_self:play_animation("1");

        return 0;
    end;

    action_machine_gun = function(self)
        fighter_self:play_animation("2");
        script:play_hurt_action(fighters_target[1], 0.27);
        fighter_self:play_animation("3");
        fighter_self:play_animation("4");
        fighter_self:play_animation("5");

        return 0;
    end;

    action_tonfa = function(self)
        fighter_self:play_animation("6");
        fighter_self:play_animation("7");
        script:play_hurt_action(fighters_target[1], 0.13);
        fighter_self:play_animation("8");
        fighter_self:play_animation("9");

        return 0;
    end;
}
