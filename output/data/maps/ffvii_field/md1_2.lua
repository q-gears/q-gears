EntityContainer = {}



EntityContainer[ "Background" ] = {
    on_start = function( self )
        local temp5_27 = 0;

        while true do
            if temp5_27 > 2 then
                temp5_27 = 0
            end

            local number = math.random( 0, 3 )
            if number == 0 then
                number = 1
            end

            for v = 0, number, 1 do
                background2d:play_animation( "Warning" .. temp5_27 .. "Zizizi" )
                background2d:animation_sync()
            end

            background2d:play_animation( "Warning" .. temp5_27 )
            background2d:animation_sync()

            background2d:play_animation( "WarningBlank" )
            background2d:animation_sync()

            temp5_27 = temp5_27 + 1
        end

        return 0
    end,
}



EntityContainer[ "Gateway0" ] = {
    on_start = function( self )
        return 0
    end,

    on_enter_line = function( self, entity )
        return 0
    end,

    on_move_to_line = function( self, entity )
        return 0
    end,

    on_cross_line = function( self, entity )
        if entity == "Player" then
            load_field_map_request( "ffvii_md1_1", "Spawn_md1_2" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}



EntityContainer[ "Gateway1" ] = {
    on_start = function( self )
        return 0
    end,

    on_enter_line = function( self, entity )
        return 0
    end,

    on_move_to_line = function( self, entity )
        return 0
    end,

    on_cross_line = function( self, entity )
        if entity == "Player" then
            --load_field_map_request( "", "" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}