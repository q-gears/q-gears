Ui = {}



Ui[ "TestScreen" ] = {
    on_start = function()
        return 0
    end,

    on_show = function()
        ui_manager:get_widget( "TestScreen.Dialog" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.Center" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.Top" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.Bottom" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.Left" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.Right" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.TopLeft" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.TopRight" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.BottomLeft" ):show()
        ui_manager:get_widget( "TestScreen.Dialog.BottomRight" ):show()

        return 0
    end,

    on_hide = function()
        ui_manager:get_widget( "TestScreen.Dialog" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.Center" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.Top" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.Bottom" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.Left" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.Right" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.TopLeft" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.TopRight" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.BottomLeft" ):hide()
        ui_manager:get_widget( "TestScreen.Dialog.BottomRight" ):hide()

        return 0
    end,
}
