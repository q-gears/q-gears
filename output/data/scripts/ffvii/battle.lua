load_battle_players = function()
    EntityContainer.Cloud = FFVII.Characters.Cloud

    entity_manager:add_entity( "Cloud", "models/ffvii/battle/units/first_ray.mesh", 0, 2, 0, 0 )
end



System[ "Battle" ] = {
    on_update = function( self, time )
        return 0
    end,
}

--[[
    calculate_damage = function(attacker, target, attack)
        local damage = 0;

        -- x1 type
        if attack.formula == "physical" then
            damage = attacker.data.attack;
            -- calculate base damage
            damage = damage + ((attacker.data.level + damage) / 32) * ((attacker.data.level * damage) / 32);
            -- apply attack data power
            damage = damage * attack.power;
            -- apply defense
            damage = damage * (512 - target.data.defense) / 512;
            -- random
            damage = damage * (15 + math.random()) / 16;
        -- x2 type
        elseif attack.formula == "magical" then
            damage = attacker.data.magic_attack;
            -- calculate base damage
            damage = (attacker.data.level + damage) * 6;
            -- apply attack data power
            damage = damage * attack.power;
            -- apply defense
            damage = damage * (512 - target.data.magic_defense) / 512;
            -- random
            damage = damage * (15 + math.random()) / 16;
        -- x3 type
        elseif attack.formula == "target_current%" then
            -- calculate damage as percent from current hp
            damage = target.data.current_hp * attack.power / 100;
        -- x4 type
        elseif attack.formula == "target_max%" then
            -- calculate damage as percent from current hp
            damage = target.data.max_hp * attack.power / 100;
        end;

        return damage;
    end;



function is_self_in_front_row()
    return fighter_self.data.row == 0;
end;



function is_all_enemy_in_front_row()
    if table.getn(fighters_enemy) ~= 0 then
        for i, fighter in pairs(fighters_enemy) do
            if fighter.data.row > 0 then
                return false;
            end;
        end;

        return true;
    end;

    return false;
end;



function is_all_enemy_in_back_row()
    if table.getn(fighters_enemy) ~= 0 then
        for i, fighter in pairs(fighters_enemy) do
            if fighter.data.row == 0 then
                return false;
            end;
        end;

        return true;
    end;

    return false;
end;



function is_all_ally_in_front_row()
    if table.getn(fighters_ally) ~= 0 then
        for i, fighter in pairs(fighters_ally) do
            if fighter.data.row > 0 then
                return false;
            end;
        end;

        return true;
    end;

    return false;
end;



function is_all_ally_in_back_row()
    if table.getn(fighters_ally) ~= 0 then
        for i, fighter in pairs(fighters_ally) do
            if fighter.data.row == 0 then
                return false;
            end;
        end;

        return true;
    end;

    return false;
end;



function set_self_as_target()
    -- clear targer
    fighters_target = {};
    fighters_target[1] = fighter_self;
end;



function set_random_enemy_as_target()
    -- clear targer
    fighters_target = {};
    if table.getn(fighters_enemy) ~= 0 then
        fighters_target[1] = fighters_enemy[math.random(1, table.getn(fighters_enemy))];
    end;
end;



function set_random_ally_as_target()
    -- clear targer
    fighters_target = {};
    if table.getn(fighters_ally) ~= 0 then
        fighters_target[1] = fighters_ally[math.random(1, table.getn(fighters_ally))];
    end;
end;

]]
