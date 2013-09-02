EntityContainer = {}



EntityContainer[ "Director" ] = {
    on_start = function( self )
        background2d:scroll_to_position( 0, 40, Background2D.NONE, 0 )
        if FFVII.Data.progress_game == 0 then
            player_lock( true )
            --03b2 (end 03d1): fade:black();
            background2d:scroll_to_position( 0, 0, Background2D.NONE, 0 )
            --03c1 (end 03d1): music:execute_akao( f0, 00000000, 00000000, 00000000, 00000000, 00007100, 00008101 );
            --03cf (end 03d1): field:random_encounter_on( false );
        end

        --03d6 (end 03d6): [UNREVERSED] BTLMD(20, 00);

        if FFVII.Data.progress_game > 0 then
            --03e1 (end 03e3): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
        end

        --03e3 (end 03e3): [UNREVERSED] FMUSC(00);
        --03e5 (end 03e5): field:map_name(0);

        if FFVII.Data.progress_game == 0 then
            --03f0 (end 04bd): field:movie_set( 53 );
            --03f2 (end 04bd): music:execute_akao( c8, 00007000, 00000000, 00000000, 00000000, 00000000, 00000301 );
            script:request( Script.ENTITY, "View", "script_3", 6 )
            --0404 (end 04bd): field:play_movie();
            --0405 (end 04bd): music:execute_akao( c8, 00007fff, 00000000, 00000000, 00000000, 00000000, 00002081 );
            --0414 (end 04bd): game:variable_set("menu_appear", 763);


            FFVII.set_party( "Cloud", nil, nil );

            --041d (end 04bd): [UNREVERSED] MMBLK(00);
            --043f (end 04bd): music:execute_akao( 20, 00000040, 00000035 ); -- play sound

            script:wait( 1 )
            script:request( Script.ENTITY, "Biggs", "action1", 2 )
            script:wait( 1.1 )
            script:request( Script.ENTITY, "Gu1", "action1", 2 )
            script:wait( 1 )
            script:request( Script.ENTITY, "Gu0", "action1", 2 )
            script:wait( 2 )
            --0459 (end 04bd): music:execute_akao( 20, 00000040, 00000039 ); -- play sound
            script:request( Script.ENTITY, "Jessie", "action1", 2 )
            script:wait( 0.333333 )
            script:wait( 2 )
            script:request( Script.ENTITY, "Wedge", "action1", 2 )
            script:wait( 2.33333 )
            script:request( Script.ENTITY, "Barret", "action1", 2 )
            script:wait( 2.66667 )
            background2d:scroll_to_position( -20, 130, Background2D.SMOOTH, 0.4 )
            script:wait( 0.466667 )
            script:request( Script.ENTITY, "Cloud", "action1", 2 )
            script:wait( 0.0666667 )
            --0485 (end 04bd): music:execute_akao( 20, 00000040, 00000037 ); -- play sound
            script:wait( 0.733333 )
            background2d:scroll_to_position( 10, 35, Background2D.SMOOTH, 0.5 )
            script:wait( 0.533333 )
            --0499 (end 04bd): music:execute_akao( 20, 00000040, 00000038 ); -- play sound
            script:wait( 1.93333 )
            --04a1 (end 04bd): -- set window parameters (id = 3, x = 40, y = 20, width = 133, height = 41);
            --04ab (end 04bd): message:show_text_wait(3, 30, x, y);
            script:request( Script.ENTITY, "Barret", "action2", 2 )
            script:wait( 0.666667 )

            FFVII.Data.progress_game = 1

            player_lock( false )
        end

        while true do
            if FFVII.Data.progress_game > 1 then
                break
            end

            if EntityContainer[ "Cloud" ].cloud ~= nil then
                local triangle_id = EntityContainer[ "Cloud" ].cloud:get_move_triangle_id()

                if ( FFVII.Data.progress_game == 1 ) and ( triangle_id == 12 ) then
                    FFVII.Data.progress_game = 6
                    player_lock( true )
                    script:request( Script.ENTITY, "Hei0", "action1", 2 )
                    script:request_end_sync( Script.ENTITY, "Hei1", "action1", 2 )
                    --04e2 (end 04ea): field:battle_run( 300 );
                    player_lock( false )
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
        set_entity_to_character( "Cloud", "Cloud" );
        self.cloud = entity_manager:get_entity( "Cloud" )
        if FFVII.Data.progress_game == 0 then
            self.cloud:set_position( 28.5547, 214.312, 2.42188 )
            self.cloud:set_rotation( 180 )
            self.cloud:set_solid( false )
            self.cloud:set_visible( false )
        else
            self.cloud:set_solid( true )
            self.cloud:set_visible( true )
        end

        return 0
    end,

    action1 = function( self )
        self.cloud:set_solid( true )
        self.cloud:set_visible( true )
        self.cloud:play_animation( "JumpFromTrain" )
        self.cloud:animation_sync()

        return 0
    end,
}



