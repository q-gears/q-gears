-- ----------------------------------------------------------------------------
--
-- Workfile: MenuWnd.lua
-- Created by: SoftKitty @
-- Copyright й 2006, Targem LLC. All rights reserved.
--
-- ----------------------------------------------------------------------------
--  $Id: menuwnd.lua 2685 2011-04-27 07:33:41Z elena_evdokimova $
-- ----------------------------------------------------------------------------

local resolution = UI:GetCoordinateSystemForAspect( cvars.r_height / cvars.r_width )

UI.MenuWnd = {}
local mw = UI.MenuWnd

-- ------------------------------
-- items
-- ------------------------------

-- "static" variable
mw.items =
{
	main			= { "Campaign", "Skirmish", "Multiplayer", "Challenges", "Options", "Exit" },
	Multiplayer		= { "Lan" },
	Options			= { "Video", "Audio", "Tutorial" },
	Tutorial		= {},	-- инициализируется после создания меню
	Pause			= { "Continue", "Restart", "Options", "ToMainMenu" },
}

-- ------------------------------
-- window definition
-- ------------------------------

local l_numLaptopLayers = UI:GetTableLength( UI.LaptopWnd_mini.layers )

UI.MenuWnd.def =
{
	className	= "Wnd",
	prototype	= "LaptopWnd_mini",

	props =
	{
		name 			= "MenuWnd",
		isPrototype		= true,
	},

	layers =
	{
		numLayers = l_numLaptopLayers + 1,

		-- CAPTION
		{
			id = l_numLaptopLayers,

			layerType	= UI.LAYER_TEXT,
			blendMode	= UI.BM_COLOR,

   			formatFlags	 = FONT.TF_SINGLELINE + FONT.TF_NOCLIP,
   			formatInfoSz = { 1, 1 },
   			font =
			{
   				scaledForResolution = true,
   				patternName = UI:GetFontPattern( "Large_outl" ),
   			},
		},  
	},
}


-- ------------------------------
-- interface functions
-- ------------------------------

--
function UI.MenuWnd:SetLevel( level, stack --[[optional]] )

	if type( level ) ~= "string" then
		sys.log( "UI.MenuWnd:SetLevel()[ERROR]: invalid type of the 1-st parameter (level); \"string\" expected got \"%s\"", type( level ) )
		return
	end

	if not UI.MenuWnd.items then
		sys.log( "UI.MenuWnd:SetLevel()[ERROR]: invalid 1-st parameter (level); cannot find item with name \"%s\"", level )
		return
	end

	if stack ~= nil then
		if type( stack ) ~= "table" then
			sys.log( "UI.MenuWnd:SetLevel()[ERROR]: invalid type of the 2-nd parameter (stack); \"nil\" or \"table\" expected, got \"%s\"", type( stack ) )
			return
		end

		for stackIdx, stackLevel in pairs( stack ) do
			if not UI.MenuWnd.items[ stackLevel ] then
				sys.log( "UI.MenuWnd:SetLevel()[ERROR]: invalid stack; level \"%s\" not found", tostring( stackLevel ) )
				return
			end
		end
	end

	if stack then
		self.stack = UI:CopyTable2( stack )
	end

	self:SetLevelInternal( level, false )

end


--
function UI.MenuWnd:SelectItem( itemName )

	if type( itemName ) ~= "string" then
		sys.log( "UI.MenuWnd:SelectItem()[ERROR]: invalid type of the 1-st parameter (item); \"string\" expected, got \"%s\"", type( itemName ) )
		return
	end

	local recordIdx = self:GetRecordByItemName( itemName )
	if recordIdx == -1 then
		sys.log( "UI.MenuWnd:SelectItem()[ERROR]: cannot find item \"%s\" for level \"%s\"", itemName, self.level )
		return
	end

	self.listWnd:SelectRecord( recordIdx, false )

end


--
function UI.MenuWnd:GetLevel()

	return self.level

end


--
function UI.MenuWnd:GetSelectedItem()

	local selRecordIdx = self.listWnd:GetSelectedRecord()

	if selRecordIdx ~= -1 then

		local data = self.listWnd:GetRecordData( selRecordIdx )
		return data.item.name

	else
		return ""
	end

end


--
function UI.MenuWnd:SetShowModeFromStartWnd()

	self.bShowModeFromStartWnd = true

end

-- ------------------------------
-- const
-- ------------------------------

mw.layers =
{
	MAIN_EFFECT				= 0, 
    BG_EFFECT           	= 1, 
	LOGO_EFFECT         	= 2,
	LAPTOP_FRAME_EFFECT		= 3,
	LAMPS_EFFECT			= 4,
	BATTERY_EFFECT          = 5,
	TUMBLER_EFFECT_1	    = 6,
	KNOB_EFFECT_1		    = 7,
	KNOB_EFFECT_2			= 8,
	LAPTOP_CONTENT_EFFECT	= 9,
	CAPTION				    = 10,
}

mw.waitModes =
{
	NONE			= 1,
	SEARCHING		= 2,
	CONNECTING		= 3,
	CREATING_SERVER	= 4,
}


mw.startShowAnimations_withLogo	= { "showLaptopFrame_withLogo" }
mw.startShowAnimations_woLogo	= { "showLaptopFrame_woLogo" }
mw.startShowAnimations			= mw.startShowAnimations_withLogo


mw.finalHideAnimations_withLogo	= { "hideLaptopFrame_withLogo" }
mw.finalHideAnimations_woLogo	= { "hideLaptopFrame_woLogo" }
mw.finalHideAnimations			= mw.finalHideAnimations_withLogo

-- ------------------------------
-- animations
-- ------------------------------

mw.animations = {}

mw.animations.showLaptopFrame_withLogo = UI:CopyTable2( UI.FullScreenWnd.animationShowLayersBase )
mw.animations.showLaptopFrame_withLogo.animInfo = { { layer = mw.layers.MAIN_EFFECT, anim = "show", animIdle = "idle" }, { layer = mw.layers.LOGO_EFFECT, anim = "show_complet", animIdle = "idle_in_menu" } }

mw.animations.showLaptopFrame_woLogo = UI:CopyTable2( UI.FullScreenWnd.animationShowLayersBase )
mw.animations.showLaptopFrame_woLogo.animInfo = { { layer = mw.layers.MAIN_EFFECT, anim = "show", animIdle = "idle" } }

