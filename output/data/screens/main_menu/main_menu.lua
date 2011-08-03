if Ui == nil then Ui = {} end



Ui.MainMenu = {
    position = 1,
    position_total = 10,



    on_start = function( self )
        local characters  = ui_manager:get_widget( "MainMenu.Characters" )
        local menu        = ui_manager:get_widget( "MainMenu.Menu" )
        local menu_cursor = ui_manager:get_widget( "MainMenu.Menu.Cursor" )
        local timegil     = ui_manager:get_widget( "MainMenu.TimeGil" )
        local location    = ui_manager:get_widget( "MainMenu.Location" )

        menu_cursor:set_default_animation( "Position" .. self.position )

        characters:play_animation_stop( "Appear" )
        menu:play_animation_stop( "Appear" )
        timegil:play_animation_stop( "Appear" )
        location:play_animation_stop( "Appear" )
        location:animation_sync()

        return 0
    end,



    on_pressed = function( self, button )
        local characters  = ui_manager:get_widget( "MainMenu.Characters" )
        local menu        = ui_manager:get_widget( "MainMenu.Menu" )
        local menu_cursor = ui_manager:get_widget( "MainMenu.Menu.Cursor" )
        local timegil     = ui_manager:get_widget( "MainMenu.TimeGil" )
        local location    = ui_manager:get_widget( "MainMenu.Location" )

        if button == "Z" then
            characters:play_animation_stop( "Disappear" )
            menu:play_animation_stop( "Disappear" )
            timegil:play_animation_stop( "Disappear" )
            location:play_animation_stop( "Disappear" )
            location:animation_sync()
        elseif button == "S" then
            characters:play_animation_stop( "Appear" )
            menu:play_animation_stop( "Appear" )
            timegil:play_animation_stop( "Appear" )
            location:play_animation_stop( "Appear" )
            location:animation_sync()
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

        return 0
    end,
}
