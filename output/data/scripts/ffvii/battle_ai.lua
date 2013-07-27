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
                target[ 1 ] = value
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




--[[
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