mw.animations.hideLaptopFrame_withLogo = UI:CopyTable2( UI.FullScreenWnd.animationHideLayersBase )
mw.animations.hideLaptopFrame_withLogo.animInfo = { { layer = mw.layers.MAIN_EFFECT, anim = "hide" }, { layer = mw.layers.LOGO_EFFECT, anim = "hide_complet" } }

mw.animations.hideLaptopFrame_woLogo = UI:CopyTable2( UI.FullScreenWnd.animationHideLayersBase )
mw.animations.hideLaptopFrame_woLogo.animInfo = { { layer = mw.layers.MAIN_EFFECT, anim = "hide" } }

-- ------------------------------
-- vars
-- ------------------------------

mw.level					= ""
mw.stack					= {}
mw.hMsgBoxToMainMenu		= UI.INVALID_UI_HANDLE
mw.hMsgBoxToWindows			= UI.INVALID_UI_HANDLE
mw.hMsgPsnSign				= UI.INVALID_UI_HANDLE
mw.hMsgRestart				= UI.INVALID_UI_HANDLE
mw.itemToSelect				= ""
mw.waitingWnd				= nil
mw.waitMode					= mw.waitModes.NONE
mw.bPsnChecked				= false
mw.bShowModeFromStartWnd	= false

-- ------------------------------
-- work functions
-- ------------------------------

--
function UI.MenuWnd:F_PostLoad()    

	UI.LaptopWnd_mini.F_PostLoad( self )

	self.stack = {}

	if self == UI.MenuWnd then
		self:PrepareItems()
		self:InitTutorialItems()

	else

		self.waitingWnd = self:GetChildByName( "waitingWnd" )

    	self:FullUpdate()

    	local handle = self:GetUiHandle()
    	UI:SubscribeUiObjOnEvent( handle, UI.EV_MSGBOX_RET )
		UI:SubscribeUiObjOnEvent( handle, UI.EV_SERVER_REPLY )
		UI:SubscribeUiObjOnEvent( handle, UI.EV_PLAYER_DISCONNECTED )
		UI:SubscribeUiObjOnEvent( handle, UI.EV_LIVE_SERVICES_RESULT )
		UI:SubscribeUiObjOnEvent( handle, UI.EV_NETWORK_DISCONNECT )

	end

end


--
function UI.MenuWnd:PrepareItems()

	for levelName, levelItems in pairs( UI.MenuWnd.items ) do

		for itemIdx, item in pairs( levelItems ) do

			if type( item ) ~= "table" then
				local tItem = { name = item }
				levelItems[ itemIdx ] = tItem				
				item = tItem
			end

			if item.bHidden == nil then
				item.bHidden = false
			end

			if item.bDisabled == nil then
				item.bDisabled = false
			end
		end
	end

end


--
local l_OnLesson = function( self, itemName )

	local lessonName = string.match( itemName, "^Tutorial_(%w+)$" )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnLesson2", params = { lessonName = lessonName } }
	self:Hide( true, true )		

end


--
function UI.MenuWnd:InitTutorialItems()

	if not _G.howtoplay then
		return
	end

	for lessonIdx = 1, #_G.howtoplay do

		local lessonInfo = _G.howtoplay[ lessonIdx ]
		if lessonInfo then
		                                                      		
			local itemName = string.format( "Tutorial_%s", lessonInfo.name )
			table.insert( self.items.Tutorial, { name = itemName, bHidden = false, bDisabled = false } )

			local fnName = string.format( "On%s", itemName )
			self[ fnName ] = l_OnLesson

		end

	end	

end


--
function UI.MenuWnd:Reset()

	if not UI:IsInRemovingAllWindows() then
		UI.LaptopWnd_mini.Reset( self )
	end

	self:SetText( "", self.layers.CAPTION )

	self.waitMode = self.waitModes.NONE
	self:HideWaitEffect()

end


--
function UI.MenuWnd:FullUpdate()

	UI.LaptopWnd_mini.FullUpdate( self )
	self:UpdateCaption()

end


--
function UI.MenuWnd:UpdateList()

	local levelItems = UI.MenuWnd.items[ self.level ]
	if not levelItems then
		return
	end

	self:UpdateItemsStatus()

	for itemIdx = 1, #levelItems do
		local item = levelItems[ itemIdx ]

		if not item.bHidden then

			local data = {}
			data.item		= item
			data.text		= UI:AStr( self:ItemName2Localized( item.name ) )
			data.bDisabled	= item.bDisabled

			self.listWnd:AddRecord( data )

		end
	end

end


--
function UI.MenuWnd:ValidateListSelection()

	if self.itemToSelect ~= "" then
		local recordIdx = self:GetRecordByItemName( self.itemToSelect )
		self.itemToSelect = ""

		if recordIdx ~= -1 then
			self.listWnd:SelectRecord( recordIdx, false )
			return
		end
	end

	if self.listWnd:GetNumRecords() > 0 then
		self.listWnd:SelectRecord( 1, false )
	end

end


--
function UI.MenuWnd:UpdateKeyTipPanel()

	if not self.keyTipPanel then
		return
	end

	-- escape

	local bNeedEscape = true

	if self.waitMode == self.waitModes.CONNECTING or self.waitMode == self.waitModes.CREATING_SERVER then
		bNeedEscape = false
	end

	self.keyTipPanel:EnableBtn( UI.Keys.KEY_ESCAPE, bNeedEscape )


	-- enter

	local bNeedEnter = true

	if self.listWnd:GetSelectedRecord() == -1 then
		bNeedEnter = false
	end

	if self.waitMode ~= self.waitModes.NONE then
		bNeedEnter = false
	end

	self.keyTipPanel:EnableBtn( UI.Keys.KEY_ENTER, bNeedEnter )

end


--
function UI.MenuWnd:UpdateCaption()

	local caption = ""

	if self.level ~= "" and self.level ~= "main" and self.level ~= "Pause" then
		caption = self:ItemName2Localized( self.level )
	end

	self:SetText( caption, self.layers.CAPTION )

end


