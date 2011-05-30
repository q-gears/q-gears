main_menu_buttons = {
    Init = function()
    end

    StartScreen = function()
        SetLock( true )
        global:PlaySoundSample( "gui_menu_show" )
        show_anim:Restart( "Buttons" )
    end

    StopScreen = function()
        global:PlaySoundSample( "gui_menu_hide" )
        hide_anim:Restart( "Buttons" )
        SetLock( false )
    end
}
