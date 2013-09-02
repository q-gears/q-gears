EntityContainer = {}



EntityContainer[ "Director" ] = {
    on_start = function( self )
        background2d:play_animation_looped( "Light1" )
        background2d:play_animation_looped( "Light2" )
        background2d:play_animation_looped( "Fan" )

        background2d:autoscroll_to_entity( entity_manager:get_entity( "Cloud" ) )
        --03a6 (end 03a6): [UNREVERSED] BTLMD(20, 00);
        --03a9 (end 03a9): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
        --03ab (end 03ab): field:map_name(1);

        while true do
            if FFVII.Data.progress_game >= 7 then
                break
            end

            if EntityContainer[ "Cloud" ].cloud ~= nil then
                local triangle_id = EntityContainer[ "Cloud" ].cloud:get_move_triangle_id()

                if ( FFVII.Data.progress_game < 7 ) and ( triangle_id == 62 ) then
                    player_lock( true )
                    background2d:scroll_to_position( -96, 60, Background2D.SMOOTH, 1.06667 )

                    script:request( Script.ENTITY, "Cloud", "scene_part_1", 6 )

                    FFVII.Data.progress_game = 7

                    script:request_end_sync( Script.ENTITY, "Biggs", "scene_part_2", 6 )
                    script:wait( 0.2 )
                    script:request_end_sync( Script.ENTITY, "Jessie", "scene_part_3", 6 )
                    script:wait( 0.333333 )
                    script:request_end_sync( Script.ENTITY, "Biggs", "scene_part_4", 5 )
                    script:wait( 0.266667 )
                    script:request_end_sync( Script.ENTITY, "Cloud", "scene_part_6", 6 )
                    script:wait( 0.266667 )
                    script:request_end_sync( Script.ENTITY, "Barret", "scene_part_8", 6 )
                    script:wait( 0.4 )
                    --03f5 (end 043e): music:execute_akao( 20, 00000040, 00000034 ); -- play sound
                    script:wait( 0.266667 )
                    --03fd (end 043e): music:execute_akao( 20, 00000040, 00000020 ); -- play sound
                    script:request( Script.ENTITY, "DoorLeft", "open", 6 )
                    script:request( Script.ENTITY, "DoorRight", "open", 6 )
                    script:wait( 0.333333 )
                    script:request( Script.ENTITY, "Jessie", "scene_part_10", 6 )
                    script:wait( 1 )
                    script:request( Script.ENTITY, "Biggs", "scene_part_11", 6 )
                    script:wait( 0.2 )
                    script:request( Script.ENTITY, "Wedge", "scene_part_12", 6 )
                    script:wait( 0.5 )
                    script:request_end_sync( Script.ENTITY, "Barret", "scene_part_13", 6 )
                    --0420 (end 043e): [UNREVERSED] PMJMP(76, 00);
                    script:request( Script.ENTITY, "Barret", "scene_part_15", 6 )
                    script:wait( 1 )
                    --0429 (end 043e): field:movie_set( 20 );
                    EntityContainer.Movie.movie_check = true
                    --042f (end 043e): field:play_movie();
                    --0430 (end 043e): field:jump_to_map(118, 3549, 30574, 60, 180);

                    --player_lock( false )
                end
            end

            script:wait( 0 )
        end

        return 0
    end,
}



