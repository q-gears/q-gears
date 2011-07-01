Ui = {}



Ui[ "TestScreen" ] = {
    on_start = function()
        return 0
    end,

    on_show = function()
        ui_manager:get_widget( "TestScreen.Dialog0" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.Center" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.Top" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.Bottom" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.Left" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.Right" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.TopLeft" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.TopRight" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.BottomLeft" ):show()
        ui_manager:get_widget( "TestScreen.Dialog0.BottomRight" ):show()

        ui_manager:get_widget( "TestScreen.Dialog1" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.Center" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.Top" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.Bottom" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.Left" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.Right" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.TopLeft" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.TopRight" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.BottomLeft" ):show()
        ui_manager:get_widget( "TestScreen.Dialog1.BottomRight" ):show()

        ui_manager:get_widget( "TestScreen.Dialog2" ):show()

        return 0
    end,

    on_hide = function()
        ui_manager:get_widget( "TestScreen.Dialog0" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.Center" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.Top" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.Bottom" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.TopLeft" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.TopRight" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.BottomLeft" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog0.BottomRight" ):hide()

        ui_manager:get_widget( "TestScreen.Dialog1" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.Center" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.Top" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.Bottom" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.TopLeft" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.TopRight" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.BottomLeft" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog1.BottomRight" ):hide()

        ui_manager:get_widget( "TestScreen.Dialog2" ):hide()

        return 0
    end,
}
