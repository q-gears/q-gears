EntityContainer = {}



EntityContainer[ "Dir" ] = {
    on_start = function( self )
--[[
        03a0 (end 03a0): temp6_06 = 62;
        03a5 (end 03a5): field:screen_set_scroll_to_pc_instant(); -- SCRCC
        03a6 (end 03a6): [UNREVERSED] BTLMD(20, 00);
        03a9 (end 03a9): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
        03ab (end 03ab): field:map_name(1);
        03ad (end 03ad): return;
        03ae (end 03ae): temp6_00 = cl:get_triangle();
        03b2 (end 03b2): if ( temp6_00 == temp6_06 ) then continue else jumpto(043e);
        03ba (end 043e): if ( game:variable_get( "progress_game" ) < 7 ) then continue else jumpto(043e);
        03c2 (end 043e): field:pc_lock(true);
        03c4 (end 043e): field:menu_lock(true);
        03c6 (end 043e): field:screen_set_scroll_to_coords_smooth( 65440, 60, 1.06667 );
        03cf (end 043e): script:request( "cl", "script_3", 6 );
        03d2 (end 043e): game:variable_set("progress_game", 7);
        03d7 (end 043e): script:request_end_wait( "av_m", "script_3", 6 );
        03da (end 043e): script:wait( 0.2 )
        03dd (end 043e): script:request_end_wait( "av_l", "script_3", 6 );
        03e0 (end 043e): script:wait( 0.333333 )
        03e3 (end 043e): script:request_end_wait( "av_m", "script_4", 5 );
        03e6 (end 043e): script:wait( 0.266667 )
        03e9 (end 043e): script:request_end_wait( "cl", "script_6", 6 );
        03ec (end 043e): script:wait( 0.266667 )
        03ef (end 043e): script:request_end_wait( "ba", "script_3", 6 );
        03f2 (end 043e): script:wait( 0.4 )
        03f5 (end 043e): music:execute_akao( 20, 00000040, 00000034 ); -- play sound
        03fa (end 043e): script:wait( 0.266667 )
        03fd (end 043e): music:execute_akao( 20, 00000040, 00000020 ); -- play sound
        0402 (end 043e): script:request( "drL", "script_3", 6 );
        0405 (end 043e): script:request( "drR", "script_3", 6 );
        0408 (end 043e): script:wait( 0.333333 )
        040b (end 043e): script:request( "av_l", "script_4", 6 );
        040e (end 043e): script:wait( 1 )
        0411 (end 043e): script:request( "av_m", "script_6", 6 );
        0414 (end 043e): script:wait( 0.2 )
        0417 (end 043e): script:request( "av_s", "script_3", 6 );
        041a (end 043e): script:wait( 0.5 )
        041d (end 043e): script:request_end_wait( "ba", "script_4", 6 );
        0420 (end 043e): [UNREVERSED] PMJMP(76, 00);
        0423 (end 043e): script:request( "ba", "script_5", 6 );
        0426 (end 043e): script:wait( 1 )
        0429 (end 043e): field:movie_set( 20 );
        042b (end 043e): temp5_15 = 1;
        042f (end 043e): field:play_movie();
        0430 (end 043e): field:jump_to_map(118, 3549, 30574, 60, 180);
        043a (end 043e): field:pc_lock(false);
        043c (end 043e): field:menu_lock(false);
        043e (end 043e): jumpto( 03ae );
]]
        return 0
    end,
}



