if Ui == nil then Ui = {} end



Ui.MainMenu = {
    position = 1,
    position_total = 10,



    on_start = function( self )
        script:request( "Ui.MainMenu", "show", 0 )

        return 0
    end,



    on_button = function( self, button, event )
        if ui_manager:get_widget( "MainMenu" ):is_visible() == true then
            local characters  = ui_manager:get_widget( "MainMenu.Characters" )
            local menu        = ui_manager:get_widget( "MainMenu.Menu" )
            local menu_cursor = ui_manager:get_widget( "MainMenu.Menu.Cursor" )
            local timegil     = ui_manager:get_widget( "MainMenu.TimeGil" )
            local location    = ui_manager:get_widget( "MainMenu.Location" )

            if button == "Z" and event == "Press" then
                script:request_end_sync( "Ui.MainMenu", "hide", 0 )
                script:request_end_sync( "Ui.BeginMenu", "show", 0 )
            elseif button == "Down" then
                self.position = self.position + 1
                if self.position > self.position_total then
                    self.position = 1;
                end
                menu_cursor:set_default_animation( "Position" .. self.position )
            elseif button == "Up" then
                self.position = self.position - 1
                if self.position <= 0 then
                    self.position = self.position_total;
                end
                menu_cursor:set_default_animation( "Position" .. self.position )
            end
        end

        return 0
    end,



    show = function( self )
        ui_manager:get_widget( "MainMenu" ):set_visible( true )

        local characters  = ui_manager:get_widget( "MainMenu.Characters" )
        local menu        = ui_manager:get_widget( "MainMenu.Menu" )
        local menu_cursor = ui_manager:get_widget( "MainMenu.Menu.Cursor" )
        local timegil     = ui_manager:get_widget( "MainMenu.TimeGil" )
        local location    = ui_manager:get_widget( "MainMenu.Location" )

        ui_manager:get_widget( "MainMenu.Menu.PHSText" ):set_visible( false )
        ui_manager:get_widget( "MainMenu.Menu.SaveText" ):set_colour( 0.4, 0.4, 0.4 )

        characters:play_animation_stop( "Appear" )
        menu:play_animation_stop( "Appear" )
        menu_cursor:set_default_animation( "Position" .. self.position )
        timegil:play_animation_stop( "Appear" )
        location:play_animation_stop( "Appear" )
        location:animation_sync()

        return 0;
    end,



    hide = function( self )
        local characters  = ui_manager:get_widget( "MainMenu.Characters" )
        local menu        = ui_manager:get_widget( "MainMenu.Menu" )
        local timegil     = ui_manager:get_widget( "MainMenu.TimeGil" )
        local location    = ui_manager:get_widget( "MainMenu.Location" )

        characters:play_animation_stop( "Disappear" )
        menu:play_animation_stop( "Disappear" )
        timegil:play_animation_stop( "Disappear" )
        location:play_animation_stop( "Disappear" )
        location:animation_sync()

        ui_manager:get_widget( "MainMenu" ):set_visible( false )

        return 0;
    end,
}