--
function UI.MenuWnd:OnEscape()

	if self.keyTipPanel and not self.keyTipPanel:IsBtnEnabled( UI.Keys.KEY_ESCAPE ) then
		return false
	end

	if UI.LaptopWnd_mini.IsInputBlocked( self ) then	-- не учитывается waitMode
		return true	
	end

	if self.waitMode == self.waitModes.SEARCHING then
		self:StopWaiting()
		return true
	end

	if self.level == "main" then
		self:ReturnToStartWnd()

	elseif self.level == "Pause" then
		self:HandleCommand( "Continue" )

	else
		self:ReturnToPrevLevel( true )
		UI:PlayGlobalSound( UI.sounds.showScreen )
	end

	return true

end


--
function UI.MenuWnd:ActivateSelRecord()

	local selRecordIdx = self.listWnd:GetSelectedRecord()
	local data = self.listWnd:GetRecordData( selRecordIdx )

	if data.item.bDisabled then
		UI:PlayGlobalSound( UI.sounds.locked )
		return
	end

	if self:IsItemLeaf( data.item.name ) then

		self:HandleCommand( data.item.name, true )

	else

		if not self:HandleCommand( data.item.name, false ) then

    		table.insert( self.stack, self.level )

    		UI:PlayGlobalSound( UI.sounds.showScreen )
			self:SetLevelCrossover( data.item.name, nil, true )

		end

	end

end


--
function UI.MenuWnd:GetRecordByItemName( itemName )

	for recordIdx = 1, self.listWnd:GetNumRecords() do
		local data = self.listWnd:GetRecordData( recordIdx )
		if data.item.name == itemName then
			return recordIdx
		end
	end

	return -1	

end


--
function UI.MenuWnd:IsItemLeaf( itemName )

	return UI.MenuWnd.items[ itemName ] == nil

end


--
function UI.MenuWnd:ItemName2Localized( itemName )	

	local strId = string.format( "menu_%s", itemName )
	return UI:GetStringForPlatform( strId )

end


--
function UI.MenuWnd:UpdateItemsStatus()

	local items = UI.MenuWnd.items[ self.level ]
	if not items then
		return
	end

	for itemIdx, item in pairs( items ) do
		local fnName = string.format( "UpdateItemStatus_%s", item.name )
		local fn = self[ fnName ]
		if fn then
			fn( self, item )
		end
	end

end


--
function UI.MenuWnd:SetLevelInternal( level, bAnimated )

	if bAnimated == nil or not self:IsOnScreen() or self.level == level then
		bAnimated = false
	end

	self.level = level

	if not bAnimated then
		self:FullUpdate()

	else

		self.commandOnHide = { fn = "SetLevelInternal2" }
		self:StartHideAnimation( false )		

	end

end


--
function UI.MenuWnd:SetLevelInternal2()

	self:FullUpdate()
	self:StartShowAnimation( false )

end


-- возможен переход между разными окнами меню в зависимости от уровня меню и стека
function UI.MenuWnd:SetLevelCrossover( level, selItem, bAnimated )

	local menuWnd = UI:GetMenuWndForStack( level, self.stack )

	if menuWnd == self then
		self.itemToSelect = selItem
		self:SetLevelInternal( level, bAnimated )
		return		
	end

	if not bAnimated then
		self:Hide( false, false )

		menuWnd:SetLevel( level, self.stack )
		UI.Root:AddChild( menuWnd )

		if selItem and selItem ~= "" then
			menuWnd:SelectItem( selItem )
		end

		return
	end

	self.commandOnHide = { fn = "SetLevelCrossover2", params = { level = level, stack = self.stack, selItem = selItem } }
	self:Hide( true, true )

end


--
function UI.MenuWnd:SetLevelCrossover2( params )

	local menuWnd = UI:GetMenuWndForStack( params.level, params.stack )

	menuWnd:SetLevel( params.level, params.stack )
	menuWnd:Show( true )

	if params.selItem and params.selItem ~= "" then
		menuWnd:SelectItem( params.selItem )
	end

end


--
function UI.MenuWnd:HandleCommand( itemName, bLeaf )

	if bAnimated == nil or not self:IsOnScreen() then
		bAnimated = false
	end

	if bLeaf == nil then
		bLeaf = true
	end

	local fnName = string.format( "On%s", itemName )
	local fn = self[ fnName ]

	if fn then
		return fn( self, itemName )
	else
		if bLeaf then
			sys.log( "UI.MenuWnd:HandleCommand()[ERROR]: cannot find handle for command \"%s\"", itemName )
		end
		return false
	end

end


--
function UI.MenuWnd:ReturnToPrevLevel( bAnimated )

	if not next( self.stack ) then
		return
	end

	local stackSize = #self.stack

	local prevLevel = self.stack[ stackSize ]
	self.stack[ stackSize ] = nil

	self.itemToSelect = self.level
	self:SetLevelCrossover( prevLevel, self.level, true )

end


--
function UI.MenuWnd:F_OnAfterHideFromScreen()

	self.hMsgBoxToMainMenu  	= UI.INVALID_UI_HANDLE
	self.hMsgBoxToWindows		= UI.INVALID_UI_HANDLE
	self.hMsgPsnSign			= UI.INVALID_UI_HANDLE
	self.hMsgRestart			= UI.INVALID_UI_HANDLE

	if not UI:IsInRemovingAllWindows() then
		UI.LaptopWnd_mini.F_OnAfterHideFromScreen( self )
	else
		self:OnAfterHideFromScreen()
	end

end


--
function UI.MenuWnd:F_OnEventMsgBoxRet( hSender, retCode, boxHandle )

	if not self:IsOnScreen() then
		return
	end

	if boxHandle == self.hMsgBoxToMainMenu then
		self.hMsgBoxToMainMenu = UI.INVALID_UI_HANDLE

		if retCode == UI.MBRET_YES then
			self:OnToMainMenu2()
			return
		end

	elseif boxHandle == self.hMsgBoxToWindows then
		self.hMsgBoxToWindows = UI.INVALID_UI_HANDLE

		if retCode == UI.MBRET_YES then
    		sys.concmd( "quit" )
			return
		end

	elseif boxHandle == self.hMsgPsnSign then
		self.hMsgPsnSign = UI.INVALID_UI_HANDLE

		if retCode == UI.MBRET_YES then
			_G.PsnOpenSignInDialog()
			return
		end

	elseif boxHandle == self.hMsgRestart then
		self.hMsgRestart = UI.INVALID_UI_HANDLE

		if retCode == UI.MBRET_YES then
			UI:RestartMap()
			return
		end
	end

	UI:PlayGlobalSound( UI.sounds.showScreen )

