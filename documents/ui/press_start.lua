ui.PressStart = {}

ui.PressStart.elements = {
    background = ui_manager:AddEffect( "background_effect" ),
    press_start = ui_manager:AddLabel( "press_start_effect", "large_font", "press_start_text" ),
}

function ui.PressStart:Show()
    self.elements.background:PlayAnimation( "show" )
    self.elements.press_start:PlayAnimation( "show" )
    self.elements.background:AnimationSync()
    return 0
end

function ui.PressStart:Hide()
    self.elements.background:PlayAnimation( "hide" )
    self.elements.press_start:PlayAnimation( "hide" )
    self.elements.background:AnimationSync()
    return 0
end

function ui.PressStart:OnCancel()
    return 0
end

function ui.PressStart:OnConfirm()
    ui.PressStart.Hide()
    ui.MainMenu:Show()
    return 0
end