units = {}

units.unit1 = {
    max_hp = 100,
    hp = 100,

    speed = 1,
    timer = 0,

    callback_on_start = function()
    end,

    callback_on_update = function( delta )
    end,

    ai_think = function()
        local action_item
        action_item.priority = 2

        if math.random( 2 ) == 1 then
            action_item.action = monster_attackss.Mashingun
        else
            action_item.action = monster_attackss.Tonfa
        end

        table.insert( battle.action_queue, action_item )

        return 0;
    end,
}



battle = {
    action_queue = {}



    callback_on_start = function( units )
        for i, unit in pairs( units ) do
            script:Start( unit )
        end;
    end;



    callback_on_update = function( units, delta )
        -- update timer
        for i, unit in pairs( units ) do
            unit.timer = unit.timer + unit.speed * delta

            if unit.timer >= 10 then
                script:Request( unit, "ai_think" )
                unit.timer = 0
            end;
        end;



        -- run action
        local sorting = fucntion( table1, table2 )
            return table1.priority > table2.priority
        end
        table.sort( action_queue, sorting )
        local action_item = table.remove( action_queue )

        -- do actions.
        -- action_item.action

    end;



    callback_on_finish = function()
        for i, unit in pairs( units ) do
            -- store units data to profile
        end;
    end;
}
