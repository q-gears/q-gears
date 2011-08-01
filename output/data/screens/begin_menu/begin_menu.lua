Ui.BeginMenu = {
    on_start = function()
        local cursor = ui_manager:get_widget( "BeginMenu.Cursor" )
        cursor:set_default_animation( "Position1" )
        Ui.BeginMenu.position = 1
        return 0
    end,



    on_update = function()
        if button == "X" then
            if Ui.BeginMenu.Cursor.position == 1 then
                script:request_end_sync( "Ui.BeginMenu", "to_start", 0 )
            else
                script:request_end_sync( "Ui.BeginMenu", "to_continue", 0 )
            end
        elseif button == "Down" and Ui.BeginMenu.position == 1 then
            local cursor = ui_manager:get_widget( "BeginMenu.Cursor" )
            cursor:set_default_animation( "Position2" )
            Ui.BeginMenu.position = 2
        elseif button == "Up" and Ui.BeginMenu.position == 2 then
            local cursor = ui_manager:get_widget( "BeginMenu.Cursor" )
            cursor:set_default_animation( "Position1" )
            Ui.BeginMenu.position = 1
        end

        return 0
    end,



    to_start = function()
        -- load map
        -- ui_manager:get_widget( "BeginMenu" ):hide()
        return 0
    end,



    to_continue = function()
        -- call continue menu
        -- ui_manager:get_widget( "BeginMenu" ):hide()
        return 0
    end,
}
