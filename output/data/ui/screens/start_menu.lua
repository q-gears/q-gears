Ui = {}



Ui[ "StartScreen" ] = {
    on_start = function()
        return 0
    end,

    on_show = function()
        ui_manager:get_widget( "StartScreen.Background" ):show()
        ui_manager:get_widget( "StartScreen.StartButton" ):show()
        ui_manager:get_widget( "StartScreen.ContinueButton" ):show()
        ui_manager:get_widget( "StartScreen.Cursor" ):show()
        return 0
    end,

    on_hide = function()
        ui_manager:get_widget( "StartScreen.Background" ):hide()
        ui_manager:get_widget( "StartScreen.StartButton" ):hide()
        ui_manager:get_widget( "StartScreen.ContinueButton" ):hide()
        ui_manager:get_widget( "StartScreen.Cursor" ):hide()
        return 0
    end,

    on_key_press = function( button )
        if button == "X" then
            if Ui[ "StartScreen" ][ "StartButton" ].focus == true then
                script:request_end_sync( "Ui.StartScreen", "to_start", 0 )
            else
                script:request_end_sync( "Ui.StartScreen", "to_continue", 0 )
            end

            -- when we hide parent - all it's childrens stop rendering (but not hiding),
            -- but when we call Show() again they all will be hided from script.
            ui_manager:get_widget( "StartScreen" ):hide()
        elseif button == "Down" then
            if Ui[ "StartScreen" ][ "StartButton" ].focus == true then
                script:request( "Ui.StartScreen.Cursor", "to_continue", 0 )
            end
        elseif button == "Up" then
            if Ui[ "StartScreen" ][ "StartButton" ].focus == false then
                script:request( "Ui.StartScreen.Cursor", "to_start", 0 )
            end
        end

        return 0
    end,

    to_start = function()
        -- load map
        return 0
    end,

    to_continue = function()
        ui_manager:get_widget( "ContinueMenu" ):show()
        return 0
    end,



    Background = {
        on_start = function()
            return 0
        end,

        on_show = function()
            return 0
        end,

        on_hide = function()
            return 0
        end,
    },



    StartButton = {
        focus = false,

        on_start = function()
            return 0
        end,

        on_show = function()
            --ui_manager:get_widget( "StartScreen.StartButton" ):play_animation( "appear" )
            -- after playing this animation - entity changes to default idle animation.
            return 0
        end,

        on_hide = function()
            return 0
        end,
    },



    ContinueButton = {
        on_start = function()
            return 0
        end,

        on_show = function()
            --ui_manager:get_widget( "StartScreen.ContinueButton" ):play_animation( "appear" )
            -- after playing this animation - entity changes to default idle animation.
            return 0
        end,

        on_hide = function()
            return 0
        end,
    },



    Cursor = {
        on_start = function()
            return 0
        end,

        on_show = function()
            local cursor = ui_manager:get_widget( "StartScreen.Cursor" )
            --cursor:play_animation( "appear" )
            --cursor:animation_sync()
            --cursor:set_default_animation( "position1" )
            Ui[ "StartScreen" ][ "StartButton" ].focus = true;
            return 0
        end,

        on_hide = function()
            return 0
        end,

        to_start = function()
            --cursor:set_default_animation( "position1" )
            Ui[ "StartScreen" ][ "StartButton" ].focus = true;
            return 0
        end,

        to_continue = function()
            --cursor:set_default_animation( "position2" )
            Ui[ "StartScreen" ][ "StartButton" ].focus = false;
            return 0
        end
    },
}
