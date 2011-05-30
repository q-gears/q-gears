-- ----------------------------------------------------------------------------
--
-- Workfile: StartWnd.lua
-- Created by: SoftKitty
-- Copyright é 2006, Targem LLC. All rights reserved.-- 
--
-- ----------------------------------------------------------------------------
--  $Id: startwnd.lua 2361 2011-04-14 11:55:51Z elena_evdokimova $
-- ----------------------------------------------------------------------------

UI.StartWnd = {}
local st = UI.StartWnd

local resolution = UI:GetCoordinateSystemForAspect( cvars.r_height / cvars.r_width )

-- -------------------------------
-- window definition
-- -------------------------------

local l_numBaseLayers = UI:GetTableLength( UI.FullScreenWnd.layers )

UI.StartWnd.def =
{
	className	= "Wnd",
	prototype	= "FullScreenWnd",

	props =
	{
		name			= "StartWnd",
	},

	layers =
	{
		numLayers = l_numBaseLayers + 2,

		-- MAIN_EFFECT
		{
			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "start_main",
				defaultAnimation    = "idle",

				links =
				{     
					{
						objName		= "bg",
						layer		= "UI.StartWnd.layers.BG_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "sun",
						layer		= "UI.StartWnd.layers.LOGO_EFFECT",
						animParams	= UI.EffectAnimParams.POS,
					},

					{
						objName		= "press_start",
						layer		= "UI.StartWnd.layers.PRESS_KEY_TEXT",
						animParams	= UI.EffectAnimParams.POS + UI.EffectAnimParams.SIZE + UI.EffectAnimParams.ALIGNMENT + UI.EffectAnimParams.COLOR + UI.EffectAnimParams.ALPHA,
					},
				}
			}}

		},

		-- BG_EFFECT
		{
			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "bg",
				defaultAnimation    = "idle",
			}}
		},

		-- LOGO_EFFECT
		{
			layerType	= UI.LAYER_EFFECT,
			layerStyle	= UI.WLS_RESIZABLE,

			effects =
			{{
				defName				= "logo",
				defaultAnimation    = "idle",
			}}
		},

		-- PRESS_KEY_TEXT
		{
			layerType	= UI.LAYER_TEXT,
			blendMode	= UI.BM_COLOR,

   			formatFlags	 = FONT.TF_SINGLELINE + FONT.TF_NOCLIP,
   			formatInfoSz = { 1, 1 },
   			font =
			{
   				scaledForResolution = true,
   				patternName = UI:GetFontPattern( "Large_outl" ),
   			},

			text = UI:GetStringForPlatform( "pressKeyToContinue" ),			
		},
	}
}

-- -------------------------------
-- interface functions
-- -------------------------------

--
function UI.StartWnd:Setup( mode )

	if UI:Val2Key( self.modes, mode ) == "" then
		sys.log( "UI.StartWnd:Setup()[ERROR]: invalid 1-st parameter (\"mode\"); one of the \"UI.StartWnd.modes\" values expected, got \"%s\"", tostring( mode ) )
		return
	end

	self.mode = mode

end


-- -------------------------------
-- const
-- -------------------------------

-- from FullScreenWnd
st.bgEffectName			= "bg"

st.showAnimations		= {}
st.hideAnimations		= { "Hide" }
st.showAnimations_first		= { "ShowFirst" }
st.showAnimations_afterMenu	= { "ShowAfterMenu" }


st.layers =
{
	MAIN_EFFECT		= 0, 
    BG_EFFECT       = 1, 
	LOGO_EFFECT		= 2,
	PRESS_KEY_TEXT	= 3,
}

st.modes =
{
	FIRST		= 1,
	AFTER_MENU	= 2,
}

-- -------------------------------
-- animations
-- -------------------------------

st.animations = {}

st.animations.ShowFirst = UI:CopyTable2( UI.FullScreenWnd.animationShowLayersBase )
st.animations.ShowFirst.animInfo =
{
	{ layer = st.layers.MAIN_EFFECT,	anim = "show",			animIdle = "idle" },
	{ layer = st.layers.BG_EFFECT,		anim = "show",			animIdle = "idle" },
	{ layer = st.layers.LOGO_EFFECT,	anim = "show_first",	animIdle = "idle" },
}

st.animations.ShowAfterMenu= UI:CopyTable2( UI.FullScreenWnd.animationShowLayersBase )
st.animations.ShowAfterMenu.animInfo =
{
	{ layer = st.layers.LOGO_EFFECT,	anim = "restore",	animIdle = "idle" },
}


st.animations.Hide = UI:CopyTable2( UI.FullScreenWnd.animationHideLayersBase )
st.animations.Hide.animInfo =
{
	{ layer = st.layers.LOGO_EFFECT,	anim = "hide_in_menu" }
}

-- -------------------------------
-- vars
-- -------------------------------

st.mode = st.modes.FIRST

-- -------------------------------
-- work functions
-- -------------------------------

--
function UI.StartWnd:StartShowAnimation( bPlayStartAnim )

	if self.mode == self.modes.FIRST then
		self.showAnimations = self.showAnimations_first

	elseif self.mode == self.modes.AFTER_MENU then
		self.showAnimations = self.showAnimations_afterMenu
	end 

	UI.FullScreenWnd.StartShowAnimation( self, bPlayStartAnim )

end


--
function UI.StartWnd:F_OnJoystickKeyDown( key, wndThatReceivedInput, gamepadType, controllerIdx )

	if UI.Wnd.F_OnJoystickKeyDown( self, key, wndThatReceivedInput, gamepadType, controllerIdx ) then
		return true
	end

	if key == UI.Keys.KEY_XINPUT_START or key == UI.Keys.KEY_CELL_START then
		self:ProceedToMenu()
		return true

	else
		return self:HandleKey( key, controllerIdx )	
	end

end


--
function UI.StartWnd:F_OnJoystickKeyDown_1( key, wndThatReceivedInput, gamepadType, controllerIdx )

	if UI.Wnd.F_OnJoystickKeyDown_1( self, key, wndThatReceivedInput, gamepadType, controllerIdx ) then
		return true
	end

	if key == UI.Keys.KEY_XINPUT1_START or key == UI.Keys.KEY_CELL1_START then
		self:ProceedToMenu()
		return true

	else
		return self:HandleKey( key, controllerIdx )	
	end

end


--
function UI.StartWnd:F_OnMouseLButtonDown( mouseX, mouseY, wndThatReceivedInput )

	if self:OnMouseLButtonDown( mouseX, mouseY, wndThatReceivedInput ) then
		return true
	end

	self:ProceedToMenu()	
	return true

end   


--
function UI.StartWnd:OnEnter( key )

	self:ProceedToMenu()	
	return true

end


--
function UI.StartWnd:ProceedToMenu()

	self.commandOnHide = { fn = "ProceedToMenu2" }
	self:Hide( true, true )

end


--
function UI.StartWnd:ProceedToMenu2()

	UI.MenuWnd_Main:SetShowModeFromStartWnd()
	UI:ShowMenuInternal( "main", {}, nil, true )

end


--
function UI.StartWnd:F_OnEventSaveUiState()

	UI.store.StartWnd =
	{
		mode	= self.mode
	}

end


--
function UI.StartWnd:F_OnEventRestoreUiState()

	if UI.store.StartWnd then

		self:Setup( UI.store.StartWnd.mode )
		UI.store.StartWnd = nil

	end
end