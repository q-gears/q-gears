EntityContainer = {}



EntityContainer[ "Player" ] = {
    on_start = function( self )
        local player = entity_manager:get_entity( "Player" )
        entity_manager:set_player_entity( "Player" )

        player:set_solid_radius( 0.3 )
        player:set_solid( true )

        while true do
            local triangle_id = player:get_move_triangle_id()

            if triangle_id == 0 then
                -- remove player control
                entity_manager:unset_player_entity()
                player:set_solid( false )

                -- move to ladder
                player:move_to_position( -1, 0 )
                player:move_sync()

                -- move to up platform 1
                player:set_rotation( 180 )
                player:linear_to_position( -2, 3.5, 3, Entity.DOWN_TO_UP, "Climb" )
                player:linear_sync()

                -- tell something
--                message:show_text(1, "I runned away!", 100, 100, 130, 25);
--                script:wait(2);
--                message:hide(1);

                -- move to jump position
                player:move_to_position( -2, 6 )
                player:move_sync()

                -- jump to platform 2
                player:set_rotation( 90 )
                player:move_auto_animation( false )
                player:play_animation_stop( "Jump" )
                script:wait( 0.5 ) -- wait to start of jump in animation
                player:jump_to_position( 2, 6, 3, 0.567 ) -- triangle 24
                player:jump_sync()
                script:wait( 0.667 ) -- wait to end of animation
                player:move_auto_animation( true )

                -- move to ladder
                player:move_to_position( 2, 3.5 )
                player:move_sync()

                -- tell something
--                message:show_text(1, "I returned!", 100, 100, 130, 25)
--                script:wait(2)
--                message:hide(1)

                -- ladder down
                player:set_rotation( 180 )
                player:linear_to_position( 1, 0, 0, Entity.DOWN_TO_UP, "Climb" )
                player:linear_sync()

                -- return player control
                player:set_solid( true )
                entity_manager:set_player_entity( "Player" )
            end

            script:wait( 0.5 )
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}



EntityContainer[ "Chaser_Slow" ] = {
    on_start = function( self )
        local chaser_slow = entity_manager:get_entity( "Chaser_Slow" )
        local player = entity_manager:get_entity( "Player" )

        chaser_slow:set_move_auto_speed( 0.5 )
        chaser_slow:set_solid_radius( 0.35 )
        chaser_slow:move_auto_animation( false )

        script:wait( 1 )

        while true do
            chaser_slow:set_solid( true )
            chaser_slow:move_to_entity( player )
            chaser_slow:move_sync()
            chaser_slow:set_solid( false )
            script:wait( 5 )
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}



EntityContainer[ "Chasers_Speed1" ] = {
    on_start = function( self )
        local chaser1 = entity_manager:get_entity( "Chasers_Speed1" )
        local player = entity_manager:get_entity( "Player" )

        chaser1:set_move_auto_speed( 3 )
        chaser1:set_solid_radius( 0.15 )
        chaser1:set_solid( true )
        chaser1:move_auto_animation( false )

        script:wait( 1 )

        while true do
            chaser1:set_position( 0, 0.5, 0 )
            chaser1:move_to_entity( player )
            chaser1:move_sync()
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}



EntityContainer[ "Chasers_Speed2" ] = {
    on_start = function( self )
        local chaser2 = entity_manager:get_entity( "Chasers_Speed2" )
        local player = entity_manager:get_entity( "Player" )

        chaser2:set_move_auto_speed( 3 )
        chaser2:set_solid_radius( 0.15 )
        chaser2:set_solid( true )
        chaser2:move_auto_animation( false )

        script:wait( 1 )

        while true do
            chaser2:set_position( -1, 1, 0 )
            chaser2:move_to_entity( player )
            chaser2:move_sync()
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}



EntityContainer[ "Chasers_Speed3" ] = {
    on_start = function( self )
        local chaser3 = entity_manager:get_entity( "Chasers_Speed3" )
        local player = entity_manager:get_entity( "Player" )

        chaser3:set_move_auto_speed( 3 )
        chaser3:set_solid_radius( 0.15 )
        chaser3:set_solid( true )
        chaser3:move_auto_animation( false )

        script:wait( 1 )

        while true do
            chaser3:set_position( 1, 1, 0 )
            chaser3:move_to_entity( player )
            chaser3:move_sync()
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}



EntityContainer[ "Watcher1" ] = {
    on_start = function( self )
        local watcher1 = entity_manager:get_entity( "Watcher1" )
        local player = entity_manager:get_entity( "Player" )

        watcher1:set_move_auto_speed( 1.5 )
        watcher1:set_solid_radius( 0.3 )
        watcher1:set_solid( true )

        script:wait( 1 )

        while true do
            watcher1:turn_to_entity( player, Entity.CLOSEST, 2 )
            watcher1:turn_sync()
            script:wait( 0.5 )
            watcher1:turn_to_direction( 0, Entity.CLOSEST, Entity.SMOOTH, 2 )
            watcher1:turn_sync()
            script:wait( 1 )
            watcher1:move_to_position( 7.5, -6.5 )
            watcher1:move_sync()
            watcher1:turn_to_entity( player, Entity.CLOSEST, 2 )
            watcher1:turn_sync()
            script:wait( 0.5 )
            watcher1:turn_to_direction( 180, Entity.CLOSEST, Entity.SMOOTH, 2 )
            watcher1:turn_sync()
            script:wait( 1 )
            watcher1:move_to_position( 7.5, 1.5 )
            watcher1:move_sync()
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}



EntityContainer[ "Lifter" ] = {
    on_start = function( self )
        local lifter = entity_manager:get_entity( "Lifter" )
        lifter:set_solid( false )
        lifter:offset_to_position( 0, 0, 3, Entity.NONE, 0 )

        while true do
            script:wait( 1 )
            lifter:offset_to_position( 0, 0, 0, Entity.SMOOTH, 5 )
            lifter:offset_sync()
            script:wait( 1 )
            lifter:offset_to_position( 0, 0, 3, Entity.SMOOTH, 5 )
            lifter:offset_sync()
        end

        return 0
    end,

    on_collide = function( self )
        return 0
    end,
}