end       


--
function UI.MenuWnd:HasLevelOnStack( level )

	if self.level == level then
		return true
	end

	for idx, stackLevel in pairs( self.stack ) do
		if stackLevel == level then
			return true
		end
	end
	
	return false

end


--
function UI.MenuWnd:SetItemHidden( item, bHidden )

	if item then
		item.bHidden = bHidden
	end

end


--
function UI.MenuWnd:SetItemDisabled( item, bDisabled )

	if item then
		item.bDisabled = bDisabled
	end

end


--
function UI.MenuWnd:F_OnEventSaveUiState()

	if self.bToHide then
		self:OnStopHideAnimation()
	end

	UI.store[ self:GetScriptTableName() ] =
	{
		level			= self.level,
		stack			= self.stack,
		selItem			= self:GetSelectedItem(),
		bPsnChecked 	= self.bPsnChecked
	}

end


--
function UI.MenuWnd:F_OnEventRestoreUiState()

	local name = self:GetScriptTableName()	
	local t = UI.store[ name ]
	if t then

		self.bPsnChecked = t.bPsnChecked

		if t.level ~= "" then
			self:SetLevel( t.level, t.stack )

			if t.selItem ~= "" then
				self:SelectItem( t.selItem )
			end
		end

		UI.store[ name ] = nil
	end 

end


--
function UI.MenuWnd:SetWaitMode( waitMode )

	if UI:Val2Key( self.waitModes, waitMode ) == "" then
		sys.log( "UI.MenuWnd:SetWaitMode()[ERROR]: invalid waitMode: \"%s\"", tostring( waitMode ) )
		return
	end

	self.waitMode = waitMode

	if self.waitMode == self.waitModes.NONE then
		self:HideWaitEffect()

	else
		self:ShowWaitEffect( self:GetWaitMsg( self.waitMode ) )
	end

	self:UpdateKeyTipPanel()

end


--
function UI.MenuWnd:StopWaiting()

	self:SetWaitMode( self.waitModes.NONE )

end


--
function UI.MenuWnd:ShowWaitEffect( msg )

	self:AddChild( self.waitingWnd )

	if self.keyTipPanel then
		self:MoveChildToLastPosition( self.keyTipPanel )
	end

	self.waitingWnd:SetWaitText( msg )

end


--
function UI.MenuWnd:HideWaitEffect()

	if self.waitingWnd then
		self.waitingWnd:UnlinkFromParent()
	end

end


--
function UI.MenuWnd:GetWaitMsg( waitMode )

	local str = ""

	if waitMode == self.waitModes.SEARCHING then

		if self:HasLevelOnStack( "LAN" ) then
			str = UI:GetStringForPlatform( "serverSearching_lan" )

		elseif self:HasLevelOnStack( "Live" ) then
			str = UI:GetStringForPlatform( "serverSearching_live" )

		elseif self:HasLevelOnStack( "PSN" ) then
			str = UI:GetStringForPlatform( "serverSearching_psn" )
		end


	elseif waitMode == self.waitModes.CONNECTING then

    	if self:HasLevelOnStack( "LAN" ) then
    		str = UI:GetStringForPlatform( "connecting_lan" )

    	elseif self:HasLevelOnStack( "Live" ) then
    		str = UI:GetStringForPlatform( "connecting_live" )

    	elseif self:HasLevelOnStack( "PSN" ) then
    		str = UI:GetStringForPlatform( "connecting_psn" )
		end


	elseif waitMode == self.waitModes.CREATING_SERVER then

    	if self:HasLevelOnStack( "Live" ) then
    		str = UI:GetStringForPlatform( "serverCreating_live" )

    	elseif self:HasLevelOnStack( "PSN" ) then
    		str = UI:GetStringForPlatform( "serverCreating_psn" )
		end

	end

	return str

end


-- TODO: адаптировать для данного проекта 
-- конец поиска для LAN
function UI.MenuWnd:F_OnEventServerReply()
end 


--
function UI.MenuWnd:F_OnEventPlayerDisconnected( hSender, iParam0, iParam1, fParam0, fParam1 )

	if not self:IsOnScreen() then
		return
	end

	if self.waitMode == self.waitModes.CONNECTING then

    	self:StopWaiting()

    	local reason = iParam1
    	UI:ShowMsgOnMpConnectionLost( reason )

	end

end 


--
function UI.MenuWnd:F_OnEventLiveServicesResult( hSender, iParam0, iParam1, fParam0, fParam1 )

	if not self:IsOnScreen() then
		return
	end

	local result = iParam0

	if self.waitMode == self.waitModes.CONNECTING then

		self:StopWaiting()

		local msgId = ""

		if result == network.SessionErr.NO_SESSION_FOUND then

			if self:HasLevelOnStack( "PSN" ) then
				msgId = "msg_noServersFound_psn"
			elseif self:HasLevelOnStack( "Live" ) then
				msgId = "msg_noServersFound_live"
			end

		else

			if self:HasLevelOnStack( "PSN" ) then
				msgId = "msg_failServerSearch_psn"
			elseif self:HasLevelOnStack( "Live" ) then
				msgId = "msg_failServerSearch_live"
			end

		end

		UI:MessageBox( "", UI:GetStringForPlatform( msgId ), UI.MBS_OK )		

	elseif self.waitMode == self.waitModes.CREATING_SERVER then

		self:StopWaiting()

		if result ~= network.SessionErr.SUCCESS then

    		local msgId = ""

    		if self:HasLevelOnStack( "PSN" ) then
    			msgId = "msg_failCreateServer_psn"
    		elseif self:HasLevelOnStack( "Live" ) then
    			msgId = "msg_failCreateServer_live"
    		end

    		UI:MessageBox( "", UI:GetStringForPlatform( msgId ), UI.MBS_OK )		

		end

	end

end


--
function UI.MenuWnd:F_OnEventNetworkDisconnect( hSender, iParam0, iParam1, fParam0, fParam1 )

	if not self:IsOnScreen() then
		return
	end

	if not self:HasLevelOnStack( "PSN" ) and not self:HasLevelOnStack( "Live" ) then
		return
	end

	self:StopWaiting()

	local msgId = self:HasLevelOnStack( "PSN" ) and "msg_lostPsn" or "msg_lostLive"

	-- TODO: адапиировать для данного проекта
