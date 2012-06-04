EntityContainer = {}



EntityContainer[ "Director" ] = {
    on_start = function( self )
        background2d:autoscroll_to_entity( entity_manager:get_entity( "Cloud" ) )
        --0358 (end 0358): [UNREVERSED] BTLMD(20, 00);
        --035b (end 035b): music:execute_akao( 10, pointer_to_field_AKAO_0 ); -- play field music
        --035d (end 035d): field:map_name(2);

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
}



EntityContainer[ "Biggs" ] = {
    biggs = nil,

    on_start = function( self )
        self.biggs = entity_manager:get_entity( "Biggs" )

        self.biggs:set_position( 26.8516, 246.281, 5.01562 )
        self.biggs:set_solid( false )

        if Savemap.progress_game < 8 then
            self.biggs:set_visible( true )
            self.biggs:set_move_auto_speed( 3.75 )
            self.biggs:move_to_position( 28.4844, 243.898 )
            self.biggs:move_sync()
            -- this needs to be called after some sync because other entity check this in on_start too.
            Savemap.progress_game = 8
            self.biggs:play_animation( "LookAround" )
            self.biggs:animation_sync()
            self.biggs:move_to_position( 33.4141, 244.211 )
            self.biggs:move_sync()
            self.biggs:move_to_position( 34.0938, 250.406 )
            self.biggs:move_sync()
            self.biggs:move_to_position( 26.4141, 252.445 )
            self.biggs:move_sync()
            self.biggs:move_to_position( 23.5156, 252.734 )
            self.biggs:move_sync()
        end

        self.biggs:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Jessie" ] = {
    jessie = nil,

    on_start = function( self )
        self.jessie = entity_manager:get_entity( "Jessie" )

        self.jessie:set_default_animation( "LookAround" )
        self.jessie:play_animation( "LookAround" )
        self.jessie:set_move_auto_speed( 3.75 )
        self.jessie:set_direction( 354.375 )
        self.jessie:set_position( 27.9219, 253.773, 4.96875 )
        self.jessie:set_solid( false )

        if Savemap.progress_game < 8 then
            self.jessie:set_visible( true )
            script:wait( 8.5 )
            self.jessie:move_to_position( 26.4141, 252.445 )
            self.jessie:move_sync()
            self.jessie:move_to_position( 23.5156, 252.734 )
            self.jessie:move_sync()
        end

        self.jessie:set_visible( false )

        return 0
    end,
}



EntityContainer[ "Wedge" ] = {
    wedge = nil,

    on_start = function( self )
        self.wedge = entity_manager:get_entity( "Wedge" )
        self.wedge:set_default_animation( "LookAround" )
        self.wedge:play_animation( "LookAround" )
        self.wedge:set_move_auto_speed( 3.75 )
        self.wedge:set_direction( 354.375 )
        self.wedge:set_position( 34.0312, 247.484, 5.09375 )
        self.wedge:set_solid( false )

        if Savemap.progress_game < 8 then
            self.wedge:set_visible( true )
            script:wait( 4.26667 )
            self.wedge:move_to_position( 33.6875, 250.664 )
            self.wedge:move_sync()
            self.wedge:move_to_position( 26.4141, 252.445 )
            self.wedge:move_sync()
            self.wedge:move_to_position( 23.5156, 252.734 )
            self.wedge:move_sync()
        end

        self.wedge:set_visible( false )

        return 0
    end,
}



