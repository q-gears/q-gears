ui.MainMenu = {}

ui.MainMenu.elements = {
    background = ui_manager:AddEffect( "background_effect" ),
    menu1 = ui_manager:AddButton( "menu_effect", "medium_font", "start_text" ),
    menu2 = ui_manager:AddButton( "menu_effect", "medium_font", "exit_text" ),
}

function ui.MainMenu:Show()
    self.elements.background:PlayAnimation( "show" )
    self.elements.menu1:PlayAnimation( "show" )
    self.elements.menu2:PlayAnimation( "show" )
    self.elements.background:AnimationSync()
    return 0
end

function ui.MainMenu:Hide()
    self.elements.background:PlayAnimation( "hide" )
    self.elements.menu1:PlayAnimation( "hide" )
    self.elements.menu2:PlayAnimation( "hide" )
    self.elements.background:AnimationSync()
    return 0
end

function ui.MainMenu:OnCancel()
    ui.MainMenu.Hide()
    ui.PressStart:Show()
    return 0
end

function ui.MainMenu:OnConfirm()
    return 0
end
