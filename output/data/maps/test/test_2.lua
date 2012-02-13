--[[

-- player
player = field:load_model("Player", 5806);
field:set_player_entity(player);
player:set_position_triangle(0, -100, 0, 1);
player:set_visible(true);
player:set_solid(true);
player:set_speed(300);
player:set_solid_range(30);

-- chaser slow
chaser_slow = field:load_model("Chaser_Slow", 30);
chaser_slow:set_position_triangle(0, -50, 0, 1);
chaser_slow:set_speed(50);
chaser_slow:set_solid_range(35);
chaser_slow:set_visible(true);

-- chaser1
chaser1 = field:load_model("Chasers_Speed1", 40);
chaser1:set_position_triangle(0, 50, 0, 1);
chaser1:set_speed(500);
chaser1:set_solid_range(15);
chaser1:set_visible(true);
chaser1:set_solid(true);

-- chaser2
chaser2 = field:load_model("Chasers_Speed2", 40);
chaser2:set_position_triangle(-100, 100, 0, 1);
chaser2:set_speed(500);
chaser2:set_solid_range(15);
chaser2:set_visible(true);
chaser2:set_solid(true);

-- chaser3
chaser3 = field:load_model("Chasers_Speed3", 40);
chaser3:set_position_triangle(100, 100, 0, 1);
chaser3:set_speed(500);
chaser3:set_solid_range(15);
chaser3:set_visible(true);
chaser3:set_solid(true);
]]




--[[
-- message conf
message:set_clickable(1, false);



entity["Player"] = {
    on_start = function(self)
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

        return 0;
    end;

    on_collide = function(self)
        return 0;
    end;
};



entity["Chaser_Slow"] = {
    on_start = function(self)
        script:wait(1);

        while true do
            chaser_slow:set_solid(true);
            chaser_slow:move_to_model(player, false);
            chaser_slow:set_solid(false);
            script:wait(5);
        end;

        return 0;
    end;

    on_collide = function(self)
        return 0;
    end;
};



entity["Chasers_Speed1"] = {
    on_start = function(self)
        script:wait(1);

        while true do
            chaser1:set_position_triangle(0, 50, 0, 1);
            chaser1:move_to_model(player, false);
        end;

        return 0;
    end;

    on_collide = function(self)
        return 0;
    end;
};



entity["Chasers_Speed2"] = {
    on_start = function(self)
        script:wait(1);

        while true do
            chaser2:set_position_triangle(-100, 100, 0, 1);
            chaser2:move_to_model(player, false);
        end;

        return 0;
    end;

    on_collide = function(self)
        return 0;
    end;
};



entity["Chasers_Speed3"] = {
    on_start = function(self)
        script:wait(1);

        while true do
            chaser3:set_position_triangle(100, 100, 0, 1);
            chaser3:move_to_model(player, false);
        end;

        return 0;
    end;

    on_collide = function(self)
        return 0;
    end;
};
]]



















EntityContainer = {}

-- watcher1



EntityContainer[ "Watcher1" ] = {
    on_start = function( self )
        local watcher1 = entity_manager:get_entity( "Watcher1" )
        watcher1:set_move_speed( 1.5 )

        watcher1:set_solid_radius( 30 )
        watcher1:set_solid( true )

        script:wait( 1 )

        while true do
            --watcher1:turn_to_model( player, Entity.CLOSEST, 2 )
            script:wait( 0.5 )
            --watcher1:turn_to_direction( 180, Entity.CLOSEST, Field.SMOOTH, 2 )
            script:wait( 1 )
            watcher1:move_walkmesh( 7.5, -6.5, true )
            --watcher1:turn_to_model( player, Entity.CLOSEST, 2 )
            script:wait( 0.5 )
            --watcher1:turn_to_direction( 0, Entity.CLOSEST, Field.SMOOTH, 2 )
            script:wait( 1 )
            watcher1:move_walkmesh( 7.5, 1.5, true )
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
