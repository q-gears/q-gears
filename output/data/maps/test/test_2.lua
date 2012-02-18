--[[
-- message conf
message:set_clickable(1, false);
]]



EntityContainer = {}



EntityContainer[ "Player" ] = {
    on_start = function(self)
        local player = entity_manager:get_entity( "Player" )
        entity_manager:set_player_entity( "Player" )

        player:set_solid_radius( 0.3 )
        player:set_solid( true )

--[[
        while true do
            local triangle_id = player:get_triangle();
            if triangle_id == 0 then
                field:pc_lock(true);
                -- move to ladder
                player:move_to_position(-100, 0, true);
                -- move to up platform 1
                player:set_direction(0);
                player:set_animation_default("6", 1);
                player:climb_to_position(-200, 350, 300, 23, Entity.DOWN_TO_UP);
                player:set_animation_default("0", 1);
                -- tell something
                message:show_text(1, "I runned away!", 100, 100, 130, 25);
                script:wait(2);
                message:hide(1);
                -- move to jump position
                player:move_to_position(-200, 600, true);
                -- jump to platform 2
                player:set_direction(90);
                player:set_animation_default("5", 1);
                script:wait(0.5);
                player:jump_to_position(200, 600, 24, 0.567);
                script:wait(0.667);
                player:set_animation_default("0", 1);
                -- move to ladder
                player:move_to_position(200, 350, true);
                -- tell something
                message:show_text(1, "I returned!", 100, 100, 130, 25);
                script:wait(2);
                message:hide(1);
                -- ladder down
                player:set_direction(0);
                player:set_animation_default("6", 1);
                player:climb_to_position(100, 0, 0, 4, Entity.DOWN_TO_UP);
                -- return player control
                field:pc_lock(false);
            end;

            script:wait(0.5);
        end;
]]
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

        chaser_slow:set_move_speed( 0.5 )
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

        chaser1:set_move_speed( 5 );
        chaser1:set_solid_radius( 0.15 );
        chaser1:set_solid( true );

        script:wait( 1 )

        while true do
            --chaser1:set_position_triangle( 100, 100, 0, 1 )
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

        chaser2:set_move_speed( 5 );
        chaser2:set_solid_radius( 0.15 );
        chaser2:set_solid( true );

        script:wait( 1 )

        while true do
            --chaser2:set_position_triangle( 100, 100, 0, 1 )
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

        chaser3:set_move_speed( 5 );
        chaser3:set_solid_radius( 0.15 );
        chaser3:set_solid( true );

        script:wait( 1 )

        while true do
            --chaser3:set_position_triangle( 100, 100, 0, 1 )
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

        watcher1:set_move_speed( 1.5 )
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
        lifter:offset_to_position( 0, 0, 3, Entity.NONE, 0 );

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