--	UI:ShowMenuInternal( self:HasLevelOnStack( "BattleDance" ) and "BattleDance" or "FreeDance", { "main" }, self:HasLevelOnStack( "PSN" ) and "PSN" or "Live", false )

	UI:MessageBox( "", UI:GetStringForPlatform( msgId ), UI.MBS_OK )	

end


--
function UI.MenuWnd:IsInputBlocked()

	if UI.LaptopWnd_mini.IsInputBlocked( self ) then
		return true
	end

	return self.waitMode ~= self.waitModes.NONE

end


--
function UI.MenuWnd:F_OnAfterShowOnScreen()

	UI.LaptopWnd_mini.F_OnAfterShowOnScreen( self )

	-- нельзя проинициализировать в PostLoad, т.к. дизайнерский файл howtoplay.lua еще не загружен
	if not next( self.items.Tutorial ) then
		self:InitTutorialItems()
	end

	if not self:HasLevelOnStack( "Pause" ) then
		UI:ResetPreferences()
	end

	if _G.IsPS3() and not self.bPsnChecked then
		self.bPsnChecked = true

		if not _G.IsPsnSignedIn() then
			self.hMsgPsnSign = UI:MessageBox( "", UI:GetStringByName( "msg_notSignedFirst_psn" ), UI.MBS_YES_NO )		
		end
	end

end


--
function UI.MenuWnd:ReturnToStartWnd()

	self.finalHideAnimations = self.finalHideAnimations_woLogo
	
	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "ReturnToStartWnd2" }
	self:Hide( true, true )

	self.finalHideAnimations = self.finalHideAnimations_withLogo

end


--
function UI.MenuWnd:ReturnToStartWnd2()

	UI.StartWnd:Setup( UI.StartWnd.modes.AFTER_MENU )
	UI.StartWnd:Show( true )	

end


--
function UI.MenuWnd:StartShowAnimation( bPlayStartAnim )

	if self.bShowModeFromStartWnd then
		self.startShowAnimations = self.startShowAnimations_woLogo
	end

	UI.LaptopWnd.StartShowAnimation( self, bPlayStartAnim )

	self.bShowModeFromStartWnd = false
	self.startShowAnimations = self.startShowAnimations_withLogo

end


-- --------------------------------
-- command handlers
-- --------------------------------

