EntityContainer = {}

progress_game = 0;



EntityContainer[ "Dir" ] = {
    on_start = function( self )
        --03a4 (end 03a4): field:screen_set_scroll_to_coords_instant( 0, 40 );
        if Savemap.progress_game == 0 then
            --03b2 (end 03d1): fade:black();
            --03bb (end 03d1): field:screen_set_scroll_to_coords_instant( 0, 0 );
            --03c1 (end 03d1): music:execute_akao( f0, 00000000, 00000000, 00000000, 00000000, 00007100, 00008101 );
            --03cf (end 03d1): field:random_encounter_on( false );
        end

        --03d6 (end 03d6): [UNREVERSED] BTLMD(20, 00);

        if Savemap.progress_game > 0 then
            --03e1 (end 03e3): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
        end

        --03e3 (end 03e3): [UNREVERSED] FMUSC(00);
        --03e5 (end 03e5): field:map_name(0);

        if Savemap.progress_game == 0 then
            --03f0 (end 04bd): field:movie_set( 53 );
            --03f2 (end 04bd): music:execute_akao( c8, 00007000, 00000000, 00000000, 00000000, 00000000, 00000301 );
            script:request( "EntityContainer.View", "script_3", 6 )
            --0404 (end 04bd): field:play_movie();
            --0405 (end 04bd): music:execute_akao( c8, 00007fff, 00000000, 00000000, 00000000, 00000000, 00002081 );
            --0414 (end 04bd): game:variable_set("menu_appear", 763);
            --0419 (end 04bd): game:party_set( 0, 254, 254 );
            --041d (end 04bd): [UNREVERSED] MMBLK(00);
            --043f (end 04bd): music:execute_akao( 20, 00000040, 00000035 ); -- play sound

            script:wait( 1 )
            script:request( "EntityContainer.Biggs", "script_3", 2 )
            script:wait( 1.1 )

            --044d (end 04bd): script:request( "gu1", "script_3", 2 );
            --0450 (end 04bd): script:wait( 1 );
            --0453 (end 04bd): script:request( "gu0", "script_3", 2 );
            --0456 (end 04bd): script:wait( 2 );
            --0459 (end 04bd): music:execute_akao( 20, 00000040, 00000039 ); -- play sound
            --045e (end 04bd): script:request( "av_l", "script_3", 2 );
            --0461 (end 04bd): script:wait( 0.333333 );
            --0464 (end 04bd): script:wait( 2 );
            --0467 (end 04bd): script:request( "av_s", "script_3", 2 );
            --046a (end 04bd): script:wait( 2.33333 );
            --046d (end 04bd): script:request( "ba", "script_3", 2 );
            --0470 (end 04bd): script:wait( 2.66667 );
            --0473 (end 04bd): field:screen_set_scroll_to_coords_smooth( 65516, 130, 0.4 );
            --047c (end 04bd): script:wait( 0.466667 );
            --047f (end 04bd): script:request( "cl", "script_3", 2 );
            --0482 (end 04bd): script:wait( 0.0666667 );
            --0485 (end 04bd): music:execute_akao( 20, 00000040, 00000037 ); -- play sound
            --048a (end 04bd): script:wait( 0.733333 );
            --048d (end 04bd): field:screen_set_scroll_to_coords_smooth( 10, 35, 0.5 );
            --0496 (end 04bd): script:wait( 0.533333 );
            --0499 (end 04bd): music:execute_akao( 20, 00000040, 00000038 ); -- play sound
            --049e (end 04bd): script:wait( 1.93333 );
            --04a1 (end 04bd): -- set window parameters (id = 3, x = 40, y = 20, width = 133, height = 41);
            --04ab (end 04bd): message:show_text_wait(3, 30, x, y);
            --04ae (end 04bd): script:request( "ba", "script_4", 2 );
            --04b1 (end 04bd): script:wait( 0.666667 );

            Savemap.progress_game = 1

            --04b9 (end 04bd): field:pc_lock(false);
            --04bb (end 04bd): field:menu_lock(false);
        end

        entity_manager:set_player_entity( "Cloud" )

        while true do
            if EntityContainer[ "Cloud" ].cloud ~= nil then
                local triangle_id = EntityContainer[ "Cloud" ].cloud:get_move_triangle_id()

                if ( Savemap.progress_game == 1 ) and ( triangle_id == 12 ) then
                    Savemap.progress_game = 6
                    --04d8 (end 04ea): field:pc_lock(true);
                    --04da (end 04ea): field:menu_lock(true);
                    --04dc (end 04ea): script:request( "hei0", "script_3", 2 );
                    --04df (end 04ea): script:request_end_wait( "hei1", "script_3", 2 );
                    --04e2 (end 04ea): field:battle_run( 300 );
                    --04e6 (end 04ea): field:pc_lock(false);
                    --04e8 (end 04ea): field:menu_lock(false);
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
        --04ef (end 04ef): field:set_entity_to_character("cl", 0);
        self.cloud = entity_manager:get_entity( "Cloud" )
        if Savemap.progress_game == 0 then
            --04fa (end 0512): field:pc_lock(true);
            --04fc (end 0512): field:menu_lock(true);
            self.cloud:set_position( 28.5547, 214.312, 2.42188 )
            self.cloud:set_direction( 180 );
            --050c (end 0512): cl:set_talkable( false );
            self.cloud:set_solid( false );
            --self.cloud:set_visible( false );
        end

        return 0
    end,

    script_3 = function( self )
--[[
        0515 (end 0515): cl:set_talkable( true );
        0517 (end 0517): cl:set_solid( true );
        0519 (end 0519): cl:set_visible(true);
        051b (end 051b): cl:play_animation_wait("3", 0, -1, 1, false);
        051e (end 051e): return;
]]
        return 0
    end,
}



