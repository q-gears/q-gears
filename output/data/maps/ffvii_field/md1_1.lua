EntityContainer = {}



EntityContainer[ "Background" ] = {
    on_start = function( self )
        while true do
            background2d:play_animation( "Fan" )
            background2d:animation_sync()
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
            load_field_map_request( "ffvii_md1stin", "Spawn_md1_1" )
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
            load_field_map_request( "ffvii_md1_2", "Spawn_md1_1" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}