EntityContainer[ "Cloud" ] = {
    cloud = nil,

    on_start = function( self )
        set_entity_to_character( "Cloud", "Cloud" )
        self.cloud = entity_manager:get_entity( "Cloud" )
        self.cloud:set_solid( true )
        self.cloud:set_visible( true )

        return 0
    end,

    --[[ Move Cloud to talk position for the scene. ]]
    scene_part_1 = function( self )
        self.cloud:set_move_auto_speed( 1.875 )
        self.cloud:move_to_position( 4.48438, 5.30469 )
        self.cloud:move_sync()
        self.cloud:set_rotation( 174.375 )

        return 0
    end,

    --[[ Cloud reply his name to Avalanche. ]]
    scene_part_5 = function( self )
        self.cloud:play_animation_stop( "LookAtPeople", 0, 0.233333 )
        self.cloud:animation_sync()
        --0465 (end 0465): -- set window parameters (id = 0, x = 100, y = 150, width = 165, height = 41);
        --046f (end 046f): message:show_text_wait(0, 36, x, y);
        self.cloud:play_animation_stop( "LookAtPeople", 0.266667, 0.466667 )
        self.cloud:animation_sync()

        return 0
    end,

    --[[ Cloud tells Biggs that he didn\t care about names. ]]
    scene_part_6 = function( self )
        self.cloud:play_animation( "TalkNo" )
        self.cloud:animation_sync()
        script:request( Script.ENTITY, "Biggs", "scene_part_7", 6 )
        self.cloud:play_animation_stop( "LookAtPeople", 0, 0.233333 )
        self.cloud:animation_sync()
        --0483 (end 0483): -- set window parameters (id = 0, x = 30, y = 150, width = 249, height = 57);
        --048d (end 048d): message:show_text_wait(0, 38, x, y);
        self.cloud:play_animation_stop( "LookAtPeople", 0.233333, 0.466667 )
        self.cloud:animation_sync()

        return 0
    end,

    scene_part_9 = function( self )
        script:wait( 0.333333 )
        self.cloud:play_animation_stop( "LookAtPeople", 0.466667, 0.733333 )
        self.cloud:animation_sync()

        return 0
    end,

    scene_part_14 = function( self )
        self.cloud:play_animation_stop( "LookAtPeople", 0.733333, 0.966667 )
        self.cloud:animation_sync()

        return 0
    end,

    --[[ look at reactor and run after Barret and others. ]]
    scene_part_16 = function( self )
        self.cloud:set_animation_speed( 0.5 )
        script:wait( 0.6 )
        self.cloud:play_animation_stop( "LookUp" )
        self.cloud:animation_sync()
        self.cloud:set_move_auto_speed( 1.17187 )
        self.cloud:set_default_animation( "Idle" )
        self.cloud:play_animation( "Idle" )
        self.cloud:move_to_position( 5.02344, 11.4141 )
        self.cloud:move_sync()

        return 0
    end,
}