EntityContainer[ "Barret" ] = {
    barret = nil,

    on_start = function( self )
        --0521 (end 0521): field:set_entity_to_character("ba", 1);
        self.barret = entity_manager:get_entity( "Barret" )
        --0523 (end 0523): if ( game:variable_get( "progress_game" ) <= 1 ) then continue else jumpto(0536);
        self.barret:set_position( 30.6328, 214.758, 2.52344 )
        --0536 (end 0536): return;

        return 0
    end,

    script_3 = function( self )
--[[
        053a (end 053a): ba:set_talkable( true );
        053c (end 053c): ba:set_solid( true );
        053e (end 053e): ba:set_visible(true);
        0540 (end 0540): ba:set_speed( 360 );
        0544 (end 0544): ba:move_to_position( "3607, 27712, true );
        054a (end 054a): ba:set_direction( 164.531 );
        054d (end 054d): ba:play_animation_wait( "3", 0, 1.3, 1, true );
        0552 (end 0552): script:wait( 1.33333 );
        0555 (end 0555): ba:play_animation_wait( "3", 1.3, 1.6, 1, true );
        055a (end 055a): return;
]]
        return 0
    end,

    script_4 = function( self )
--[[
        055b (end 055b): ba:move_to_position( "3836, 29295, true );
        0561 (end 0561): ba:move_to_position( "3578, 29360, true );
        0567 (end 0567): return;
]]
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



EntityContainer[ "Hei0" ] = {
    hei0 = nil,

    on_start = function( self )
        self.hei0 = entity_manager:get_entity( "Hei0" )
        self.hei0:set_position( 28.3906, 228.781, 2.86719 )
        --05b4 (end 05b4): hei0:set_talkable( false );
        self.hei0:set_solid( false );
        self.hei0:set_visible( false );

        return 0
    end,

    script_3 = function( self )
--[[
        05be (end 05be): hei0:set_visible(true);
        05c0 (end 05c0): hei0:set_speed( 285 );
        05c4 (end 05c4): hei0:move_to_position( "3794, 29268, true );
        05ca (end 05ca): hei0:move_to_position( "3732, 28752, true );
        05d0 (end 05d0): hei0:set_talkable( false );
        05d2 (end 05d2): hei0:set_solid( false );
        05d4 (end 05d4): hei0:set_visible(false);
        05d6 (end 05d6): return;
]]
        return 0
    end,
}



EntityContainer[ "Hei1" ] = {
    hei1 = nil,

    on_start = function( self )
        self.hei1 = entity_manager:get_entity( "Hei0" )
        self.hei1:set_position( 28.3906, 228.781, 2.86719 )
        --05b4 (end 05b4): hei0:set_talkable( false );
        self.hei1:set_solid( false );
        self.hei1:set_visible( false );

        return 0
    end,

    script_3 = function( self )
--[[
        05ee (end 05ee): hei1:set_visible(true);
        05f0 (end 05f0): hei1:set_speed( 300 );
        05f4 (end 05f4): hei1:move_to_position( "3897, 29257, true );
        05fa (end 05fa): hei1:move_to_position( "3873, 28840, true );
        0600 (end 0600): hei1:set_talkable( false );
        0602 (end 0602): hei1:set_solid( false );
        0604 (end 0604): hei1:set_visible(false);
        0606 (end 0606): return;
]]
        return 0
    end,
}



-- AvM
EntityContainer[ "Biggs" ] = {
    biggs = nil,

    on_start = function( self )
        self.biggs = entity_manager:get_entity( "Biggs" )
        self.biggs:set_position( 30, 228, 2.45312 )
        self.biggs:set_direction( 270 )
        --0617 (end 0617): av_m:set_talkable( false )
        self.biggs:set_solid( false )
        self.biggs:set_visible( false )

        return 0
    end,

    script_3 = function( self )
        self.biggs:set_visible( true )
        self.biggs:play_animation( "JumpFromTrain" )
        self.biggs:animation_sync()
        script:wait( 0.266667 )
        self.biggs:turn_to_direction( 326.25, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
        script:wait( 0.333333 )
        self.biggs:play_animation( "Throw" )
        self.biggs:animation_sync()
        self.biggs:set_direction( 146.25 )
        script:wait( 3.33333 )
        self.biggs:set_move_speed( 2.34375 )
        self.biggs:move_to_position( 29.9688, 228.867 )
        self.biggs:move_sync()
        self.biggs:move_to_position( 27.9531, 229.375 )
        self.biggs:move_sync()
        --064b (end 064b): av_m:set_talkable( false );
        self.biggs:set_solid( false )
        self.biggs:set_visible( false )

        return 0
    end,
}



--[[
av_l
script_0:
0652 (end 0652): -- assosiate entity with model (CHAR) argument doesn't matter;
0654 (end 0654): av_l:set_position_triangle(3986, 28214, 321, 34);
065f (end 065f): av_l:set_talkable( false );
0661 (end 0661): av_l:set_solid( false );
0663 (end 0663): av_l:set_visible(false);
0665 (end 0665): return;
0666 (end 0666): jumpto( 0666 );

script_3:
0669 (end 0669): av_l:set_visible(true);
066b (end 066b): av_l:set_speed( 240 );
066f (end 066f): av_l:move_to_position( "3672, 28221, true );
0675 (end 0675): av_l:set_direction( 16.875 );
0678 (end 0678): av_l:play_animation_wait( "3", 0, 0.466667, 1, true );
067d (end 067d): script:wait( 0.233333 );
0680 (end 0680): music:execute_akao( 20, 00000040, 0000001c ); -- play sound
0685 (end 0685): script:wait( 0.766667 );
0688 (end 0688): av_l:play_animation_wait( "3", 0.5, 0.8, 1, false );
068d (end 068d): av_l:set_animation_default("0", 1);
0690 (end 0690): script:wait( 1.33333 );
0693 (end 0693): av_l:move_to_position( "3836, 29295, true );
0699 (end 0699): av_l:move_to_position( "3578, 29360, true );
069f (end 069f): av_l:set_talkable( false );
06a1 (end 06a1): av_l:set_solid( false );
06a3 (end 06a3): av_l:set_visible(false);
06a5 (end 06a5): return;

av_s
script_0:
06a6 (end 06a6): -- assosiate entity with model (CHAR) argument doesn't matter;
06a8 (end 06a8): av_s:set_position_triangle(3794, 28317, 310, 14);
06b3 (end 06b3): av_s:set_direction( 270 );
06b6 (end 06b6): av_s:set_talkable( false );
06b8 (end 06b8): av_s:set_solid( false );
06ba (end 06ba): av_s:set_visible(false);
06bc (end 06bc): return;
06bd (end 06bd): jumpto( 06bd );

script_3:
06c0 (end 06c0): av_s:set_visible(true);
06c2 (end 06c2): av_s:play_animation_wait("3", 0, -1, 1, false);
06c5 (end 06c5): script:wait( 0.266667 );
06c8 (end 06c8): av_s:turn_to_direction( 326.25, Entity.CLOSEST, Field.SMOOTH, 0.333333 );
06ce (end 06ce): script:wait( 2 );
06d1 (end 06d1): av_s:set_speed( 300 );
06d5 (end 06d5): av_s:move_to_position( "3836, 29295, true );
06db (end 06db): av_s:move_to_position( "3578, 29360, true );
06e1 (end 06e1): av_s:set_talkable( false );
06e3 (end 06e3): av_s:set_solid( false );
06e5 (end 06e5): av_s:set_visible(false);
06e7 (end 06e7): return;
]]



EntityContainer[ "Gu0" ] = {
    gu0 = nil,

    on_start = function( self )
        self.gu0 = entity_manager:get_entity( "Gu0" )
        self.gu0:set_position( 28.0938, 217.008, 2.42188 )
        self.gu0:set_direction( 90 )
        if Savemap.progress_game >= 1 then
            self.gu0:set_position( 29.4297, 216.578, 2.42188 )
            self.gu0:set_direction( 191.25 )
            self.gu0:set_default_animation( "Dead1" );
        end

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

    script_3 = function( self )
--[[
        0761 (end 0761): gu0:set_solid( false );
        0763 (end 0763): gu0:turn_to_direction( 135, Entity.CLOSEST, Field.SMOOTH, 0.333333 );
        0769 (end 0769): script:wait( 1.06667 );
        076c (end 076c): gu0:play_animation_wait("4", 0, -1, 1, false);
        076f (end 076f): gu0:set_speed( 240 );
        0773 (end 0773): script:wait( 0.266667 );
        0776 (end 0776): gu0:move_to_position( "3704, 28044, true );
        077c (end 077c): gu0:set_direction( 191.25 );
        077f (end 077f): gu0:play_animation_wait( "5", 0, -1, 1, true );
        0782 (end 0782): script:request_end_wait( "gu1", "script_4", 6 );
        0785 (end 0785): gu0:set_talkable( false );
        0787 (end 0787): gu0:set_solid( false );
        0789 (end 0789): gu0:set_visible(false);
]]
        return 0
    end,
}



EntityContainer[ "Gu1" ] = {
    gu1 = nil,

    on_start = function( self )
        self.gu1 = entity_manager:get_entity( "Gu1" )
        self.gu1:set_position( 28.875, 224.477, 2.42188 )
        self.gu1:set_direction( 90 )
        if Savemap.progress_game >= 1 then
            self.gu1:set_position( 30.625, 227.812, 2.42969 )
            self.gu1:set_direction( 56.25 )
            self.gu1:set_default_animation( "Dead2" );
        end

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

    script_3 = function( self )
--[[
        0805 (end 0805): gu1:set_solid( false );
        0807 (end 0807): gu1:play_animation_wait("4", 0, -1, 1, false);
        080a (end 080a): gu1:set_speed( 480 );
        080e (end 080e): gu1:move_to_position( "3792, 29232, true );
        0814 (end 0814): gu1:set_direction( 56.25 );
        0817 (end 0817): gu1:play_animation_wait( "7", 0, -1, 1, true );
        081a (end 081a): script:request( "guadd", "script_3", 6 );
        081d (end 081d): gu1:set_talkable( false );
        081f (end 081f): gu1:set_solid( false );
        0821 (end 0821): gu1:set_visible(false);
]]
        return 0
    end,

    script_4 = function( self )
--[[
        0824 (end 0824): gu1:set_animation_default("3", 1);
        0827 (end 0827): gu1:set_position_triangle(3767, 27722, 310, 20);
        0832 (end 0832): gu1:set_direction( 191.25 );
        0835 (end 0835): gu1:set_talkable( true );
        0837 (end 0837): gu1:set_solid( true );
        0839 (end 0839): gu1:set_visible(true);
]]
        return 0
    end,
}



EntityContainer[ "GuAdd" ] = {
    gu_add = nil,

    on_start = function( self )
        self.gu_add = entity_manager:get_entity( "GuAdd" )
        self.gu_add:set_position( 30.625, 227.812, 2.42969 )
        self.gu_add:set_direction( 56.25 )
        self.gu_add:set_default_animation( "Dead2" );
        --084f (end 084f): guadd:set_talkable( false );
        self.gu_add:set_solid( false );
        self.gu_add:set_visible( false );

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

    script_3 = function( self )
--[[
        08a5 (end 08a5): guadd:set_talkable( true );
        08a7 (end 08a7): guadd:set_solid( true );
        08a9 (end 08a9): guadd:set_visible(true);
]]
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
            load_field_map_request( "ffvii_md1_1", "Spawn_md1stin" )
        end

        return 0
    end,

    on_leave_line = function( self, entity )
        return 0
    end,
}
