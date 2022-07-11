local Lobby = luiglobals.Lobby
local SystemLinkJoinMenu = LUI.mp_menus.SystemLinkJoinMenu

if (not SystemLinkJoinMenu) then
	return
end

game:addlocalizedstring("MENU_NUMPLAYERS", "Players")
game:addlocalizedstring("MENU_PING", "Ping")
game:addlocalizedstring("SERVERLIST_PLAYER_COUNT", "&&1 Players")
game:addlocalizedstring("SERVERLIST_SERVER_COUNT", "&&1 Servers")

local columns = {
	{
		offset = 40,
		text = "@MENU_HOST_NAME",
		dataindex = 0
	},
	{
		offset = 500,
		text = "@MENU_MAP",
		dataindex = 1
	},
	{
		offset = 725,
		text = "@MENU_TYPE1",
		dataindex = 3
	},
	{
		offset = 920,
		text = "@MENU_NUMPLAYERS",
		dataindex = 2
	},
	{
		offset = 1070,
		text = "@MENU_PING",
		dataindex = 4
	},
	{
		offset = 10,
		image = "s1_icon_locked",
		customelement = function(value, offset)
			return LUI.UIImage.new({
				leftAnchor = true,
				topAnchor = true,
				height = 20,
				width = 20,
				left = offset,
				top = 2,
				material = RegisterMaterial(CoD.Material.RestrictedIcon),
				alpha = value == "1" and 1 or 0,
				color = {
					r = 1,
					b = 1,
					g = 1
				}
			})
		end,
		dataindex = 5
	}
}

function textlength(text, font, height)
	local _, _, width = luiglobals.GetTextDimensions(text, font, height)
	return width
end