EntityContainer[ "Barret" ] = {
    barret = nil,

    on_start = function( self )
        set_entity_to_character( "Barret", "Barret" )
        self.barret = entity_manager:get_entity( "Barret" )

        if FFVII.Data.progress_game < 7 then
            self.barret:set_position( 8.84375, 4.82812, 5.07031 )
        end

        self.barret:set_solid( false )
        self.barret:set_visible( false )

        return 0
    end,

    scene_part_8 = function( self )
        self.barret:set_solid( true )
        self.barret:set_visible( true )
        self.barret:set_move_auto_speed( 1.17187 )
        script:request( Script.ENTITY, "Cloud", "scene_part_9", 6 )
        self.barret:move_to_position( 5.96094, 5.08594 )
        self.barret:move_sync()
        self.barret:set_rotation( 241.875 )
        --04ee (end 04ee): -- set window parameters (id = 3, x = 25, y = 140, width = 228, height = 57);
        --04f8 (end 04f8): message:show_text_wait(3, 39, x, y);
        --04fb (end 04fb): -- set window parameters (id = 3, x = 8, y = 150, width = 260, height = 41);
        --0505 (end 0505): message:show_text_wait(3, 40, x, y);

        return 0
    end,

    scene_part_13 = function( self )
        self.barret:set_move_auto_speed( 1.17187 )
        script:request( Script.ENTITY, "Cloud", "scene_part_14", 6 )
        self.barret:move_to_position( 4.39844, 7.3125 )
        self.barret:move_sync()
        script:wait( 1 )
        self.barret:turn_to_direction( 16.875, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        self.barret:turn_sync()
        script:wait( 0.666667 )
        --0522 (end 0522): -- set window parameters (id = 0, x = 30, y = 20, width = 135, height = 41);
        --052c (end 052c): message:show_text_wait(0, 41, x, y);
        script:wait( 0.266667 )
        --0532 (end 0532): [UNREVERSED] MENU(00, 06, 01);
        script:wait( 0.666667 )
        --0539 (end 0539): -- set window parameters (id = 0, x = 10, y = 137, width = 254, height = 73);
        --0543 (end 0543): message:show_text_wait(0, 42, x, y);

        return 0
    end,

    scene_part_15 = function( self )
        self.barret:move_to_position( 5.29297, 13.1875 )
        self.barret:move_sync()
        self.barret:set_solid( false )
        self.barret:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Biggs" ] = {
    biggs = nil,

    on_start = function( self )
        self.biggs = entity_manager:get_entity( "Biggs" )
        self.biggs:set_position( 3.91406, 6.07812, 5.07031 )
        self.biggs:set_rotation( 174.375 )

        if FFVII.Data.progress_game >= 7 then
            self.biggs:set_solid( false )
            self.biggs:set_visible( false )
        else
            self.biggs:set_solid( true )
            self.biggs:set_visible( true )
        end

        return 0
    end,

    --[[ Turn to Cloud and start talk to him. ]]
    scene_part_2 = function( self )
        self.biggs:turn_to_direction( 39.375, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        self.biggs:turn_sync()
        script:wait( 0.0333333 )
        self.biggs:play_animation_stop( "TalkGesture", 0, 0.3 )
        self.biggs:animation_sync()
        --0584 (end 0584): -- set window parameters (id = 1, x = 8, y = 8, width = 269, height = 73);
        --058e (end 058e): message:show_text_wait(1, 31, x, y);
        self.biggs:play_animation( "TalkGesture", 0.333333, 0.633333 )
        self.biggs:animation_sync()

        return 0
    end,

    --[[ Dialog with Jessie and Cloud. We input Cloud name during this scene and call Cloud reply. ]]
    scene_part_4 = function( self )
        --0597 (end 0597): -- set window parameters (id = 1, x = 30, y = 10, width = 242, height = 41);
        --05a1 (end 05a1): message:show_text_wait(1, 34, x, y);
        self.biggs:play_animation_stop( "TalkGesture", 0, 0.466667 )
        self.biggs:animation_sync()
        --05a9 (end 05a9): -- set window parameters (id = 1, x = 50, y = 10, width = 174, height = 41);
        --05b3 (end 05b3): message:show_text_wait(1, 35, x, y);
        self.biggs:play_animation( "TalkGesture", 0.333333, 0.633333 )
        self.biggs:animation_sync()
        script:wait( 0.1 )
        --05be (end 05be): [UNREVERSED] MENU(00, 06, 00);
        script:wait( 0.1 )
        script:request_end_sync( Script.ENTITY, "Cloud", "scene_part_5", 6 )
        script:wait( 0.2 )
        self.biggs:play_animation_stop( "TalkGesture", 0, 0.466667 )
        self.biggs:animation_sync()
        --05d0 (end 05d0): -- set window parameters (id = 1, x = 50, y = 20, width = 213, height = 41);
        --05da (end 05da): message:show_text_wait(1, 37, x, y);

        return 0
    end,

    scene_part_7 = function( self )
        self.biggs:play_animation( "TalkGesture", 0.333333, 0.633333 )
        self.biggs:animation_sync()

        return 0
    end,

    scene_part_11 = function( self )
        self.biggs:set_move_auto_speed( 1.17187 )
        self.biggs:move_to_position( 4.57422, 6.82812 )
        self.biggs:move_sync()
        self.biggs:move_to_position( 5.29297, 13.1875 )
        self.biggs:move_sync()
        self.biggs:set_solid( false )
        self.biggs:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Jessie" ] = {
    jessie = nil,

    on_start = function( self )
        self.jessie = entity_manager:get_entity( "Jessie" )
        self.jessie:set_position( 4.51953, 6.32422, 5.07031 )
        self.jessie:set_rotation( 174.375 )

        self.jessie:set_default_animation( "BreakUp" )
        self.jessie:play_animation( "BreakUp" )

        if FFVII.Data.progress_game >= 7 then
            self.jessie:set_solid( false )
            self.jessie:set_visible( false )
        else
            self.jessie:set_solid( true )
            self.jessie:set_visible( true )
        end

        return 0
    end,

    --[[ Stop breaking gate for a while and talk. ]]
    scene_part_3 = function( self )
        self.jessie:play_animation_stop( "BreakUpLookBack" )
        self.jessie:animation_sync()
        --0623 (end 0623): -- set window parameters (id = 2, x = 155, y = 8, width = 233, height = 41);
        --062d (end 062d): message:show_text_wait(2, 32, x, y);
        --0630 (end 0630): -- set window parameters (id = 2, x = 120, y = 8, width = 268, height = 41);
        --063a (end 063a): message:show_text_wait(2, 33, x, y);
        script:wait( 0.266667 )
        self.jessie:set_default_animation( "BreakUp" )
        self.jessie:play_animation( "BreakUp" )

        return 0
    end,

    scene_part_10 = function( self )
        self.jessie:set_move_auto_speed( 1.17187 )
        self.jessie:play_animation( "BreakUpGetUp" )
        self.jessie:animation_sync()
        self.jessie:move_to_position( 5.29297, 13.1875 )
        self.jessie:move_sync()
        self.jessie:set_solid( false )
        self.jessie:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Wedge" ] = {
    wedge = nil,

    on_start = function( self )
        self.wedge = entity_manager:get_entity( "Wedge" )
        self.wedge:set_position( 5.94141, 5.875, 5.07031 )
        self.wedge:set_rotation( 16.875 )
        self.wedge:set_default_animation( "LookAround" )
        self.wedge:play_animation( "LookAround" )

        if FFVII.Data.progress_game >= 7 then
            self.wedge:set_solid( false )
            self.wedge:set_visible( false )
        else
            self.wedge:set_solid( true )
            self.wedge:set_visible( true )
        end

        return 0
    end,

    scene_part_12 = function( self )
        self.wedge:set_move_auto_speed( 1.17187 )
        self.wedge:move_to_position( 4.57422, 6.82812 )
        self.wedge:move_sync()
        self.wedge:move_to_position( 5.29297, 13.1875 )
        self.wedge:move_sync()
        self.wedge:set_solid( false )
        self.wedge:set_visible( false )

        return 0
    end,
}



EntityContainer[ "DoorLeft" ] = {
    door = nil,

    on_start = function( self )
        self.door = entity_manager:get_entity( "DoorLeft" )
        self.door:set_position( 4.25, 7.20703, 5.07031 )
        self.door:set_rotation( 354.375 )

        if FFVII.Data.progress_game >= 7 then
            self.door:set_visible( false )
        else
            self.door:set_visible( true )
        end

        self.door:set_solid( false )

        return 0
    end,

    open = function( self )
        self.door:offset_to_position( -0.789062, 0, 0, Entity.LINEAR, 1.66667 )
        self.door:offset_sync()
        self.door:set_visible( false )

        return 0
    end,
}



EntityContainer[ "DoorRight" ] = {
    door = nil,

    on_start = function( self )
        self.door = entity_manager:get_entity( "DoorRight" )
        self.door:set_position( 4.93359, 7.125, 5.07031 )
        self.door:set_rotation( 174.375 )

        if FFVII.Data.progress_game >= 7 then
            self.door:set_visible( false )
        else
            self.door:set_visible( true )
        end

        self.door:set_solid( false )

        return 0
    end,

    open = function( self )
        self.door:offset_to_position( 0.71875, 0, 0, Entity.LINEAR, 1.66667 )
        self.door:offset_sync()
        self.door:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Movie" ] = {
    movie_check = false,

    on_start = function( self )
        while true do
            if self.movie_check == true then
                --0717 (end 0729): temp6_09 = field:get_movie_frame();
                --071a (end 0729): if ( temp6_09 > 30 ) then continue else jumpto(0729);
                script:request( Script.ENTITY, "Cloud", "scene_part_16", 6 )
                break
            end

            script:wait( 0 )
        end

        return 0
    end,
}



--[[
fan
script_0:
072c (end 072c): field:background_clear( "2" ); -- turns off all layer of background animation with given id
072f (end 072f): return;
0730 (end 0730): script:wait( 0.1 )
0733 (end 0733): field:background_on( "2", 0 ); -- turns on layer of background animation with given id
0737 (end 0737): script:wait( 0.133333 )
073a (end 073a): field:background_off( "2", 0 ); -- turns off layer of background animation with given id
073e (end 073e): field:background_on( "2", 1 ); -- turns on layer of background animation with given id
0742 (end 0742): script:wait( 0.133333 )
0745 (end 0745): field:background_off( "2", 1 ); -- turns off layer of background animation with given id
0749 (end 0749): jumpto( 0730 );

light
script_0:
074b (end 074b): temp5_16 = 66;
074f (end 074f): return;
0750 (end 0750): [UNREVERSED] STPAL( 00, 0d, 00, ff );
0755 (end 0755): if ( temp5_16 < 62 ) then continue else jumpto(0775);
075b (end 0775): temp5_16 = temp5_16 + 2;
075f (end 0775): [UNREVERSED] MPPAL2( 00, 55, 50, 00, 10, 16, 16, 16, ff );
0769 (end 0775): [UNREVERSED] CPPAL( 00, 00, 10, 00 );
076e (end 0775): [UNREVERSED] LDPAL( 00, 10, 0d, ff );
0773 (end 0775): jumpto( 0755 );
0775 (end 0775): if ( temp5_16 > 32 ) then continue else jumpto(0795);
077b (end 0795): temp5_16 = temp5_16 - 2;
077f (end 0795): [UNREVERSED] MPPAL2( 00, 55, 50, 00, 10, 16, 16, 16, ff );
0789 (end 0795): [UNREVERSED] CPPAL( 00, 00, 10, 00 );
078e (end 0795): [UNREVERSED] LDPAL( 00, 10, 0d, ff );
0793 (end 0795): jumpto( 0775 );
0795 (end 0795): jumpto( 0755 );

light2
script_0:
0797 (end 0797): temp5_17 = 66;
079b (end 079b): return;
079c (end 079c): script:wait( 0.666667 )
079f (end 079f): [UNREVERSED] STPAL( 00, 0e, 20, ff );
07a4 (end 07a4): if ( temp5_17 < 62 ) then continue else jumpto(07c4);
07aa (end 07c4): temp5_17 = temp5_17 + 1;
07ae (end 07c4): [UNREVERSED] MPPAL2( 00, 55, 50, 20, 30, 17, 17, 17, ff );
07b8 (end 07c4): [UNREVERSED] CPPAL( 00, 20, 30, 00 );
07bd (end 07c4): [UNREVERSED] LDPAL( 00, 30, 0e, ff );
07c2 (end 07c4): jumpto( 07a4 );
07c4 (end 07c4): if ( temp5_17 > 16 ) then continue else jumpto(07e4);
07ca (end 07e4): temp5_17 = temp5_17 - 1;
07ce (end 07e4): [UNREVERSED] MPPAL2( 00, 55, 50, 20, 30, 17, 17, 17, ff );
07d8 (end 07e4): [UNREVERSED] CPPAL( 00, 20, 30, 00 );
07dd (end 07e4): [UNREVERSED] LDPAL( 00, 30, 0e, ff );
07e2 (end 07e4): jumpto( 07c4 );
07e4 (end 07e4): jumpto( 07a4 );
]]



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
        if entity == "Cloud" then
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
        if entity == "Cloud" then
            load_field_map_request( "ffvii_md1_2", "Spawn_md1_1" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}
