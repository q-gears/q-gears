if Ui == nil then Ui = {} end



Ui.BeginMenu = {
    position = 1,
    position_total = 10,



    on_start = function( self )
        local cursor = ui_manager:get_widget( "BeginMenu.Cursor" )
        cursor:set_default_animation( "Position" .. self.position )
        return 0
    end,



    on_pressed = function( self, button )
        local cursor = ui_manager:get_widget( "BeginMenu.Cursor" )

        if button == "X" then
            if self.position == 1 then
                --script:request_end_sync( "Ui.BeginMenu", "to_start", 0 )
            else
                --script:request_end_sync( "Ui.BeginMenu", "to_continue", 0 )
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

        return 0
    end,
}
