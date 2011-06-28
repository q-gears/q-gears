Ui = {}



Ui[ "TestScreen" ] = {
    on_start = function()
        return 0
    end,

    on_show = function()
        ui_manager:get_widget( "TestScreen.Right" ):show()
        ui_manager:get_widget( "TestScreen.Right.Top" ):show()
        ui_manager:get_widget( "TestScreen.Right.Bottom" ):show()
        ui_manager:get_widget( "TestScreen.Left" ):show()
        ui_manager:get_widget( "TestScreen.Left.Top" ):show()
        ui_manager:get_widget( "TestScreen.Left.Bottom" ):show()
        ui_manager:get_widget( "TestScreen.Bottom" ):show()
        ui_manager:get_widget( "TestScreen.Bottom.Left" ):show()
        ui_manager:get_widget( "TestScreen.Bottom.Right" ):show()
        ui_manager:get_widget( "TestScreen.Top" ):show()
        ui_manager:get_widget( "TestScreen.Top.Left" ):show()
        ui_manager:get_widget( "TestScreen.Top.Right" ):show()
        ui_manager:get_widget( "TestScreen.Center" ):show()
        ui_manager:get_widget( "TestScreen.Center.LeftTop" ):show()
        ui_manager:get_widget( "TestScreen.Center.RightTop" ):show()
        ui_manager:get_widget( "TestScreen.Center.LeftBottom" ):show()
        ui_manager:get_widget( "TestScreen.Center.RightBottom" ):show()
        return 0
    end,

    on_hide = function()
        ui_manager:get_widget( "TestScreen.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Right.Top" ):hide()
        ui_manager:get_widget( "TestScreen.Right.Bottom" ):hide()
        ui_manager:get_widget( "TestScreen.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Left.Top" ):hide()
        ui_manager:get_widget( "TestScreen.Left.Bottom" ):hide()
        ui_manager:get_widget( "TestScreen.Bottom" ):hide()
        ui_manager:get_widget( "TestScreen.Bottom.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Bottom.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Top" ):hide()
        ui_manager:get_widget( "TestScreen.Top.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Top.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Center" ):hide()
        ui_manager:get_widget( "TestScreen.Center.LeftTop" ):hide()
        ui_manager:get_widget( "TestScreen.Center.RightTop" ):hide()
        ui_manager:get_widget( "TestScreen.Center.LeftBottom" ):hide()
        ui_manager:get_widget( "TestScreen.Center.RightBottom" ):hide()
        return 0
    end,
}
