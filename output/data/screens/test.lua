if Ui == nil then Ui = {} end



Ui.TestScreen = {
    on_start = function()
        return 0
    end,

    on_show = function()
        return 0
    end,

    on_hide = function()
        return 0
    end,
}



Ui.TestScreen.Dialog0 = {
    on_start = function()
        local dialog = ui_manager:get_widget( "TestScreen.Dialog0" )
        dialog:play_animation( "Appear" )
        return 0
    end,

    on_show = function()
        return 0
    end,

    on_hide = function()
        return 0
    end,
}