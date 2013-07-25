-- helper function for ai
FFVII.Battle.in_front_row = function( self )
    return self.row == FFVII.Battle.Row.FRONT
end



FFVII.Battle.get_random_enemy_as_target = function( self )
    local target = {}

    local enemy = FFVII.Battle.Type.ENEMY
    local number = EntityContainer.BattleLogic.enemy_number
    if self.unit_type == FFVII.Battle.Type.ENEMY then
        enemy = FFVII.Battle.Type.ALLY
        number = EntityContainer.BattleLogic.ally_number
    end

    local random_id = math.random( 1, number )

    local current_id = 1;
    for key, value in pairs( EntityContainer ) do
        if value.unit_type == enemy then
            if random_id == current_id then
                target[ 1 ] = key
                --print( "Set \"" .. tostring( key ) .. "\" as target." )
            end

            current_id = current_id + 1
        end
    end

    return target
end;



FFVII.Battle.add_command = function( self, target, action, attack )
    local command = {
        self = self,
        target = target,
        action = action,
        attack = attack,
    }

    -- temporary hack
    local priority = 0

    if EntityContainer.BattleLogic.command_queue[ priority ] == nil then
        EntityContainer.BattleLogic.command_queue[ priority ] = {}
    end

    table.insert( EntityContainer.BattleLogic.command_queue[ priority ], command )
end;