--
function UI.MenuWnd:OnContinue( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnContinue2", params = { itemName = itemName } }
	self:Hide( true, true )

end


--
function UI.MenuWnd:OnContinue2( params )

	local levelName = UI:GetCurLevelName()
	if levelName ~= "" and levelName ~= "mainmenu" and levelName ~= "mp_lobby" then

		UI:PlayGlobalSound( UI.sounds.showScreen )

		if UI.HudWnd then
			UI.HudWnd:Show()
		end

	end

end


--
function UI.MenuWnd:OnToMainMenu( itemName )

	local msgId = ""

	if network.isMultiplayer and network.isServer then
		msgId = "msg_requestServerExitGame"

	elseif network.isMultiplayer and network.isClient then
		msgId = "msg_requestClientExitGame"

	else
		msgId = "msg_requestToMainMenu"
	end

	self.hMsgBoxToMainMenu = UI:MessageBox( "", UI:GetStringByName( msgId ), UI.MBS_YES_NO )

end


--
function UI.MenuWnd:OnToMainMenu2()

	if UI.launchParams.mode == UI.launchModes.LOCAL then

    	UI.suspendedMenuState = {}
    	local state = UI.suspendedMenuState
    	UI:ResetMenuStateStruct( state )

    	state.bMenu		= true
    	state.level		= "main"
    	state.stack		= {}
    	state.selItem	= "Skirmish"	

		UI:LoadMainMenuLevel( true )

	else
		UI:LoadMainMenuLevel()
	end

end


--
function UI.MenuWnd:OnRestart( itemName )

	self.hMsgRestart = UI:MessageBox( "", UI:GetStringByName( "msg_requestRestart" ), UI.MBS_YES_NO )

end 


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnLAN( itemName )

	if not self:CheckGameplayFirstTime( self:HasLevelOnStack( "BattleDance" ) ) then
		return true
	else
		return false
	end

end


--
function UI.MenuWnd:OnLanCustomJoin( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnLanCustomJoin2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnLanCustomJoin2()	

	UI.MpOptionsWnd:Setup( self:HasLevelOnStack( "BattleDance" ) and UI.MpOptionsWnd.modes.BD_SEARCH_SERVER_LAN or UI.MpOptionsWnd.modes.FD_SEARCH_SERVER_LAN )
	UI.MpOptionsWnd:Show( true )	

end


--
function UI.MenuWnd:OnPSN( itemName )

	if not self:CheckGameplayFirstTime( self:HasLevelOnStack( "BattleDance" ) ) then
		return true
	end

	if not _G.IsPsnSignedIn() then
		self.hMsgPsnSign = UI:MessageBox( "", UI:GetStringByName( "msg_notSigned_psn" ), UI.MBS_YES_NO )
		return true
	end

	if _G.PsnIsContentRatingRestricted() then
		UI:MessageBox( "", UI:GetStringByName( "msg_contentRatingRestricted_psn" ), UI.MBS_OK )
		return true
	end

	if _G.PsnIsChatRestricted() then
		UI:MessageBox( "", UI:GetStringByName( "msg_chatRestricted_psn" ), UI.MBS_OK )
		return false
	end

	return false

end


--
function UI.MenuWnd:OnPsnCustomJoin( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnPsnCustomJoin2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnPsnCustomJoin2()		

	UI.MpOptionsWnd:Setup( self:HasLevelOnStack( "BattleDance" ) and UI.MpOptionsWnd.modes.BD_SEARCH_SERVER_PSN or UI.MpOptionsWnd.modes.FD_SEARCH_SERVER_PSN )
	UI.MpOptionsWnd:Show( true )	

end  


--
function UI.MenuWnd:OnLanQuickJoin( itemName )

	_G.network.LANGames = {}

	if not _G.MpFindLanGames() then
		UI:MessageBox( "", UI:GetStringForPlatform( "msg_failServerSearch_lan" ), UI.MBS_OK )
		return
	end

	self:SetWaitMode( self.waitModes.SEARCHING )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnPsnQuickJoin( itemName )

	self:SetWaitMode( self.waitModes.CONNECTING )

	UI:ResetLaunchParams( UI.launchParams )

	UI.launchParams.mode			= UI.launchModes.MP_PSN_CLIENT
	UI.launchParams.gameplay		= self:HasLevelOnStack( "BattleDance" ) and ai.Gameplay.BATTLE_DANCE or ai.Gameplay.FREE_DANCE
	UI.launchParams.ranked			= true
	UI.launchParams.quick			= true		
	UI.launchParams.songSpeed		= -1

	if not UI:LaunchMap( UI.launchParams ) then
		self:StopWaiting()
		UI:MessageBox( "", UI:GetStringForPlatform( "msg_failServerSearch_psn" ), UI.MBS_OK )		
	end

end


--
function UI.MenuWnd:OnLanCreateServer( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnLanCreateServer2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnLanCreateServer2()

	UI.MpOptionsWnd:Setup( self:HasLevelOnStack( "BattleDance" ) and UI.MpOptionsWnd.modes.BD_CREATE_SERVER_LAN or UI.MpOptionsWnd.modes.FD_CREATE_SERVER_LAN )
	UI.MpOptionsWnd:Show( true )	

end


--
function UI.MenuWnd:OnPsnCreateServer( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnPsnCreateServer2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnPsnCreateServer2()

	UI.MpOptionsWnd:Setup( self:HasLevelOnStack( "BattleDance" ) and UI.MpOptionsWnd.modes.BD_CREATE_SERVER_PSN or UI.MpOptionsWnd.modes.FD_CREATE_SERVER_PSN )
	UI.MpOptionsWnd:Show( true )	

end    


--
function UI.MenuWnd:OnLeaderboards( itemName )

	if _LB_EMULATE ~= true then

     	if _G.IsX360() then

     		if not _G.IsLiveSignedIn() then
     			UI:MessageBox( "", UI:GetStringByName( "msg_notSigned_live" ), UI.MBS_OK )
     			return

     		elseif not _G.IsMultiplayerPrivilegeAllowed() then
     			UI:MessageBox( "", UI:GetStringByName( "msg_noMultiplayerPrivilegies_live" ), UI.MBS_OK )
     			return
     		end

     	elseif _G.IsPS3() then

     		if not _G.IsPsnSignedIn() then
    			self.hMsgPsnSign = UI:MessageBox( "", UI:GetStringByName( "msg_notSigned_psn" ), UI.MBS_YES_NO )
     			return
     		end

        	if _G.PsnIsContentRatingRestricted() then
        		UI:MessageBox( "", UI:GetStringByName( "msg_contentRatingRestricted_psn" ), UI.MBS_OK )
        		return
        	end

     	end 

	end

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnLeaderboards2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnLeaderboards2()

	UI.LeaderboardsWnd:Setup( self:HasLevelOnStack( "BattleDance" ) and UI.LeaderboardsWnd.modes.MAIN_MENU_BD or UI.LeaderboardsWnd.modes.MAIN_MENU_FD )
	UI.LeaderboardsWnd:Show( true, true )	

end


--
function UI.MenuWnd:OnExit( itemName )

	-- TODO: вернуть, когда будет месседжбокс
--	self.hMsgBoxToWindows = UI:MessageBox( "", UI:GetStringByName( "msg_exitApp" ), UI.MBS_YES_NO )

    sys.concmd( "quit" )

end


--
function UI.MenuWnd:OnOptionsPS3( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnOptionsPS32" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnOptionsPS32()

	local context	= { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }	
	local mode		= self:HasLevelOnStack( "Pause" ) and UI.OptionsWnd.modes.PAUSE or UI.OptionsWnd.modes.MAIN_MENU
	local optionSet	= self:HasLevelOnStack( "Pause" ) and "PS3_Pause" or "PS3"
	
	UI.OptionsWnd:Setup( mode, optionSet, context )
	UI.OptionsWnd:Show( true )	

end


--
function UI.MenuWnd:OnOptionsVideo( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnOptionsVideo2" }
	self:Hide( true, true )	

end


--
function UI.MenuWnd:OnOptionsVideo2()

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }	
	local mode = self:HasLevelOnStack( "Pause" ) and UI.OptionsWnd.modes.PAUSE or UI.OptionsWnd.modes.MAIN_MENU
	
	UI.OptionsWnd:Setup( mode, "Video", context )
	UI.OptionsWnd:Show( true )	

end


--
function UI.MenuWnd:OnOptionsAudio( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnOptionsAudio2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnOptionsAudio2()

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }	
	local mode = self:HasLevelOnStack( "Pause" ) and UI.OptionsWnd.modes.PAUSE or UI.OptionsWnd.modes.MAIN_MENU
	
	UI.OptionsWnd:Setup( mode, "Audio", context )
	UI.OptionsWnd:Show( true )	

end


--
function UI.MenuWnd:OnOptionsGame( itemName )

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnOptionsGame2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnOptionsGame2()

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }	
	local mode = self:HasLevelOnStack( "Pause" ) and UI.OptionsWnd.modes.PAUSE or UI.OptionsWnd.modes.MAIN_MENU
	
	UI.OptionsWnd:Setup( mode, "Game", context )
	UI.OptionsWnd:Show( true )	

end


--
function UI.MenuWnd:OnControls()

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnControls2" }
	self:Hide( true, true )	

end


-- TODO: адаптировать для данного проекта
function UI.MenuWnd:OnControls2()

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }	
	local mode = self:HasLevelOnStack( "Pause" ) and UI.KeyHelpWnd.modes.MENU_PAUSE or UI.KeyHelpWnd.modes.MENU_MAIN
	
	UI.KeyHelpWnd:Setup( mode, context )
	UI.KeyHelpWnd:Show( true )	

end


--
function UI.MenuWnd:OnCampaign()

	sys.concmd( "map campaign" )

end


--
function UI.MenuWnd:OnSkirmish()

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnSkirmish2" }
	self:Hide( true, true )	

end


--
function UI.MenuWnd:OnSkirmish2()

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }			

	UI.LevelsWnd:Setup( UI.LevelsWnd.modes.LOCAL, context )
	UI.LevelsWnd:Show( true )

end


--
function UI.MenuWnd:OnLesson2( params )

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }		

	UI.TutorialWnd:Setup( params.lessonName, context )
	UI.TutorialWnd:Show( true )

end


--
function UI.MenuWnd:OnLan()

	UI:PlayGlobalSound( UI.sounds.showScreen )
	self.commandOnHide = { fn = "OnLan2" }
	self:Hide( true, true )		

end


--
function UI.MenuWnd:OnLan2()

	local context = { level = self.level, stack = UI:CopyTable2( self.stack ), selItem = self:GetSelectedItem() }		

	UI.LevelsWnd:Setup( UI.LevelsWnd.modes.LAN, context )
	UI.LevelsWnd:Show( true )	

end


-- -------------------------
-- items status
-- ------------------------- 

--
function UI.MenuWnd:UpdateItemStatus_Restart( item )

	local levelName = UI:GetCurLevelName()

	local isMp =
    	UI.launchParams.mode == UI.launchModes.LAN_CLIENT	or
    	UI.launchParams.mode == UI.launchModes.LAN_SERVER	or
    	UI.launchParams.mode == UI.launchModes.PSN_CLIENT	or
    	UI.launchParams.mode == UI.launchModes.PSN_SERVER	or
    	UI.launchParams.mode == UI.launchModes.LIVE_CLIENT	or
    	UI.launchParams.mode == UI.launchModes.LIVE_SERVER

	self:SetItemHidden( item, levelName == "" or levelName == "mainmenu" or levelName == "mp_lobby" or isMp )

end


--
function UI.MenuWnd:UpdateItemStatus_LAN( item )

	self:SetItemHidden( item, _G.IsPS3() )	

end


--
function UI.MenuWnd:UpdateItemStatus_PSN( item )

	self:SetItemHidden( item, not _G.IsPS3() )	

end


--
function UI.MenuWnd:UpdateItemStatus_Leaderboards( item )

	if _LB_EMULATE == true then
		self:SetItemHidden( item, false )
		return
	end

	self:SetItemHidden( item, not( _G.IsX360() or _G.IsPS3() ) )

end


--
function UI.MenuWnd:UpdateItemStatus_Exit( item )

	self:SetItemHidden( item, _G.IsX360() or _G.IsPS3() )

end


--
function UI.MenuWnd:UpdateItemStatus_OptionsPC( item )

	self:SetItemHidden( item, not _G.IsPC() )

end


--
function UI.MenuWnd:UpdateItemStatus_OptionsPS3( item )

	self:SetItemHidden( item, not _G.IsPS3() )

end


-- ---------------------------------------------------------------------------
-- UI.MenuWnd_Main
-- ---------------------------------------------------------------------------

UI.MenuWnd_Main = {}
local mm = UI.MenuWnd_Main

-- ------------------------------
-- window definition
-- ------------------------------

UI.MenuWnd_Main.def =
{
	className	= "Wnd",
	prototype	= "MenuWnd",

	props =
	{
		name 			= "MenuWnd_Main",
	},

	layers =
	{
		-- MAIN_EFFECT
		{
			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "laptopMini_main",
				defaultAnimation    = "idle",

				links =
				{     
					{
						objName		= "bg",
						layer		= "UI.LaptopWnd_mini.layers.BG_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "sun",
						layer		= "UI.LaptopWnd_mini.layers.LOGO_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "slot_sml",
						layer		= "UI.LaptopWnd_mini.layers.LAPTOP_FRAME_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "keytip_panel",
						wnd			= "UI.Menu_Main_KeyTipPanel",
						animParams	= UI.EffectAnimParams.POS,
					},
				}
			}} 
		},

		-- LAPTOP_CONTENT_EFFECT
		{
			id			= UI.LaptopWnd_mini.layers.LAPTOP_CONTENT_EFFECT,

			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "mainMenu_content",
				defaultAnimation    = "idle",

				links =
				{     
					{
						objName		= "caption",
						layer		= "UI.MenuWnd.layers.CAPTION",
						animParams	= UI.EffectAnimParams.POS + UI.EffectAnimParams.SIZE + UI.EffectAnimParams.ALIGNMENT + UI.EffectAnimParams.COLOR,
					},

					{
						objName		= "list",
						wnd			= "UI.Menu_Main_ListWnd",
						animParams	= UI.EffectAnimParams.POS + UI.EffectAnimParams.COLOR,
					},
				}
			}}
		},
	},

	children = { "UI.Menu_Main_ListWnd", "UI.Menu_Main_KeyTipPanel" --[[ TODO: вернуть "UI.Menu_Main_WaitingWnd" ]] }
}


