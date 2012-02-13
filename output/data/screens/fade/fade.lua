if UiContainer == nil then UiContainer = {} end



UiContainer.Fade = {
    fade_in = function( self )
        local fade = ui_manager:get_widget( "Fade.Screen" )
        fade:play_animation_stop( "FadeIn" )
        fade:animation_sync()

        return 0;
    end,



    fade_out = function( self )
        local fade = ui_manager:get_widget( "Fade.Screen" )
        fade:play_animation_stop( "FadeOut" )
        fade:animation_sync()

        return 0;
    end,
}
