Ui = {}



Ui[ "TestScreen" ] = {
    on_start = function()
        return 0
    end,

    on_show = function()
        ui_manager:get_widget( "TestScreen.Right" ):show()
        ui_manager:get_widget( "TestScreen.Left" ):show()
        ui_manager:get_widget( "TestScreen.Left.LeftRow1" ):show()
        return 0
    end,

    on_hide = function()
        ui_manager:get_widget( "TestScreen.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Left.LeftRow1" ):hide()
        return 0
    end,
}
