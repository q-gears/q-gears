EntityContainer = {}



EntityContainer[ "Cloud" ] = {
    on_start = function( self )
        local cloud = entity_manager:get_entity( "Cloud" )
        cloud:move_to_position( 1, 1 )
        cloud:move_sync()

        return 0
    end,

    animation1 = function( self )
        local i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 2 do
            cloud:play_animation( "TalkNo" )
            i = i + 1
            cloud:animation_sync()
        end

        --load_field_map_request( "test_ffvii_2" )

        return 0
    end,
}



EntityContainer[ "Robo" ] = {
    on_start = function( self )
        local robo = entity_manager:get_entity( "Robo" )
        script:wait( 5 )
        robo:move_auto_animation( false )
        robo:play_animation_stop( "ToFire" )

        return 0
    end,
}



EntityContainer[ "Weltall" ] = {
    on_start = function( self )
        local robo = entity_manager:get_entity( "Weltall" )
        script:wait( 5 )
        robo:move_auto_animation( false )
        robo:play_animation_stop( "9" )

        return 0
    end,
}



EntityContainer[ "Player" ] = {
    on_start = function( self )
        local player = entity_manager:get_entity( "Player" )
        player:set_solid( true )
        entity_manager:set_player_entity( "Player" )

        local point = entity_manager:get_entity_point( "Spawn" )
        if point ~= nil then
            local x, y, z = point:get_point()
            player:set_position( x, y, z )
        end

        return 0
    end,
}



EntityContainer[ "Trigger" ] = {
    on_start = function( self )
        return 0
    end,

    on_enter_line = function( self, entity )
        print( "on_enter_line " .. entity )
        return 0
    end,

    on_move_to_line = function( self, entity )
        print( "on_move_to_line " .. entity )
        return 0
    end,

    on_cross_line = function( self, entity )
        print( "on_cross_line " .. entity )
        load_field_map_request( "ffvii_md1stin", 29.0547, 229.234, 0.273438, 67.7647 )
        return 0
    end,

    on_leave_line = function( self, entity )
        print( "on_leave_line " .. entity )
        return 0
    end,
}



EntityContainer[ "Manager" ] = {
    on_start = function( self )
        script:request( "EntityContainer.Cloud", "animation1", 1 )

        return 0
    end,
}