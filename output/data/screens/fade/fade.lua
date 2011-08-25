if Ui == nil then Ui = {} end



Ui.Fade = {
    fade_in = function( self )
        local fade = ui_manager:get_widget( "Fade" )
        fade:play_animation_stop( "FadeIn" )
        fade:animation_sync()

        return 0;
    end,



    fade_out = function( self )
        local fade = ui_manager:get_widget( "Fade" )
        fade:play_animation_stop( "FadeOut" )
        fade:animation_sync()

        return 0;
    end,
}
