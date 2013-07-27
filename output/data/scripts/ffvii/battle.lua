FFVII.Battle = {}

FFVII.Battle.Action = {
    MONSTER_ACTION = 32,
}

FFVII.Battle.Row = {
    BACK = 0,
    FRONT = 1,
}

FFVII.Battle.Type = {
    ENEMY = 0,
    ALLY = 1,
    LOGIC = 2,
}

FFVII.Battle.ActionDefaults = {
    [ FFVII.Battle.Action.MONSTER_ACTION ] = { animation_script = "0" }
}

FFVII.Battle.AttackHitChance = {
    PhysicalCritical = 1, -- 0x01 upper 4 bits of formula
}

FFVII.Battle.Damage = {
    Physical = 1, -- 0x01 lower 4 bits of formula
}



FFVII.Battle.logic_script = {
    unit_type = FFVII.Battle.Type.LOGIC,

    battle_speed = 0,
    game_timer = 0,

    enemy_number = 0,
    ally_number = 0,

    command_queue = {},

    temp_data = {
        attacker = nil,             -- 0x00
                                    -- 0x04 attacker level. We don't this. Instead we use direct data from copied attacker (0x00)
                                    -- 0x10 attack index. We don't this. Instead we use direct data from copied attack (0x2c)
        target = nil,               -- 0x18
        attack = nil,               -- 0x2c
                                    -- 0x40 formula. We don't this. Instead we use direct data from copied attack (0x2c)
                                    -- 0x48 power modifier. We don't this. Instead we use direct data from copied attack (0x2c)
        base_damage = 0,            -- 0x4c
                                    -- 0xa0 upper formula. We don't this. Instead we use direct data from copied attack (0x2c)
                                    -- 0xa4 lower formula. We don't this. Instead we use direct data from copied attack (0x2c)
        calculated_defense = 0,     -- 0x210
        calculated_damage = 0,      -- 0x214
    },


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



        -- update command queue
        for key_p, value_p in pairs( self.command_queue ) do
            for key_c, value_c in pairs( value_p ) do
                FFVII.Battle.run_command( self, value_c )

                value_c.self.timer = 0

                table.remove( value_p, key_c )
            end
        end



        return 0
    end,
}



FFVII.Battle.init = function()
    EntityContainer.BattleLogic = FFVII.Battle.logic_script
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
        if value.unit_type == FFVII.Battle.Type.ALLY then
            EntityContainer.BattleLogic.ally_number = EntityContainer.BattleLogic.ally_number + 1

            party_speed = party_speed + value.dexterity
            value.speed = value.dexterity + 50
        elseif value.unit_type == FFVII.Battle.Type.ENEMY then
            EntityContainer.BattleLogic.enemy_number = EntityContainer.BattleLogic.enemy_number + 1
        end
    end

    print( "ally_number = " .. tostring( EntityContainer.BattleLogic.ally_number ) )
    print( "enemy_number = " .. tostring( EntityContainer.BattleLogic.enemy_number ) )

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



FFVII.Battle.run_command = function( self, command )
    print( "Command: attack = \"" .. command.attack.name .. "\", target = \"" .. tostring( command.target[ 1 ] ) .. "\"" )



    -- todo a lot of preparation



    EntityContainer.BattleLogic.temp_data.attacker = command.self
    EntityContainer.BattleLogic.temp_data.attack = command.attack
    EntityContainer.BattleLogic.temp_data.target = command.target



    -- todo a lot of preparation



    if command.action == FFVII.Battle.Action.MONSTER_ACTION then
        -- todo action_type_07
        -- todo action_type_0C
        FFVII.Battle.calculate_and_apply_damage()   -- action_type_09
    end
end



-- action_type_09
FFVII.Battle.calculate_and_apply_damage = function()
    -- todo mp check
    -- todo a lot of fuctions



    FFVII.Battle.set_base_damage()



    -- todo a lot of fuctions



    -- attack every unit in target
    for key, value in pairs( EntityContainer.BattleLogic.temp_data.target ) do
        FFVII.Battle.main_damage_calculation( value )
    end



    -- todo a lot of functions
end



FFVII.Battle.set_base_damage = function()
    -- todo force physical attack settings in physical formula
    -- todo use special settings for special attacks
    -- todo use another base damage for magic attack



    EntityContainer.BattleLogic.temp_data.base_damage = EntityContainer.BattleLogic.temp_data.attacker.physical_power



    -- todo apply damage modifier
end



FFVII.Battle.main_damage_calculation = function( target )
    -- todo a lot of fuctions



    FFVII.Battle.calculate_target_stats( target )



    -- todo a lot of fuctions



    FFVII.Battle.damage_formula_run()



    -- todo a lot of fuctions
end



FFVII.Battle.calculate_target_stats = function( target )
    -- todo a lot of initialization
    -- todo a lot of initialization
    -- todo defense check and modification



    EntityContainer.BattleLogic.temp_data.calculated_defense = target.physical_defense



    -- todo a lot of initialization



    if EntityContainer.BattleLogic.temp_data.calculated_defense > 512 then
        EntityContainer.BattleLogic.temp_data.calculated_defense = 512
    end



    -- todo sadness check
end



FFVII.Battle.damage_formula_run = function()
    -- run high formula
    if EntityContainer.BattleLogic.temp_data.attack.hit_chance_formula == FFVII.Battle.AttackHitChance.PhysicalCritical then
        FFVII.Battle.HighFormula.Physical()
        FFVII.Battle.HighFormula.Critical()
    end



    -- run low formula
    if EntityContainer.BattleLogic.temp_data.attack.power_modifier ~= 0 then



        -- todo add additional conditions for special attacks (A0 = 0;funca8e84;)



        if EntityContainer.BattleLogic.temp_data.attack.damage_formula == FFVII.Battle.Damage.Physical then
            FFVII.Battle.LowFormula.Physical()
        end



        -- todo add additional conditions for special attacks (A0 = 1;funca8e84;)
    end
end



FFVII.Battle.HighFormula = {}



FFVII.Battle.HighFormula.Physical = function()
    -- todo add physical hit
end



FFVII.Battle.HighFormula.Critical = function()
    -- todo add critical hit
end



FFVII.Battle.LowFormula = {}



FFVII.Battle.LowFormula.Physical = function()
    local damage = EntityContainer.BattleLogic.temp_data.base_damage
    -- calculate base damage
    damage = damage + ( ( EntityContainer.BattleLogic.temp_data.attacker.level + damage ) / 32 ) * ( ( EntityContainer.BattleLogic.temp_data.attacker.level * damage ) / 32 )
    -- apply attack data power
    damage = damage * EntityContainer.BattleLogic.temp_data.attack.power
    -- apply defense
    damage = damage * ( 512 - EntityContainer.BattleLogic.temp_data.calculated_defense ) / 512



    -- todo add always critical check
    -- todo critical damage
    -- todo berserk modificator
    -- todo back row modificator
    -- todo target defend
    -- todo attack from back
    -- todo a lot of status modifiers



    damage = FFVII.Battle.add_random_modifier_and_zero_check( damage )

    EntityContainer.BattleLogic.temp_data.calculated_damage = damage

    print( "Command: damage = \"" .. damage .. "\"." )
end



FFVII.Battle.add_random_modifier_and_zero_check = function( damage )
    local random_damage = damage * ( 15 + math.random() ) / 16;

    if random_damage == 0 then
        random_damage = 1
    end

    return random_damage
end