EntityContainer[ "Barret" ] = {
    barret = nil,

    on_start = function( self )
        set_entity_to_character( "Barret", "Barret" );
        self.barret = entity_manager:get_entity( "Barret" )
        if FFVII.Data.progress_game <= 1 then
            self.barret:set_position( 30.6328, 214.758, 2.52344 )
        end

        self.barret:set_solid( false )
        self.barret:set_visible( false )

        return 0
    end,

    --[[ Barret run from train and invite Cloud ]]
    action1 = function( self )
        self.barret:set_solid( true )
        self.barret:set_visible( true )
        self.barret:set_move_auto_speed( 2.8125 )
        self.barret:move_to_position( 28.1797, 216.5 )
        self.barret:move_sync()
        self.barret:set_rotation( 164.531 )
        self.barret:play_animation_stop( "Invitation", 0, 1.3 )
        self.barret:animation_sync()
        script:wait( 1.33333 )
        self.barret:play_animation_stop( "Invitation", 1.3, 1.6 )
        self.barret:animation_sync()

        return 0
    end,

    --[[ Barret run to next field ]]
    action2 = function( self )
        self.barret:move_to_position( 29.9688, 228.867 )
        self.barret:move_sync()
        self.barret:move_to_position( 27.9531, 229.375 )
        self.barret:move_sync()
        self.barret:set_solid( false )
        self.barret:set_visible( false )

        return 0
    end,
}



EntityContainer[ "View" ] = {
    on_start = function( self )
        return 0
    end,

    script_3 = function( self )
--[[
        056c (end 056c): temp6_06 = field:get_movie_frame();
        056f (end 056f): if ( temp6_06 > 20 ) then continue else jumpto(0582);
        0577 (end 0582): fade:clear();
        0580 (end 0582): jumpto( 0584 );
        0582 (end 0584): jumpto( 056c );
        0584 (end 0584): temp6_06 = field:get_movie_frame();
        0587 (end 0587): if ( temp6_06 > 664 ) then continue else jumpto(05a4);
        058f (end 05a4): music:execute_akao( 10, pointer_to_field_AKAO_1 ); -- play field music
        0591 (end 05a4): music:lock( true );
        0593 (end 05a4): music:execute_akao( c9, 0000003c, 00007fff, 00000000, 00000000, 00000000, 00000310 );
        05a2 (end 05a4): jumpto( 05a6 );
        05a4 (end 05a6): jumpto( 0584 );
        05a6 (end 05a6): return;
]]
        return 0
    end,
}



--[[ 1st army man that attacks Cloud as we approach next field. ]]
EntityContainer[ "Hei0" ] = {
    hei0 = nil,

    on_start = function( self )
        self.hei0 = entity_manager:get_entity( "Hei0" )
        self.hei0:set_position( 28.3906, 228.781, 2.86719 )
        self.hei0:set_solid( false )
        self.hei0:set_visible( false )

        return 0
    end,

    --[[ Army man run from gate to Cloud. ]]
    action1 = function( self )
        self.hei0:set_visible( true )
        self.hei0:set_move_auto_speed( 2.22656 )
        self.hei0:move_to_position( 29.6406, 228.656 )
        self.hei0:move_sync()
        self.hei0:move_to_position( 29.1562, 224.625 )
        self.hei0:move_sync()
        self.hei0:set_solid( false )
        self.hei0:set_visible( false )

        return 0
    end,
}



--[[ 2nd army man that attacks Cloud as we approach next field. ]]
EntityContainer[ "Hei1" ] = {
    hei1 = nil,

    on_start = function( self )
        self.hei1 = entity_manager:get_entity( "Hei1" )
        self.hei1:set_position( 28.3906, 228.781, 2.86719 )
        self.hei1:set_solid( false )
        self.hei1:set_visible( false )

        return 0
    end,

    --[[ Army man run from gate to Cloud. ]]
    action1 = function( self )
        self.hei1:set_visible( true )
        self.hei1:set_move_auto_speed( 2.34375 )
        self.hei1:move_to_position( 30.4453, 228.57 )
        self.hei1:move_sync()
        self.hei1:move_to_position( 30.2578, 225.312 )
        self.hei1:move_sync()
        self.hei1:set_solid( false )
        self.hei1:set_visible( false )

        return 0
    end,
}



