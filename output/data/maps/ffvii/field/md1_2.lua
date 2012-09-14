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

        if FFVII.Data.progress_game < 8 then
            self.biggs:set_visible( true )
            self.biggs:set_move_auto_speed( 3.75 )
            self.biggs:move_to_position( 28.4844, 243.898 )
            self.biggs:move_sync()
            -- this needs to be called after some sync because other entity check this in on_start too.
            FFVII.Data.progress_game = 8
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
        self.jessie:set_rotation( 354.375 )
        self.jessie:set_position( 27.9219, 253.773, 4.96875 )
        self.jessie:set_solid( false )

        if FFVII.Data.progress_game < 8 then
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
        self.wedge:set_rotation( 354.375 )
        self.wedge:set_position( 34.0312, 247.484, 5.09375 )
        self.wedge:set_solid( false )

        if FFVII.Data.progress_game < 8 then
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



EntityContainer[ "BackgroundLight0" ] = {
    on_start = function( self )
        background2d:play_animation_looped( "Light0" )

        return 0
    end,
}



EntityContainer[ "BackgroundLight1" ] = {
    on_start = function( self )
        script:wait( 0.133333 )
        background2d:play_animation_looped( "Light1" )

        return 0
    end,
}



EntityContainer[ "BackgroundLight2" ] = {
    on_start = function( self )
        while true do
            local number = math.random( 1, 3 )
            background2d:play_animation_once( "Light2_" .. number )
            background2d:animation_sync( "Light2_" .. number )
        end

        return 0
    end,
}



EntityContainer[ "BackgroundWarning" ] = {
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
                background2d:play_animation_once( "Warning" .. temp5_27 .. "Zizizi" )
                background2d:animation_sync( "Warning" .. temp5_27 .. "Zizizi" )
            end

            background2d:play_animation_once( "Warning" .. temp5_27 .. "Light" )
            background2d:animation_sync( "Warning" .. temp5_27 .. "Light" )
            script:wait( 0.0333333 )
            background2d:play_animation_once( "Warning" .. temp5_27 .. "Light" )
            background2d:animation_sync( "Warning" .. temp5_27 .. "Light" )
            script:wait( 0.0333333 )
            background2d:play_animation_once( "Warning" .. temp5_27 .. "Light" )
            background2d:animation_sync( "Warning" .. temp5_27 .. "Light" )
            background2d:play_animation_once( "WarningBlank" )
            background2d:animation_sync( "WarningBlank" )
            script:wait( 0.0333333 )

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