EntityContainer[ "Cloud" ] = {
    cloud = nil,

    on_start = function( self )
        self.cloud = entity_manager:get_entity( "Cloud" )
        set_entity_to_character( "Cloud", "Cloud" )
        cloud:set_move_speed( 3.75 )

        return 0
    end,

    script_3 = function( self )
--[[
044d (end 044d): cl:move_to_position( 8.96875, 10.6094 )
                 cl:move_sync()
0453 (end 0453): cl:set_direction( 174.375 )
0456 (end 0456): return;
]]
        return 0
    end,

    script_4 = function( self )
--[[
0457 (end 0457): script:wait( 0.266667 )
045a (end 045a): cl:play_animation_stop( "3", 0, 0.233333 ) -- speed=1
                 cl:animation_sync()
045f (end 045f): return;
]]
        return 0
    end,

    script_5 = function( self )
--[[
0460 (end 0460): cl:play_animation_stop( "3", 0, 0.233333 ) -- speed=1
                 cl:animation_sync()
0465 (end 0465): -- set window parameters (id = 0, x = 100, y = 150, width = 165, height = 41);
046f (end 046f): message:show_text_wait(0, 36, x, y);
0472 (end 0472): cl:play_animation_stop( "3", 0.266667, 0.466667 ) -- speed=1
                 cl:animation_sync()
0477 (end 0477): return;
]]
        return 0
    end,

    script_6 = function( self )
--[[
0478 (end 0478): cl:play_animation( "4" ) -- speed=1
                 cl:animation_sync()
047b (end 047b): script:request( "av_m", "script_5", 6 );
047e (end 047e): cl:play_animation_stop( "3", 0, 0.233333 ) -- speed=1
                 cl:animation_sync()
0483 (end 0483): -- set window parameters (id = 0, x = 30, y = 150, width = 249, height = 57);
048d (end 048d): message:show_text_wait(0, 38, x, y);
0490 (end 0490): cl:play_animation_stop( "3", 0.233333, 0.466667 ) -- speed=1
                 cl:animation_sync()
0495 (end 0495): return;
]]
        return 0
    end,

    script_7 = function( self )
--[[
0496 (end 0496): script:wait( 0.333333 )
0499 (end 0499): cl:play_animation_stop( "3", 0.466667, 0.733333 ) -- speed=1
                 cl:animation_sync()
049e (end 049e): return;
]]
        return 0
    end,

    script_8 = function( self )
--[[
049f (end 049f): cl:play_animation_stop( "3", 0.733333, 0.966667 ) -- speed=1
                 cl:animation_sync()
04a4 (end 04a4): return;
]]
        return 0
    end,

    script_9 = function( self )
--[[
04a5 (end 04a5): -- set speed of entity animation to "32"
04a9 (end 04a9): script:wait( 0.6 )
04ac (end 04ac): cl:play_animation_stop( "5" ) -- speed=1
                 cl:animation_sync()
04af (end 04af): cl:set_move_speed( 2.34375 )
04b3 (end 04b3): cl:set_default_animation( "0" ) -- speed=1
                 cl:play_animation( "0" )
04b6 (end 04b6): cl:move_to_position( 10.0469, 22.8281 )
                 cl:move_sync()
04bc (end 04bc): return;
]]
        return 0
    end,
}