-- ---------------------------------------------------------------------------
-- UI.MenuWnd_Pause
-- ---------------------------------------------------------------------------

UI.MenuWnd_Pause = {}
local pm = UI.MenuWnd_Pause

-- ------------------------------
-- window definition
-- ------------------------------

UI.MenuWnd_Pause.def =
{
	className	= "Wnd",
	prototype	= "MenuWnd",

	props =
	{
		name 			= "MenuWnd_Pause",
	},

	layers =
	{
		-- MAIN_EFFECT
		{
			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "laptopMini_main",
				defaultAnimation    = "idle",

				links =
				{     
					{
						objName		= "bg",
						layer		= "UI.LaptopWnd_mini.layers.BG_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "sun",
						layer		= "UI.LaptopWnd_mini.layers.LOGO_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "slot_sml",
						layer		= "UI.LaptopWnd_mini.layers.LAPTOP_FRAME_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "keytip_panel",
						wnd			= "UI.Menu_Pause_KeyTipPanel",
						animParams	= UI.EffectAnimParams.POS,
					},
				}
			}} 
		},

		-- BG_EFFECT
		{
			id			= UI.LaptopWnd_mini.layers.BG_EFFECT,

			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "bg_blackout",
				defaultAnimation    = "idle",
			}}
		},

		-- LAPTOP_CONTENT_EFFECT
		{
			id			= UI.LaptopWnd_mini.layers.LAPTOP_CONTENT_EFFECT,

			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "mainMenu_content",
				defaultAnimation    = "idle",

				links =
				{     
					{
						objName		= "caption",
						layer		= "UI.MenuWnd.layers.CAPTION",
						animParams	= UI.EffectAnimParams.POS + UI.EffectAnimParams.SIZE + UI.EffectAnimParams.ALIGNMENT + UI.EffectAnimParams.COLOR,
					},

					{
						objName		= "list",
						wnd			= "UI.Menu_Pause_ListWnd",
						animParams	= UI.EffectAnimParams.POS + UI.EffectAnimParams.COLOR,
					},
				}
			}}
		},
	},

	children = { "UI.Menu_Pause_ListWnd", "UI.Menu_Pause_KeyTipPanel" }
}