-- AvM
EntityContainer[ "Biggs" ] = {
    biggs = nil,

    on_start = function( self )
        self.biggs = entity_manager:get_entity( "Biggs" )
        self.biggs:set_position( 30, 228, 2.45312 )
        self.biggs:set_rotation( 270 )
        self.biggs:set_solid( false )
        self.biggs:set_visible( false )

        return 0
    end,

    --[[ This is all action that does Biggs. At first he jumps from train, then he
    throws guard and a bit later run to next map. ]]
    action1 = function( self )
        self.biggs:set_visible( true )
        self.biggs:play_animation( "JumpFromTrain" )
        self.biggs:animation_sync()
        script:wait( 0.266667 )
        self.biggs:turn_to_direction( 326.25, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        script:wait( 0.333333 )
        self.biggs:play_animation( "Throw" )
        self.biggs:animation_sync()
        self.biggs:set_rotation( 146.25 )
        script:wait( 3.33333 )
        self.biggs:set_move_auto_speed( 2.34375 )
        self.biggs:move_to_position( 29.9688, 228.867 )
        self.biggs:move_sync()
        self.biggs:move_to_position( 27.9531, 229.375 )
        self.biggs:move_sync()
        self.biggs:set_solid( false )
        self.biggs:set_visible( false )

        return 0
    end,
}



-- AvL
EntityContainer[ "Jessie" ] = {
    jessie = nil,

    on_start = function( self )
        self.jessie = entity_manager:get_entity( "Jessie" )
        self.jessie:set_position( 31.1406, 220.422, 2.50781 )
        self.jessie:set_solid( false )
        self.jessie:set_visible( false )

        return 0
    end,

    --[[ This is all action that does Jessie. At first she run from train, then she
    kicks guard and a bit later run to next map. ]]
    action1 = function( self )
        self.jessie:set_visible( true )
        self.jessie:set_move_auto_speed( 1.875 )
        self.jessie:move_to_position( 28.6875, 220.477 )
        self.jessie:move_sync()
        self.jessie:set_rotation( 16.875 )
        self.jessie:play_animation_stop( "Kick", 0, 0.466667 )
        self.jessie:animation_sync()
        script:wait( 0.233333 )
        --0680 (end 0680): music:execute_akao( 20, 00000040, 0000001c ); -- play sound
        script:wait( 0.766667 )
        self.jessie:play_animation( "Kick", 0.5, 0.8 )
        self.jessie:animation_sync()
        self.jessie:set_default_animation( "Idle" )
        self.jessie:play_animation( "Idle" )
        script:wait( 1.33333 )
        self.jessie:move_to_position( 29.9688, 228.867 )
        self.jessie:move_sync()
        self.jessie:move_to_position( 27.9531, 229.375 )
        self.jessie:move_sync()
        self.jessie:set_solid( false )
        self.jessie:set_visible( false )

        return 0
    end,
}



-- AvS
EntityContainer[ "Wedge" ] = {
    wedge = nil,

    on_start = function( self )
        self.wedge = entity_manager:get_entity( "Wedge" )
        self.wedge:set_position( 29.6406, 221.227, 2.42188 )
        self.wedge:set_rotation( 270 )
        self.wedge:set_solid( false )
        self.wedge:set_visible( false )

        return 0
    end,

    --[[ This is all action that does Wedge. At first he jumps from train, then he
    looks around and a bit later run to next map. ]]
    action1 = function( self )
        self.wedge:set_visible( true )
        self.wedge:play_animation( "JumpFromTrain" )
        self.wedge:animation_sync()
        script:wait( 0.266667 )
        self.wedge:turn_to_direction( 326.25, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        script:wait( 2 )
        self.wedge:set_move_auto_speed( 2.34375 )
        self.wedge:move_to_position( 29.9688, 228.867 )
        self.wedge:move_sync()
        self.wedge:move_to_position( 27.9531, 229.375 )
        self.wedge:move_sync()
        self.wedge:set_solid( false )
        self.wedge:set_visible( false )

        return 0
    end,
}



--[[ One of two guards thas stays on train station at the very beginning.
This one is closest to camera. Jessie takes him off. ]]
EntityContainer[ "Gu0" ] = {
    gu0 = nil,

    on_start = function( self )
        self.gu0 = entity_manager:get_entity( "Gu0" )
        self.gu0:set_position( 28.0938, 217.008, 2.42188 )
        self.gu0:set_rotation( 90 )
        if FFVII.Data.progress_game >= 1 then
            self.gu0:set_position( 29.4297, 216.578, 2.42188 )
            self.gu0:set_rotation( 191.25 )
            self.gu0:set_default_animation( "Dead1" )
            self.gu0:play_animation( "Dead1" )
        end
        self.gu0:set_solid( true )
        self.gu0:set_visible( true )

        return 0
    end,

    script_1 = function( self )
--[[
        0714 (end 0714): field:pc_lock(true);
        0716 (end 0716): field:menu_lock(true);
        0718 (end 0718): if ( !(game:variable_get( "sector1_item" ) & (1 << 0)) ) then continue else jumpto(073b);
        071e (end 073b): music:execute_akao( 20, 00000040, 00000168 ); -- play sound
        0723 (end 073b): -- set window parameters (id = 0, x = 83, y = 10, width = 138, height = 25);
        072d (end 073b): message:show_text_wait(0, 6, x, y);
        0730 (end 073b): game:variable_set("sector1_item", (game:variable_get( "sector1_item" ) | (1 << 0)));
        0734 (end 073b): game:item_add(0, 1);
        0739 (end 073b): jumpto( 075c );
        073b (end 075c): if ( !(game:variable_get( "sector1_item" ) & (1 << 1)) ) then continue else jumpto(075c);
        0741 (end 075c): music:execute_akao( 20, 00000040, 00000168 ); -- play sound
        0746 (end 075c): -- set window parameters (id = 0, x = 83, y = 10, width = 138, height = 25);
        0750 (end 075c): message:show_text_wait(0, 6, x, y);
        0753 (end 075c): game:variable_set("sector1_item", (game:variable_get( "sector1_item" ) | (1 << 1)));
        0757 (end 075c): game:item_add(0, 1);
        075c (end 075c): field:pc_lock(false);
        075e (end 075e): field:menu_lock(false);
]]
        return 0
    end,

    --[[ This is what Gu0 do.
    First Gu0 look to Jessie and then run to her. Jessie kicks Gu0
    away and then Gu0 stay on the ground. ]]
    action1 = function( self )
        self.gu0:set_solid( false )
        self.gu0:turn_to_direction( 135, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        script:wait( 1.06667 )
        self.gu0:play_animation( "LookBack" )
        self.gu0:animation_sync()
        self.gu0:set_move_auto_speed( 1.875 )
        script:wait( 0.266667 )
        self.gu0:move_to_position( 28.9375, 219.094 )
        self.gu0:move_sync()
        self.gu0:set_rotation( 191.25 )
        self.gu0:play_animation_stop( "Kicked" )
        self.gu0:animation_sync()
        script:request_end_sync( Script.ENTITY, "Gu1", "activate", 6 )
        --0785 (end 0785): gu0:set_talkable( false )
        self.gu0:set_solid( false )
        self.gu0:set_visible( false )

        return 0
    end,
}



--[[ One of two guards thas stays on train station at the very beginning.
This one stay far from camera. Biggs takes him off. ]]
EntityContainer[ "Gu1" ] = {
    gu1 = nil,

    on_start = function( self )
        self.gu1 = entity_manager:get_entity( "Gu1" )
        self.gu1:set_position( 28.875, 224.477, 2.42188 )
        self.gu1:set_rotation( 90 )
        if FFVII.Data.progress_game >= 1 then
            self.gu1:set_position( 30.625, 227.812, 2.42969 )
            self.gu1:set_rotation( 56.25 )
            self.gu1:set_default_animation( "Dead2" )
            self.gu1:play_animation( "Dead2" )
        end
        self.gu1:set_solid( true )
        self.gu1:set_visible( true )

        return 0
    end,

    script_1 = function( self )
--[[
        07b8 (end 07b8): field:pc_lock(true);
        07ba (end 07ba): field:menu_lock(true);
        07bc (end 07bc): if ( !(game:variable_get( "sector1_item" ) & (1 << 0)) ) then continue else jumpto(07df);
        07c2 (end 07df): music:execute_akao( 20, 00000040, 00000168 ); -- play sound
        07c7 (end 07df): -- set window parameters (id = 0, x = 83, y = 10, width = 138, height = 25);
        07d1 (end 07df): message:show_text_wait(0, 6, x, y);
        07d4 (end 07df): game:variable_set("sector1_item", (game:variable_get( "sector1_item" ) | (1 << 0)));
        07d8 (end 07df): game:item_add(0, 1);
        07dd (end 07df): jumpto( 0800 );
        07df (end 0800): if ( !(game:variable_get( "sector1_item" ) & (1 << 1)) ) then continue else jumpto(0800);
        07e5 (end 0800): music:execute_akao( 20, 00000040, 00000168 ); -- play sound
        07ea (end 0800): -- set window parameters (id = 0, x = 83, y = 10, width = 138, height = 25);
        07f4 (end 0800): message:show_text_wait(0, 6, x, y);
        07f7 (end 0800): game:variable_set("sector1_item", (game:variable_get( "sector1_item" ) | (1 << 1)));
        07fb (end 0800): game:item_add(0, 1);
        0800 (end 0800): field:pc_lock(false);
        0802 (end 0802): field:menu_lock(false);
]]
        return 0
    end,

    --[[ This is what Gu1 do after Biggs jumps from the train.
    First Gu1 look to Biggs and then run to him. Biggs throw Gu1
    to the ground and then Gu1 stay on it. ]]
    action1 = function( self )
        self.gu1:set_solid( false )
        self.gu1:play_animation( "LookBack" )
        self.gu1:animation_sync()
        self.gu1:set_move_auto_speed( 3.75 )
        self.gu1:move_to_position( 29.625, 228.375 )
        self.gu1:move_sync()
        self.gu1:set_rotation( 56.25 )
        self.gu1:play_animation_stop( "Throwed" )
        self.gu1:animation_sync()
        script:request( Script.ENTITY, "GuAdd", "activate", 6 )
        --081d (end 081d): gu1:set_talkable( false )
        self.gu1:set_solid( false )
        self.gu1:set_visible( false )

        return 0
    end,

    -- [[ This will activate Gu1 in place of Gu0. Don't know why it is done this way. ]]
    activate = function( self )
        self.gu1:set_default_animation( "Dead1" )
        self.gu1:play_animation( "Dead1" )
        self.gu1:set_position( 29.4297, 216.578, 2.42188 )
        self.gu1:set_rotation( 191.25 )
        --0835 (end 0835): gu1:set_talkable( true )
        self.gu1:set_solid( true )
        self.gu1:set_visible( true )

        return 0
    end,
}



--[[ Additional guard model used when script switch model.
Don't know why it is dome this way. ]]
EntityContainer[ "GuAdd" ] = {
    gu_add = nil,

    on_start = function( self )
        self.gu_add = entity_manager:get_entity( "GuAdd" )
        self.gu_add:set_position( 30.625, 227.812, 2.42969 )
        self.gu_add:set_rotation( 56.25 )
        self.gu_add:set_default_animation( "Dead2" )
        self.gu_add:play_animation( "Dead2" )
        --084f (end 084f): guadd:set_talkable( false )
        self.gu_add:set_solid( false )
        self.gu_add:set_visible( false )

        return 0
    end,

    script_1 = function( self )
--[[
        0858 (end 0858): field:pc_lock(true);
        085a (end 085a): field:menu_lock(true);
        085c (end 085c): if ( !(game:variable_get( "sector1_item" ) & (1 << 0)) ) then continue else jumpto(087f);
        0862 (end 087f): music:execute_akao( 20, 00000040, 00000168 ); -- play sound
        0867 (end 087f): -- set window parameters (id = 0, x = 83, y = 10, width = 138, height = 25);
        0871 (end 087f): message:show_text_wait(0, 6, x, y);
        0874 (end 087f): game:variable_set("sector1_item", (game:variable_get( "sector1_item" ) | (1 << 0)));
        0878 (end 087f): game:item_add(0, 1);
        087d (end 087f): jumpto( 08a0 );
        087f (end 08a0): if ( !(game:variable_get( "sector1_item" ) & (1 << 1)) ) then continue else jumpto(08a0);
        0885 (end 08a0): music:execute_akao( 20, 00000040, 00000168 ); -- play sound
        088a (end 08a0): -- set window parameters (id = 0, x = 83, y = 10, width = 138, height = 25);
        0894 (end 08a0): message:show_text_wait(0, 6, x, y);
        0897 (end 08a0): game:variable_set("sector1_item", (game:variable_get( "sector1_item" ) | (1 << 1)));
        089b (end 08a0): game:item_add(0, 1);
        08a0 (end 08a0): field:pc_lock(false);
        08a2 (end 08a2): field:menu_lock(false);
]]
        return 0
    end,

    --[[ We activate this entity after deactivation of Gu1.
    Don't know why we need to do this, but FFVII handle it this way. ]]
    activate = function( self )
        --08a5 (end 08a5): guadd:set_talkable( true )
        self.gu_add:set_solid( true )
        self.gu_add:set_visible( true )

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
        if entity == "Cloud" then
            load_field_map_request( "ffvii_md1_1", "Spawn_md1stin" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}