function trimtext(text, font, height, maxwidth)
	if (maxwidth < 0) then
		return text
	end

	while (textlength(text, font, height) > maxwidth) do
		text = text:sub(1, #text - 1)
	end

	return text
end

SystemLinkJoinMenu.AddHeaderButton = function(menu, f12_arg1, width)
	local state = CoD.CreateState(0, f12_arg1, nil, nil, CoD.AnchorTypes.TopLeft)
	state.width = width
	local element = LUI.UIElement.new(state)
	local button = SystemLinkJoinMenu.CreateButton("header", 24)

	button:addElement(LUI.Divider.new(CoD.CreateState(nil, 0, nil, nil, CoD.AnchorTypes.TopLeftRight), 40,
		LUI.Divider.Grey))
	button:makeNotFocusable()
	button:addElement(LUI.Divider.new(CoD.CreateState(nil, 0, nil, nil, CoD.AnchorTypes.BottomLeftRight), 40,
		LUI.Divider.Grey))

	button.m_eventHandlers = {}

	for i = 1, #columns do
		if (columns[i].text) then
			SystemLinkJoinMenu.MakeText(button.textHolder, columns[i].offset, Engine.Localize(columns[i].text), nil)
		elseif (columns[i].image) then
			local image = LUI.UIImage.new({
				leftAnchor = true,
				topAnchor = true,
				height = 20,
				width = 20,
				top = 2,
				left = columns[i].offset,
				material = RegisterMaterial(columns[i].image)
			})
			button.textHolder:addElement(image)
		end
	end

	element:addElement(button)
	menu:addElement(element)
end

SystemLinkJoinMenu.AddServerButton = function(menu, controller, index)
	local button = SystemLinkJoinMenu.CreateButton(index or "header", 24)
	button:makeFocusable()
	button.index = index
	button:addEventHandler("button_action", SystemLinkJoinMenu.OnJoinGame)

	local gettext = function(i)
		local text = Lobby.GetServerData(controller, index, columns[i].dataindex)
		if (columns[i].customelement) then
			text = columns[i].customelement(text)
		end

		local islast = not columns[i + 1]
		local end_ = islast and 1130 or columns[i + 1].offset
		local maxlength = end_ - columns[i].offset

		if (maxlength < 0) then
			maxlength = columns[i].offset - end_
		end

		if (not islast) then
			maxlength = maxlength - 50
		end

		return trimtext(text, CoD.TextSettings.TitleFontSmall.Font, 14, maxlength)
	end

	for i = 1, #columns do
		if (columns[i].customelement) then
			local value = Lobby.GetServerData(controller, index, columns[i].dataindex)
			local element = columns[i].customelement(value, columns[i].offset)
			button.textHolder:addElement(element)
		else
			SystemLinkJoinMenu.MakeText(button.textHolder, columns[i].offset, gettext(i), luiglobals.Colors.h1.medium_grey)
		end
	end

	menu.list:addElement(button)
	return button
end

SystemLinkJoinMenu.MakeText = function(menu, f5_arg1, text, color)
	local state = CoD.CreateState(f5_arg1, nil, f5_arg1 + 200, nil, CoD.AnchorTypes.Left)
	state.font = CoD.TextSettings.TitleFontSmall.Font
	state.top = -6
	state.height = 14
	state.alignment = nil
	state.glow = LUI.GlowState.None
	state.color = color

	local el = LUI.UIText.new(state)
	el:registerAnimationState("focused", {
		color = luiglobals.Colors.white
	})

	el:registerEventHandler("focused", function(element, event)
		element:animateToState("focused", 0)
	end)

	el:registerEventHandler("unfocused", function(element, event)
		element:animateToState("default", 0)
	end)

	el:setText(text)
	menu:addElement(el)

	return el
end

function menu_systemlink_join(f19_arg0, f19_arg1)
	local width = 1145

	local menu = LUI.MenuTemplate.new(f19_arg0, {
		menu_title = "@PLATFORM_SYSTEM_LINK_TITLE",
		menu_width = width,
		menu_top_indent = 20,
		disableDeco = true,
		spacing = 1
	})

	SystemLinkJoinMenu.AddHeaderButton(menu, 80, width)
	SystemLinkJoinMenu.AddLowerCounter(menu, width)
	SystemLinkJoinMenu.UpdateCounterText(menu, nil)
	Lobby.BuildServerList(Engine.GetFirstActiveController())

	local playercount = LUI.UIText.new({
		rightAnchor = true,
		topAnchor = true,
		height = 18,
		bottom = 58,
		font = CoD.TextSettings.BodyFont.Font,
		width = 300,
		alignment = LUI.Alignment.Right,
	})
	menu:addElement(playercount)

	local servercount = LUI.UIText.new({
		rightAnchor = true,
		topAnchor = true,
		height = 18,
		bottom = 58 - 25,
		font = CoD.TextSettings.BodyFont.Font,
		width = 300,
		alignment = LUI.Alignment.Right,
	})
	menu:addElement(servercount)

	menu.list:registerEventHandler(LUI.UIScrollIndicator.UpdateEvent, function(element, event)
		SystemLinkJoinMenu.UpdateCounterText(menu, event)

		playercount:setText(Engine.Localize("@SERVERLIST_PLAYER_COUNT", serverlist:getplayercount()))
		servercount:setText(Engine.Localize("@SERVERLIST_SERVER_COUNT", serverlist:getservercount()))
	end)

	SystemLinkJoinMenu.UpdateGameList(menu)
	menu:registerEventHandler("updateGameList", SystemLinkJoinMenu.UpdateGameList)

	LUI.ButtonHelperText.ClearHelperTextObjects(menu.help, {
		side = "all"
	})

	menu:AddHelp({
		name = "add_button_helper_text",
		button_ref = "button_alt1",
		helper_text = Engine.Localize("@MENU_SB_TOOLTIP_BTN_REFRESH"),
		side = "right",
		clickable = true,
		priority = -1000
	}, function(f21_arg0, f21_arg1)
		SystemLinkJoinMenu.RefreshServers(f21_arg0, f21_arg1, menu)
	end)

	menu:AddHelp({
		name = "add_button_helper_text",
		button_ref = "button_action",
		helper_text = Engine.Localize("@MENU_JOIN_GAME1"),
		side = "left",
		clickable = false,
		priority = -1000
	}, nil, nil, true)

	menu:AddBackButton()

	Lobby.RefreshServerList(Engine.GetFirstActiveController())

	return menu
end

LUI.MenuBuilder.m_types_build["menu_systemlink_join"] = menu_systemlink_join