-- ---------------------------------------------------
-- UI.Menu_Main_ListWnd
-- ---------------------------------------------------

UI.Menu_Main_ListWnd =
{
	def =
	{
    	className 	= "Wnd",
    	prototype	= "LaptopWnd_ListWnd",

    	props =
    	{
    		name			= "list",
    	},	

    	layers =
    	{
    		-- MAIN_EFFECT
    		{
    			layerType	= UI.LAYER_EFFECT,
    			layerStyle	= UI.WLS_RESIZABLE,

    			effects =
    			{{
    				defName				= "menu_list",
    				defaultAnimation    = "idle",

    				links =
    				{
    					{
    						objName		= "self",
    						animParams	= UI.EffectAnimParams.SIZE,
    					},
    				}
    			}}
    		},
    	}
	},

	btnPrototypeName	= "Menu_ListBtn",

    effectInfo =
    {
    	main =
    	{
    		slotObjNamePrefix	= "button_",
    		scrollObjName		= "",
			animIdle			= "idle",
    	}
    }
}


-- ---------------------------------------------------
-- UI.Menu_Pause_ListWnd
-- ---------------------------------------------------

UI.Menu_Pause_ListWnd =
{
	def =
	{
    	className 	= "Wnd",
    	prototype	= "LaptopWnd_ListWnd",

    	props =
    	{
    		name			= "list",
    	},	

    	layers =
    	{
    		-- MAIN_EFFECT
    		{
    			layerType	= UI.LAYER_EFFECT,
    			layerStyle	= UI.WLS_RESIZABLE,

    			effects =
    			{{
    				defName				= "menu_list",
    				defaultAnimation    = "idle",

    				links =
    				{
    					{
    						objName		= "self",
    						animParams	= UI.EffectAnimParams.SIZE,
    					},
    				}
    			}}
    		},
    	}
	},

	btnPrototypeName	= "Menu_ListBtn",

    effectInfo =
    {
    	main =
    	{
    		slotObjNamePrefix	= "button_",
    		scrollObjName		= "",
			animIdle			= "idle",
    	}
    }
}

-- ---------------------------------------------------------------------------
-- UI.Menu_ListBtn
-- ---------------------------------------------------------------------------

UI.Menu_ListBtn =
{
	def =
    {
    	className 	= "Wnd",
    	prototype	= "LaptopWnd_ListBtn",

    	props =
    	{
    		name			= "Menu_ListBtn",
    		isPrototype		= true,
    	},

        layers =
        {
        	-- MAIN_EFFECT
        	{
        		layerType	= UI.LAYER_EFFECT,
        		layerStyle	= UI.WLS_RESIZABLE,

    			effects =
    			{{
    				defName				= "menu_btn",
    				defaultAnimation    = "idle",

    				links =
    				{
    					{
    						objName		= "self",
    						animParams	= UI.EffectAnimParams.SIZE,
    					},

    					{
    						objName		= "title",
							layer		= "UI.Menu_ListBtn.layers.TEXT",
    						animParams	= UI.EffectAnimParams.SIZE + UI.EffectAnimParams.POS + UI.EffectAnimParams.ALIGNMENT + UI.EffectAnimParams.COLOR,
    					},
    				}
    			}}
        	},

        	-- TEXT
        	{
       			layerType	= UI.LAYER_TEXT,
				blendMode	= UI.BM_COLOR,

       			formatInfoSz= { 1, 1 },
       			formatFlags	= FONT.TF_NOCLIP + FONT.TF_SINGLELINE,
       			font =
        		{
       				scaledForResolution = true,
    				patternName = UI:GetFontPattern( "Medium_outl" ), 
       			},
        	},
        }
    }
} 


-- -------------------------------------------
-- const
-- -------------------------------------------

UI.Menu_ListBtn.effectInfo =
{
	main  =
	{
		animIdle					= "idle",
		animSelect					= "select",
		animOnSelect 				= "",
		animOnRelease				= "",
		animDisabled				= "disable",
		animDisabledSelect			= "",
		animFirstSelection          = "first_select",
		animFirstSelctionDisabled	= "first_disable",
	},
}


-- ---------------------------------------------------------------------------
-- UI.Menu_Main_KeyTipPanel
-- ---------------------------------------------------------------------------

UI.Menu_Main_KeyTipPanel =
{
	def = 
	{
    	className	= "Wnd",
    	prototype	= "EffectKeyTipPanel",

    	props =
    	{
    		name = "keyTipPanel"
    	},
	},

	btnList =
	{
		{ key =	UI.Keys.KEY_TAB,	tip = "",					bEnabled = false	},
		{ key =	UI.Keys.KEY_SPACE,	tip = "",					bEnabled = false	},
		{ key =	UI.Keys.KEY_ENTER,	tip = "keytip_choose",		bEnabled = false 	},
		{ key =	UI.Keys.KEY_ESCAPE, tip = "keytip_return",		bEnabled = false	},
	},
}


-- ---------------------------------------------------------------------------
-- UI.Menu_Pause_KeyTipPanel
-- ---------------------------------------------------------------------------

UI.Menu_Pause_KeyTipPanel =
{
	def = 
	{
    	className	= "Wnd",
    	prototype	= "EffectKeyTipPanel",

    	props =
    	{
    		name = "keyTipPanel"
    	},
	},

	btnList =
	{
		{ key =	UI.Keys.KEY_TAB,	tip = "",					bEnabled = false	},
		{ key =	UI.Keys.KEY_SPACE,	tip = "",					bEnabled = false	},
		{ key =	UI.Keys.KEY_ENTER,	tip = "keytip_choose",		bEnabled = false 	},
		{ key =	UI.Keys.KEY_ESCAPE, tip = "keytip_return",		bEnabled = false	},
	},
}
