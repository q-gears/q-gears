if UiContainer == nil then UiContainer = {} end



UiContainer.Idol = {
    picture_number = 8,
    picture_state = {},
    picture_animation_number = 3,
    picture_current = 4,



    on_start = function( self )
        --script:request( Script.UI, "Idol", "show", 0 )

        for i = 1, self.picture_number, 1 do
            self.picture_state[ i ] = {}
            self.picture_state[ i ].animation = math.random ( 1, self.picture_animation_number )

            if i == self.picture_current then
                ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "RightToCenter" .. self.picture_state[ i ].animation, -1, -1 )
                ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0 )
                ui_manager:get_widget( "Idol.Name" .. i ):set_visible( true )
            elseif i > self.picture_current then
                ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "RightToCenter" .. self.picture_state[ i ].animation, 0, 0 )
                ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0.01 * ( i - self.picture_current ) )
                ui_manager:get_widget( "Idol.Name" .. i ):set_visible( false )
            else
                ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "CenterToLeft" .. self.picture_state[ i ].animation, -1, -1 )
                ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0.01 * ( self.picture_current - i ) )
                ui_manager:get_widget( "Idol.Name" .. i ):set_visible( false )
            end
        end

        return 0
    end,



    on_button = function( self, button, event )
        if ui_manager:get_widget( "Idol" ):is_visible() ~= false then
            if button == "Escape" and event == "Press" then
                script:request_end_sync( Script.UI, "Idol", "hide", 0 )
                script:request_end_sync( Script.UI, "BeginMenu", "show", 0 )
            elseif button == "Left" then
                if self.picture_current < self.picture_number then

                    ui_manager:get_widget( "Idol.ArrowLeft" ):play_animation( "Press" )
                    self.picture_current = self.picture_current + 1
                    if self.picture_current == self.picture_number then
                        ui_manager:get_widget( "Idol.ArrowLeft" ):set_colour( 0.5, 0.5, 0.5 )
                        ui_manager:get_widget( "Idol.ArrowLeft" ):set_alpha( 0.5 )
                    end
                    ui_manager:get_widget( "Idol.ArrowRight" ):set_colour( 1, 1, 1 )
                    ui_manager:get_widget( "Idol.ArrowRight" ):set_alpha( 1 )

                    for i = 1, self.picture_number, 1 do
                        if i == self.picture_current then
                            ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "RightToCenter" .. self.picture_state[ i ].animation )
                        elseif i == self.picture_current - 1 then
                            ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "CenterToLeft" .. self.picture_state[ i ].animation )
                        end

                        if i == self.picture_current then
                            ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0 )
                            ui_manager:get_widget( "Idol.Name" .. i ):set_visible( true )
                        elseif i > self.picture_current then
                            ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0.01 * ( i - self.picture_current ) )
                            ui_manager:get_widget( "Idol.Name" .. i ):set_visible( false )
                        else
                            ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0.01 * ( self.picture_current - i ) )
                            ui_manager:get_widget( "Idol.Name" .. i ):set_visible( false )
                        end
                    end

                    ui_manager:get_widget( "Idol.Picture" .. self.picture_current ):animation_sync()
                end
            elseif button == "Right" then
                if self.picture_current > 1 then

                    ui_manager:get_widget( "Idol.ArrowRight" ):play_animation( "Press" )
                    self.picture_current = self.picture_current - 1
                    if self.picture_current == 1 then
                        ui_manager:get_widget( "Idol.ArrowRight" ):set_colour( 0.5, 0.5, 0.5 )
                        ui_manager:get_widget( "Idol.ArrowRight" ):set_alpha( 0.5 )
                    end
                    ui_manager:get_widget( "Idol.ArrowLeft" ):set_colour( 1, 1, 1 )
                    ui_manager:get_widget( "Idol.ArrowLeft" ):set_alpha( 1 )

                    for i = 1, self.picture_number, 1 do
                        if i == self.picture_current then
                            ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "LeftToCenter" .. self.picture_state[ i ].animation )
                        elseif i == self.picture_current + 1 then
                            ui_manager:get_widget( "Idol.Picture" .. i ):play_animation_stop( "CenterToRight" .. self.picture_state[ i ].animation )
                        end

                        if i == self.picture_current then
                            ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0 )
                            ui_manager:get_widget( "Idol.Name" .. i ):set_visible( true )
                        elseif i > self.picture_current then
                            ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0.01 * ( i - self.picture_current ) )
                            ui_manager:get_widget( "Idol.Name" .. i ):set_visible( false )
                        else
                            ui_manager:get_widget( "Idol.Picture" .. i ):set_z( 0.01 * ( self.picture_current - i ) )
                            ui_manager:get_widget( "Idol.Name" .. i ):set_visible( false )
                        end
                    end

                    ui_manager:get_widget( "Idol.Picture" .. self.picture_current ):animation_sync()
                end
            end
        end

        return 0
    end,



    show = function( self )
        ui_manager:get_widget( "Idol" ):set_visible( true )

        return 0;
    end,



    hide = function( self )
        ui_manager:get_widget( "Idol" ):set_visible( false )

        return 0;
    end,
}
