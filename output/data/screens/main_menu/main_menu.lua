if UiContainer == nil then UiContainer = {} end



UiContainer.MainMenu = {
    position = 1,
    position_total = 10,



    on_start = function( self )
        return 0
    end,



    on_button = function( self, button, event )
        if ui_manager:get_widget( "MainMenu" ):is_visible() == true then
            local characters  = ui_manager:get_widget( "MainMenu.Container.Characters" )
            local menu        = ui_manager:get_widget( "MainMenu.Container.Menu" )
            local menu_cursor = ui_manager:get_widget( "MainMenu.Container.Menu.Cursor" )
            local timegil     = ui_manager:get_widget( "MainMenu.Container.TimeGil" )
            local location    = ui_manager:get_widget( "MainMenu.Container.Location" )

            if button == "Escape" and event == "Press" then
                script:request_end_sync( Script.UI, "MainMenu", "hide", 0 )
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
        elseif FFVII.MenuSettings.available == true then
            if button == "Space" and event == "Press" then
                script:request_end_sync( Script.UI, "MainMenu", "show", 0 )
            end
        end

        return 0
    end,



    show = function( self )
        entity_manager:set_paused( true )
        FFVII.MenuSettings.pause_available = false

        ui_manager:get_widget( "MainMenu" ):set_visible( true )

        local characters  = ui_manager:get_widget( "MainMenu.Container.Characters" )
        local menu        = ui_manager:get_widget( "MainMenu.Container.Menu" )
        local menu_cursor = ui_manager:get_widget( "MainMenu.Container.Menu.Cursor" )
        local timegil     = ui_manager:get_widget( "MainMenu.Container.TimeGil" )
        local location    = ui_manager:get_widget( "MainMenu.Container.Location" )

        ui_manager:get_widget( "MainMenu.Container.Menu.PHSText" ):set_visible( false )
        ui_manager:get_widget( "MainMenu.Container.Menu.SaveText" ):set_colour( 0.4, 0.4, 0.4 )

        characters:play_animation_stop( "Appear" )
        menu:play_animation_stop( "Appear" )
        menu_cursor:set_default_animation( "Position" .. self.position )
        timegil:play_animation_stop( "Appear" )
        location:play_animation_stop( "Appear" )
        location:animation_sync()

        return 0;
    end,



    hide = function( self )
        local characters  = ui_manager:get_widget( "MainMenu.Container.Characters" )
        local menu        = ui_manager:get_widget( "MainMenu.Container.Menu" )
        local timegil     = ui_manager:get_widget( "MainMenu.Container.TimeGil" )
        local location    = ui_manager:get_widget( "MainMenu.Container.Location" )

        characters:play_animation_stop( "Disappear" )
        menu:play_animation_stop( "Disappear" )
        timegil:play_animation_stop( "Disappear" )
        location:play_animation_stop( "Disappear" )
        location:animation_sync()

        ui_manager:get_widget( "MainMenu" ):set_visible( false )

        FFVII.MenuSettings.pause_available = true
        entity_manager:set_paused( false )

        return 0;
    end,
}
