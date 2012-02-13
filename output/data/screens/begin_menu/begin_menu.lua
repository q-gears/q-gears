if UiContainer == nil then UiContainer = {} end



UiContainer.BeginMenu = {
    position = 1,
    position_total = 2,



    on_start = function( self )
        local cursor = ui_manager:get_widget( "BeginMenu.Container.Cursor" )
        cursor:set_default_animation( "Position" .. self.position )

        --script:request( "UiContainer.BeginMenu", "show", 0 )

        return 0
    end,



    on_button = function( self, button, event )
        if ui_manager:get_widget( "BeginMenu" ):is_visible() ~= false then
            local cursor = ui_manager:get_widget( "BeginMenu.Container.Cursor" )

            if button == "X" and event == "Press" then
                if self.position == 1 then
                    script:request_end_sync( "UiContainer.BeginMenu", "hide", 0 )
                    script:request_end_sync( "UiContainer.MainMenu", "show", 0 )
                else
                    script:request_end_sync( "UiContainer.BeginMenu", "hide", 0 )
                    script:request_end_sync( "UiContainer.Idol", "show", 0 )
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