EntityContainer[ "Barret" ] = {
    barret = nil,

    on_start = function( self )
--[[
04bd (end 04bd): -- assosiate entity with model (CHAR) argument doesn't matter
04bf (end 04bf): field:set_entity_to_character("ba", 1);
04c1 (end 04c1): if ( game:variable_get( "progress_game" ) < 7 ) then continue else jumpto(04d4);
04c9 (end 04d4): ba:set_position( 17.6875, 9.65625, 10.1406 ) -- triangle_id=71
04d4 (end 04d4): return;
04d5 (end 04d5): jumpto( 04d5 );
]]
        return 0
    end,

    script_3 = function( self )
--[[
04d8 (end 04d8): ba:set_talkable( true );
04da (end 04da): ba:set_solid( true )
04dc (end 04dc): ba:set_visible( true )
04de (end 04de): ba:set_move_speed( 2.34375 )
04e2 (end 04e2): script:request( "cl", "script_7", 6 );
04e5 (end 04e5): ba:move_to_position( 11.9219, 10.1719 )
                 ba:move_sync()
04eb (end 04eb): ba:set_direction( 241.875 )
04ee (end 04ee): -- set window parameters (id = 3, x = 25, y = 140, width = 228, height = 57);
04f8 (end 04f8): message:show_text_wait(3, 39, x, y);
04fb (end 04fb): -- set window parameters (id = 3, x = 8, y = 150, width = 260, height = 41);
0505 (end 0505): message:show_text_wait(3, 40, x, y);
0508 (end 0508): return;
]]
        return 0
    end,

    script_4 = function( self )
--[[
0509 (end 0509): ba:set_move_speed( 2.34375 )
050d (end 050d): script:request( "cl", "script_8", 6 );
0510 (end 0510): ba:move_to_position( 8.79688, 14.625 )
                 ba:move_sync()
0516 (end 0516): script:wait( 1 )
0519 (end 0519): ba:turn_to_direction( 16.875, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
051f (end 051f): script:wait( 0.666667 )
0522 (end 0522): -- set window parameters (id = 0, x = 30, y = 20, width = 135, height = 41);
052c (end 052c): message:show_text_wait(0, 41, x, y);
052f (end 052f): script:wait( 0.266667 )
0532 (end 0532): [UNREVERSED] MENU(00, 06, 01);
0536 (end 0536): script:wait( 0.666667 )
0539 (end 0539): -- set window parameters (id = 0, x = 10, y = 137, width = 254, height = 73);
0543 (end 0543): message:show_text_wait(0, 42, x, y);
0546 (end 0546): return;
]]
        return 0
    end,

    script_5 = function( self )
--[[
0547 (end 0547): ba:move_to_position( 10.5859, 26.375 )
                 ba:move_sync()
054d (end 054d): ba:set_talkable( false );
054f (end 054f): ba:set_solid( false )
0551 (end 0551): ba:set_visible( false )
0553 (end 0553): return;
]]
        return 0
    end,
}



--[[
av_m
script_0:
0554 (end 0554): -- assosiate entity with model (CHAR) argument doesn't matter
0556 (end 0556): av_m:set_position( 7.82812, 12.1562, 10.1406 ) -- triangle_id=63
0561 (end 0561): av_m:set_direction( 174.375 )
0564 (end 0564): if ( game:variable_get( "progress_game" ) >= 7 ) then continue else jumpto(0572);
056c (end 0572): av_m:set_talkable( false );
056e (end 0572): av_m:set_solid( false )
0570 (end 0572): av_m:set_visible( false )
0572 (end 0572): return;
0573 (end 0573): jumpto( 0573 );

script_3:
0576 (end 0576): av_m:turn_to_direction( 39.375, Entity.CLOSEST, Entity.SMOOTH, 0.333333 )
057c (end 057c): script:wait( 0.0333333 )
057f (end 057f): av_m:play_animation_stop( "3", 0, 0.3 ) -- speed=1
                 av_m:animation_sync()
0584 (end 0584): -- set window parameters (id = 1, x = 8, y = 8, width = 269, height = 73);
058e (end 058e): message:show_text_wait(1, 31, x, y);
0591 (end 0591): av_m:play_animation( "3", 0.333333, 0.633333 ) -- speed=1
                 av_m:animation_sync()
0596 (end 0596): return;

script_4:
0597 (end 0597): -- set window parameters (id = 1, x = 30, y = 10, width = 242, height = 41);
05a1 (end 05a1): message:show_text_wait(1, 34, x, y);
05a4 (end 05a4): av_m:play_animation_stop( "3", 0, 0.466667 ) -- speed=1
                 av_m:animation_sync()
05a9 (end 05a9): -- set window parameters (id = 1, x = 50, y = 10, width = 174, height = 41);
05b3 (end 05b3): message:show_text_wait(1, 35, x, y);
05b6 (end 05b6): av_m:play_animation( "3", 0.333333, 0.633333 ) -- speed=1
                 av_m:animation_sync()
05bb (end 05bb): script:wait( 0.1 )
05be (end 05be): [UNREVERSED] MENU(00, 06, 00);
05c2 (end 05c2): script:wait( 0.1 )
05c5 (end 05c5): script:request_end_wait( "cl", "script_5", 6 );
05c8 (end 05c8): script:wait( 0.2 )
05cb (end 05cb): av_m:play_animation_stop( "3", 0, 0.466667 ) -- speed=1
                 av_m:animation_sync()
05d0 (end 05d0): -- set window parameters (id = 1, x = 50, y = 20, width = 213, height = 41);
05da (end 05da): message:show_text_wait(1, 37, x, y);
05dd (end 05dd): return;

script_5:
05de (end 05de): av_m:play_animation( "3", 0.333333, 0.633333 ) -- speed=1
                 av_m:animation_sync()
05e3 (end 05e3): return;

script_6:
05e4 (end 05e4): av_m:set_move_speed( 2.34375 )
05e8 (end 05e8): av_m:move_to_position( 9.14844, 13.6562 )
                 av_m:move_sync()
05ee (end 05ee): av_m:move_to_position( 10.5859, 26.375 )
                 av_m:move_sync()
05f4 (end 05f4): av_m:set_talkable( false );
05f6 (end 05f6): av_m:set_solid( false )
05f8 (end 05f8): av_m:set_visible( false )
05fa (end 05fa): return;

av_l
script_0:
05fb (end 05fb): -- assosiate entity with model (CHAR) argument doesn't matter
05fd (end 05fd): av_l:set_position( 9.03906, 12.6484, 10.1406 ) -- triangle_id=62
0608 (end 0608): av_l:set_direction( 174.375 )
060b (end 060b): av_l:set_default_animation( "3" ) -- speed=1
                 av_l:play_animation( "3" )
060e (end 060e): if ( game:variable_get( "progress_game" ) >= 7 ) then continue else jumpto(061c);
0616 (end 061c): av_l:set_talkable( false );
0618 (end 061c): av_l:set_solid( false )
061a (end 061c): av_l:set_visible( false )
061c (end 061c): return;
061d (end 061d): jumpto( 061d );

script_3:
0620 (end 0620): av_l:play_animation_stop( "4" ) -- speed=1
                 av_l:animation_sync()
0623 (end 0623): -- set window parameters (id = 2, x = 155, y = 8, width = 233, height = 41);
062d (end 062d): message:show_text_wait(2, 32, x, y);
0630 (end 0630): -- set window parameters (id = 2, x = 120, y = 8, width = 268, height = 41);
063a (end 063a): message:show_text_wait(2, 33, x, y);
063d (end 063d): script:wait( 0.266667 )
0640 (end 0640): av_l:set_default_animation( "3" ) -- speed=1
                 av_l:play_animation( "3" )
0643 (end 0643): return;

script_4:
0644 (end 0644): av_l:set_move_speed( 2.34375 )
0648 (end 0648): av_l:play_animation( "5" ) -- speed=1
                 av_l:animation_sync()
064b (end 064b): av_l:move_to_position( 10.5859, 26.375 )
                 av_l:move_sync()
0651 (end 0651): av_l:set_talkable( false );
0653 (end 0653): av_l:set_solid( false )
0655 (end 0655): av_l:set_visible( false )
0657 (end 0657): return;

av_s
script_0:
0658 (end 0658): -- assosiate entity with model (CHAR) argument doesn't matter
065a (end 065a): av_s:set_position( 11.8828, 11.75, 10.1406 ) -- triangle_id=70
0665 (end 0665): av_s:set_direction( 16.875 )
0668 (end 0668): av_s:set_default_animation( "3" ) -- speed=1
                 av_s:play_animation( "3" )
066b (end 066b): if ( game:variable_get( "progress_game" ) >= 7 ) then continue else jumpto(0679);
0673 (end 0679): av_s:set_talkable( false );
0675 (end 0679): av_s:set_solid( false )
0677 (end 0679): av_s:set_visible( false )
0679 (end 0679): return;
067a (end 067a): jumpto( 067a );

script_3:
067d (end 067d): av_s:set_move_speed( 2.34375 )
0681 (end 0681): av_s:move_to_position( 9.14844, 13.6562 )
                 av_s:move_sync()
0687 (end 0687): av_s:move_to_position( 10.5859, 26.375 )
                 av_s:move_sync()
068d (end 068d): av_s:set_talkable( false );
068f (end 068f): av_s:set_solid( false )
0691 (end 0691): av_s:set_visible( false )
0693 (end 0693): return;

drL
script_0:
0694 (end 0694): -- assosiate entity with model (CHAR) argument doesn't matter
0696 (end 0696): drL:set_position( 8.5, 14.4141, 10.1406 ) -- triangle_id=61
06a1 (end 06a1): drL:set_direction( 354.375 )
06a4 (end 06a4): if ( game:variable_get( "progress_game" ) >= 7 ) then continue else jumpto(06b2);
06ac (end 06b2): drL:set_talkable( false );
06ae (end 06b2): drL:set_solid( false )
06b0 (end 06b2): drL:set_visible( false )
06b2 (end 06b2): drL:set_default_animation( "0" ) -- speed=1
                 drL:play_animation( "0" )
06b5 (end 06b5): drL:set_solid( false )
06b7 (end 06b7): return;
06b8 (end 06b8): jumpto( 06b8 );

script_3:
06bb (end 06bb): drL:offset_to_position( -202, 0, 0, Field.LINEAR, 1.66667 );
06c7 (end 06c7): drL:set_offset_wait();
06c8 (end 06c8): drL:set_talkable( false );
06ca (end 06ca): drL:set_solid( false )
06cc (end 06cc): drL:set_visible( false )
06ce (end 06ce): return;

drR
script_0:
06cf (end 06cf): -- assosiate entity with model (CHAR) argument doesn't matter
06d1 (end 06d1): drR:set_position( 9.86719, 14.25, 10.1406 ) -- triangle_id=60
06dc (end 06dc): drR:set_direction( 174.375 )
06df (end 06df): if ( game:variable_get( "progress_game" ) >= 7 ) then continue else jumpto(06ed);
06e7 (end 06ed): drR:set_talkable( false );
06e9 (end 06ed): drR:set_solid( false )
06eb (end 06ed): drR:set_visible( false )
06ed (end 06ed): drR:set_default_animation( "0" ) -- speed=1
                 drR:play_animation( "0" )
06f0 (end 06f0): drR:set_solid( false )
06f2 (end 06f2): return;
06f3 (end 06f3): jumpto( 06f3 );

script_3:
06f6 (end 06f6): drR:offset_to_position( 184, 0, 0, Field.LINEAR, 1.66667 );
0702 (end 0702): drR:set_offset_wait();
0703 (end 0703): drR:set_talkable( false );
0705 (end 0705): drR:set_solid( false )
0707 (end 0707): drR:set_visible( false )
0709 (end 0709): return;

unnamed_8
script_0:
070a (end 070a): return;
070b (end 070b): if ( temp5_15 == 1 ) then continue else jumpto(0729);
0711 (end 0729): if ( temp5_0b == 0 ) then continue else jumpto(0729);
0717 (end 0729): temp6_09 = field:get_movie_frame();
071a (end 0729): if ( temp6_09 > 30 ) then continue else jumpto(0729);
0722 (end 0729): temp5_0b = 1;
0726 (end 0729): script:request( "cl", "script_9", 6 );
0729 (end 0729): jumpto( 070b );

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
