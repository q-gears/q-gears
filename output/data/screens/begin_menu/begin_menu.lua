if UiContainer == nil then UiContainer = {} end



UiContainer.BeginMenu = {
    position = 1,
    position_total = 5,



    on_start = function( self )
        local cursor = ui_manager:get_widget( "BeginMenu.Container.Cursor" )
        cursor:set_default_animation( "Position" .. self.position )

        return 0
    end,



    on_button = function( self, button, event )
        if ui_manager:get_widget( "BeginMenu" ):is_visible() ~= false then
            local cursor = ui_manager:get_widget( "BeginMenu.Container.Cursor" )

            if button == "Enter" and event == "Press" then
                if self.position == 1 then
                    load_field_map_request( "ffvii_md1stin", "" )
                    console( "camera_free false" )
                    console( "debug_walkmesh false" )
                    script:request_end_sync( Script.UI, "BeginMenu", "hide", 0 )
                    FFVII.MenuSettings.pause_available = true
                elseif self.position == 2 then
                    script:request_end_sync( Script.UI, "BeginMenu", "hide", 0 )
                    console( "camera_free true" )
                    console( "debug_walkmesh true" )
                    map( "test_3" )
                    FFVII.MenuSettings.pause_available = true
                elseif self.position == 3 then
                    script:request_end_sync( Script.UI, "BeginMenu", "hide", 0 )
                    console( "camera_free true" )
                    console( "debug_walkmesh true" )
                    map( "test_1" )
                    FFVII.MenuSettings.pause_available = true
                elseif self.position == 4 then
                    script:request_end_sync( Script.UI, "BeginMenu", "hide", 0 )
                    console( "camera_free true" )
                    console( "debug_walkmesh true" )
                    map( "test_2" )
                    FFVII.MenuSettings.pause_available = true
                elseif self.position == 5 then
                    script:request_end_sync( Script.UI, "BeginMenu", "hide", 0 )
                    script:request_end_sync( Script.UI, "Idol", "show", 0 )
                end
            elseif button == "Down" then
                self.position = self.position + 1
                if self.position > self.position_total then
                    self.position = 1;
                end
                cursor:set_default_animation( "Position" .. self.position )
            elseif button == "Up" then
                self.position = self.position - 1
                if self.position <= 0 then
                    self.position = self.position_total;
                end
                cursor:set_default_animation( "Position" .. self.position )
            end
        end

        return 0
    end,



    show = function( self )
        ui_manager:get_widget( "BeginMenu" ):set_visible( true )

        return 0;
    end,



    hide = function( self )
        ui_manager:get_widget( "BeginMenu" ):set_visible( false )

        return 0;
    end,
}
