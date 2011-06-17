main_menu_screen = {
    Init = function()
        main_menu_buttons:Hide()
        options_buttons:Hide()
    end

    StopScreen = function()
    end

    MainMenuLoading = function()
        SetLock( true )
                    <do object = "menu_background" command = "BehaviorStart" param = "ToLeft 1" instant = "1"/>
        global.screens.loading_screen:StartScreen()
                    <do object = "menu_background" command = "BehaviorStart" param = "LeftToCenter" instant = "1"/>
        global.screens.loading_screen:StopScreen()
        SetLock( false )
    end

    MainMenuScreen = function()
        SetLock( true )
        main_menu_buttons:Show()
                    <do object = "main_menu_buttons" command = "StartScreen" instant = "1"/>
                </start>

                <stop>
                    <do object = "main_menu_buttons" command = "StopScreen" />
        main_menu_buttons:Hide()
        SetLock( false )
                </stop>
    end

    MainMenuOptions = function()
        SetLock( true )
                    <do object = "menu_background" command = "BehaviorStart" param = "CenterToRight" instant = "1"/>
                    <do object = "options_buttons" command = "Show" />
                    <do object = "options_buttons" command = "StartScreen" />
                </start>

                <stop>
                    <do object = "menu_background" command = "BehaviorStart" param = "RightToCenter" instant = "1"/>
                    <do object = "options_buttons" command = "StopScreen" />
                    <do object = "options_buttons" command = "Hide" />
        SetLock( false )
                </stop>
    end
}