--[[
light0
script_0:
045e (end 045e): temp5_1c = 0;
0462 (end 0462): temp5_1f = 255;
0466 (end 0466): return
0467 (end 0467): [UNREVERSED] STPLS( 0d, 20, 00, 0f );
046c (end 046c): if ( temp5_1c == 0 ) then continue else jumpto(0484);
0472 (end 0484): if ( temp5_1f > 250 ) then continue else jumpto(047d);
0478 (end 0484): temp5_1f = temp5_1f - 1;
047b (end 0484): jumpto( 0484 );
047d (end 0484): temp5_1c = 1;
0481 (end 0484): script:wait( 0.133333 )
0484 (end 0484): if ( temp5_1c == 1 ) then continue else jumpto(049c);
048a (end 049c): if ( temp5_1f < 255 ) then continue else jumpto(0495);
0490 (end 049c): temp5_1f = temp5_1f + 1;
0493 (end 049c): jumpto( 049c );
0495 (end 049c): temp5_1c = 0;
0499 (end 049c): script:wait( 0.133333 )
049c (end 049c): [UNREVERSED] ADPAL( 00, 55, 50, 20, 2a, 1f, 1f, 1f, 1f );
04a6 (end 04a6): [UNREVERSED] LDPLS( 2a, 0d, 00, 0f );
04ab (end 04ab): script:wait( 0.0666667 )
04ae (end 04ae): jumpto( 046c );

light1
script_0:
04b1 (end 04b1): temp5_1d = 0;
04b5 (end 04b5): temp5_20 = 255;
04b9 (end 04b9): return
04ba (end 04ba): [UNREVERSED] STPAL( 00, 0e, 22, 1f );
04bf (end 04bf): script:wait( 0.133333 )
04c2 (end 04c2): if ( temp5_1d == 0 ) then continue else jumpto(04da);
04c8 (end 04da): if ( temp5_20 > 250 ) then continue else jumpto(04d3);
04ce (end 04da): temp5_20 = temp5_20 - 1;
04d1 (end 04da): jumpto( 04da );
04d3 (end 04da): temp5_1d = 1;
04d7 (end 04da): script:wait( 0.133333 )
04da (end 04da): if ( temp5_1d == 1 ) then continue else jumpto(04f2);
04e0 (end 04f2): if ( temp5_20 < 255 ) then continue else jumpto(04eb);
04e6 (end 04f2): temp5_20 = temp5_20 + 1;
04e9 (end 04f2): jumpto( 04f2 );
04eb (end 04f2): temp5_1d = 0;
04ef (end 04f2): script:wait( 0.133333 )
04f2 (end 04f2): [UNREVERSED] ADPAL( 00, 55, 50, 22, 2c, 20, 20, 20, 1f );
04fc (end 04fc): [UNREVERSED] LDPAL( 00, 2c, 0e, 1f );
0501 (end 0501): script:wait( 0.0666667 )
0504 (end 0504): jumpto( 04c2 );

light2
script_0:
0507 (end 0507): field:background_clear( "2" ); -- turns off all layer of background animation with given id
050a (end 050a): field:background_on( "2", 0 ); -- turns on layer of background animation with given id
050e (end 050e): temp5_21 = 255;
0512 (end 0512): return
0513 (end 0513): [UNREVERSED] STPLS( 0d, 24, 10, 1f );
0518 (end 0518): temp5_21 = 255;
051c (end 051c): if ( temp5_21 > 252 ) then continue else jumpto(0539);
0522 (end 0539): [UNREVERSED] ADPAL( 00, 55, 50, 24, 2e, 21, 21, 21, 1f );
052c (end 0539): [UNREVERSED] LDPLS( 2e, 0d, 10, 1f );
0531 (end 0539): temp5_21 = temp5_21 - 1;
0534 (end 0539): script:wait( 0.0666667 )
0537 (end 0539): jumpto( 051c );
0539 (end 0539): [UNREVERSED] LDPLS( 24, 0d, 10, 1f );
053e (end 053e): temp5_21 = math.rand();
0541 (end 0541): temp5_21 = temp5_21 % 3;
0545 (end 0545): temp5_21 = temp5_21 + 1;
0548 (end 0548): if ( temp5_21 > 0 ) then continue else jumpto(055e);
054e (end 055e): field:background_off( "2", 0 ); -- turns off layer of background animation with given id
0552 (end 055e): script:wait( 0.0333333 )
0555 (end 055e): field:background_on( "2", 0 ); -- turns on layer of background animation with given id
0559 (end 055e): temp5_21 = temp5_21 - 1;
055c (end 055e): jumpto( 0548 );
055e (end 055e): script:wait( 2 )
0561 (end 0561): jumpto( 0518 );

warning
script_0:
0564 (end 0564): field:background_clear( "1" ); -- turns off all layer of background animation with given id
0567 (end 0567): field:background_off( "1", 0 ); -- turns off layer of background animation with given id
056b (end 056b): temp5_18 = 0;
056f (end 056f): temp5_1b = 255;
0573 (end 0573): return
0574 (end 0574): [UNREVERSED] STPAL( 00, 0b, 00, ff );
0579 (end 0579): temp5_1b = temp5_1b + 1;
057d (end 057d): if ( temp5_1b > 2 ) then continue else jumpto(0587);
0583 (end 0587): temp5_1b = 0;
0587 (end 0587): script:request_end_sync( "zizizi", "script_1", 2 )
058a (end 058a): field:background_on( "1", temp5_1b ); -- turns on layer of background animation with given id
058e (end 058e): script:request_end_sync( "light", "script_1", 2 )
0591 (end 0591): [UNREVERSED] LDPAL( 00, 00, 0b, ff );
0596 (end 0596): script:wait( 0.0333333 )
0599 (end 0599): script:request_end_sync( "light", "script_1", 2 )
059c (end 059c): [UNREVERSED] LDPAL( 00, 00, 0b, ff );
05a1 (end 05a1): script:wait( 0.0333333 )
05a4 (end 05a4): script:request_end_sync( "light", "script_1", 2 )
05a7 (end 05a7): field:background_off( "1", temp5_1b ); -- turns off layer of background animation with given id
05ab (end 05ab): [UNREVERSED] LDPAL( 00, 00, 0b, ff );
05b0 (end 05b0): script:wait( 0.0333333 )
05b3 (end 05b3): jumpto( 0579 );

light
script_0:
05b5 (end 05b5): return
05b6 (end 05b6): return

script_1:
05b7 (end 05b7): temp5_18 = 66;
05bb (end 05bb): if ( temp5_18 < 98 ) then continue else jumpto(05de);
05c1 (end 05de): temp5_18 = temp5_18 + 16;
05c5 (end 05de): [UNREVERSED] MPPAL2( 00, 55, 50, 00, 10, 18, 18, 18, ff );
05cf (end 05de): [UNREVERSED] CPPAL( 00, 00, 10, 00 );
05d4 (end 05de): [UNREVERSED] LDPAL( 00, 10, 0b, ff );
05d9 (end 05de): script:wait( 0.0666667 )
05dc (end 05de): jumpto( 05bb );
05de (end 05de): if ( temp5_18 > 4 ) then continue else jumpto(0601);
05e4 (end 0601): temp5_18 = temp5_18 - 24;
05e8 (end 0601): [UNREVERSED] MPPAL2( 00, 55, 50, 00, 10, 18, 18, 18, ff );
05f2 (end 0601): [UNREVERSED] CPPAL( 00, 00, 10, 00 );
05f7 (end 0601): [UNREVERSED] LDPAL( 00, 10, 0b, ff );
05fc (end 0601): script:wait( 0.0666667 )
05ff (end 0601): jumpto( 05de );
0601 (end 0601): return

zizizi
script_0:
0602 (end 0602): return
0603 (end 0603): return

script_1:
0604 (end 0604): temp5_19 = 0;
0608 (end 0608): temp5_1a = math.rand();
060b (end 060b): temp5_1a = temp5_1a % 4;
060f (end 060f): if ( temp5_1a == 0 ) then continue else jumpto(0619);
0615 (end 0619): temp5_1a = 1;
0619 (end 0619): if ( temp5_19 < temp5_1a ) then continue else jumpto(0640);
061f (end 0640): field:background_on( "1", temp5_1b ); -- turns on layer of background animation with given id
0623 (end 0640): script:wait( 0.0333333 )
0626 (end 0640): field:background_off( "1", temp5_1b ); -- turns off layer of background animation with given id
062a (end 0640): script:wait( 0.0333333 )
062d (end 0640): field:background_on( "1", 3 ); -- turns on layer of background animation with given id
0631 (end 0640): script:wait( 0.0333333 )
0634 (end 0640): field:background_off( "1", 3 ); -- turns off layer of background animation with given id
0638 (end 0640): script:wait( 0.0333333 )
063b (end 0640): temp5_19 = temp5_19 + 1;
063e (end 0640): jumpto( 0619 );
0640 (end 0640): return
]]




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
        if entity == "Cloud" then
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