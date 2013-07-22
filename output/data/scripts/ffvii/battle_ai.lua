-- helper function for ai
FFVII.Battle.in_front_row = function( self )
    return self.row == FFVII.Battle.Row.FRONT;
end;



FFVII.Battle.set_random_enemy_as_target = function()
    EntityContainer.BattleLogic.target = {}

    local random_id = math.random( 1, EntityContainer.BattleLogic.enemy_number )

    local current_id = 1;
    for key, value in pairs( EntityContainer ) do
        if value.unit_type == FFVII.Battle.Type.ENEMY then
            if random_id == current_id then
                EntityContainer.BattleLogic.target[ 1 ] = key
                print( "Set \"" .. tostring( key ) .. "\" as target." )
            end

            current_id = current_id + 1
        end
    end
end;
