if UiContainer == nil then UiContainer = {} end



UiContainer.PauseMenu = {
    position = 1,
    position_total = 2,



    on_start = function( self )
        return 0
    end,



    on_button = function( self, button, event )
        if ui_manager:get_widget( "PauseMenu" ):is_visible() == true then
            local menu_cursor = ui_manager:get_widget( "PauseMenu.Menu.Cursor" )

            if button == "Enter" and event == "Press" then
                script:request_end_sync( Script.UI, "PauseMenu", "hide", 0 )
                if self.position == 1 then
                    script:request_end_sync( Script.UI, "BeginMenu", "show", 0 )
                    map( "empty" )
                    FFVII.MenuSettings.pause_available = false
                else
                    FFVII.MenuSettings.available = true
                end
            elseif button == "Escape" and event == "Press" then
                script:request_end_sync( Script.UI, "PauseMenu", "hide", 0 )
                FFVII.MenuSettings.available = true
            elseif button == "Right" then
                self.position = self.position + 1
                if self.position > self.position_total then
                    self.position = 1;
                end
                menu_cursor:set_default_animation( "Position" .. self.position )
            elseif button == "Left" then
                self.position = self.position - 1
                if self.position <= 0 then
                    self.position = self.position_total;
                end
                menu_cursor:set_default_animation( "Position" .. self.position )
            end
        elseif FFVII.MenuSettings.pause_available == true then
            if button == "Enter" and event == "Press" then
                FFVII.MenuSettings.available = false
                script:request_end_sync( Script.UI, "PauseMenu", "show", 0 )
            end
        end

        return 0
    end,



    show = function( self )
        entity_manager:set_paused( true )

        ui_manager:get_widget( "PauseMenu" ):set_visible( true )

        return 0;
    end,



    hide = function( self )
        ui_manager:get_widget( "PauseMenu" ):set_visible( false )

        entity_manager:set_paused( false )

        return 0;
    end,
}
