FFVII.Battle = {}

FFVII.Battle.Type = {
    ENEMY = 0,
    ALLY = 1,
    LOGIC = 2,
}

FFVII.Battle.Row = {
    BACK = 0,
    FRONT = 1,
}



FFVII.init_battle = function()
    EntityContainer.BattleLogic = FFVII.battle_logic_script
    entity_manager:add_entity_script( "BattleLogic" )



    -- load players
    EntityContainer.Cloud = FFVII.Characters.Cloud
    entity_manager:add_entity( "Cloud", "models/ffvii/battle/units/first_ray.mesh", 0, 2, 0, 0 )



    -- init timer with start value
    EntityContainer.BattleLogic.game_timer = timer:get_game_time_total()



    -- init battle speed calculated from menu settings
    EntityContainer.BattleLogic.battle_speed = 65536 / ( ( ( FFVII.MenuSettings.battle_speed * 480 / 256 ) + 120 ) * 2 )



    local party_speed = 0
    for key, value in pairs( EntityContainer ) do
        print( tostring( key ) )
        if value.unit_type == FFVII.Battle.Type.ALLY then
            EntityContainer.BattleLogic.ally_number = EntityContainer.BattleLogic.ally_number + 1

            party_speed = party_speed + value.dexterity
            value.speed = value.dexterity + 50
        elseif value.unit_type == FFVII.Battle.Type.ENEMY then
            EntityContainer.BattleLogic.enemy_number = EntityContainer.BattleLogic.enemy_number + 1
        end
    end



    if EntityContainer.BattleLogic.ally_number > 0 then
        party_speed = ( party_speed - 1 + EntityContainer.BattleLogic.ally_number ) / EntityContainer.BattleLogic.ally_number + 50;

        for key, value in pairs( EntityContainer ) do
            if value.unit_type ~= FFVII.Battle.Type.LOGIC then
                value.battle_speed = EntityContainer.BattleLogic.battle_speed * value.speed / party_speed
                value.battle_speed = value.battle_speed * 2 -- normal speed (initial value calculated for slow)
            end
        end
    end
end



FFVII.battle_logic_script = {
    unit_type = FFVII.Battle.Type.LOGIC,

    battle_speed = 0,
    game_timer = 0,

    enemy_number = 0,
    ally_number = 0,

    target = {},



    on_update = function( self )
        local timer = timer:get_game_time_total()
        local delta = timer - self.game_timer

        -- update timers
        for key, value in pairs( EntityContainer ) do
            if value.unit_type ~= FFVII.Battle.Type.LOGIC then
                if value.timer < 65535 then
                    value.timer = value.timer + delta * 30 * value.battle_speed
                    --print( tostring( key ) .. ".timer " .. tostring( value.timer ) )

                    if value.timer > 65535 then
                        print( tostring( key ) .. " performs script \"on_action\"" )
                        script:request( Script.ENTITY, key, "on_action", 2 )
                    end
                end
            end
        end

        self.game_timer = timer

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



function set_random_ally_as_target()
    -- clear targer
    fighters_target = {};
    if table.getn(fighters_ally) ~= 0 then
        fighters_target[1] = fighters_ally[math.random(1, table.getn(fighters_ally))];
    end;
end;

]]
