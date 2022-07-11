game:addlocalizedstring("LUA_MENU_LANGUAGE_BUTTON_DESC", "Change your game language.")
game:addlocalizedstring("LUA_MENU_LANGUAGE_POPUP_RESTART_REQUIRED_TEXT",
    "WARNING: To work properly, you need to have your language's zone files in the zone directory of your game root.\n\nYou have changed your game language, do you wish to restart?")
game:addlocalizedstring("LUA_MENU_LANGUAGE_POPUP_NO_ZONE_FOUND_TITLE", "LANGUAGE NOT FOUND")
game:addlocalizedstring("LUA_MENU_LANGUAGE_POPUP_NO_ZONE_FOUND_TEXT",
    "We are unable to find the language folder you have selected. To avoid bugs, we will not change anything.")
game:addlocalizedstring("MENU_ENGLISH_SAFE", "Arabic")
game:addlocalizedstring("LUA_MENU_LANGUAGE_EASTER_EGG_NAME", "Jok \"Llama\" Arwent")
game:addlocalizedstring("LUA_MENU_LANGUAGE_EASTER_EGG_RANK", "H1-MOD Contributor")
game:addlocalizedstring("LUA_MENU_LANGUAGE_EASTER_EGG_LOCATION", "Location: UNDISCLOSED")

local available_languages = {"english_safe", "simplified_chinese", "traditional_chinese", "english", "french", "german",
                             "italian", "japanese_partial", "korean", "polish", "portuguese", "russian", "spanish"}
local current_language = "english"

function get_current_language()
    current_language = game:getcurrentgamelanguage()
end

function set_language(value)
    local file_path = "h1-mod/language.txt"
    local file = io.open(file_path, "w")
    file:write(value)
    file:close()
end

function does_zone_folder_exists(language)
    return io.directoryexists("zone/" .. language)
end

function create_fancy_text(menu)
    local template = {
        leftAnchor = false,
        topAnchor = false,
        rightAnchor = false,
        bottomAnchor = false,
        left = 150,
        width = 385,
        top = 150,
        height = 30,
        font = CoD.TextSettings.H1TitleFont.Font,
        horizontalAlignment = LUI.AdjustAlignmentForLanguage(LUI.Alignment.Left),
        verticalAlignment = LUI.VerticalAlignment.Top,
        alpha = 1
    }

    local texts = {"LUA_MENU_LANGUAGE_EASTER_EGG_NAME", "LUA_MENU_LANGUAGE_EASTER_EGG_RANK", "LUA_MENU_LANGUAGE_EASTER_EGG_LOCATION"}

    for i = 1, #texts do
        template.top = template.top + template.height + 5 * 1.2
        template.height = template.height * 0.75

        local text = LUI.UIText.new(template)
        menu:addElement(text)
        text:setText(Engine.Localize(texts[i]))
        text:setTextStyle(CoD.TextStyle.MW1Title)
        text:setupAutoScaleText()
        text:setUsePulseFX(true, false)
        text:registerAnimationState("hide", {
            alpha = 0
        })
        text:animateInSequence({{"default", 5000 + (3 - i) * 1000}, {"hide", 1000}}, nil, true, true)
    end
end

get_current_language()

LUI.addmenubutton("pc_controls", {
    index = 4,
    text = Engine.Localize("MENU_LANGUAGE"),
    description = Engine.Localize("LUA_MENU_LANGUAGE_BUTTON_DESC"),
    callback = function()
        LUI.FlowManager.RequestAddMenu(nil, "language_menu")
    end
})

LUI.MenuBuilder.registerType("language_menu", function(unk1)
    local menu;

    if Engine.InFrontend() and Engine.IsMultiplayer() then
        menu = LUI.MenuTemplate.new(unk1, {
            menu_title = Engine.ToUpperCase(Engine.Localize("MENU_LANGUAGE")),
            exclusiveController = 0,
            persistentBackground = PersistentBackground.Variants.Depot
        })

        if Engine.GetDvarBool("virtualLobbyPresentable") then
            Cac.NotifyVirtualLobby("depot", 0)
            create_fancy_text(menu)
        end
    else
        menu = LUI.MenuTemplate.new(unk1, {
            menu_title = Engine.ToUpperCase(Engine.Localize("MENU_LANGUAGE")),
            exclusiveController = 0
        })
    end

    for i = 1, #available_languages do
        if does_zone_folder_exists(available_languages[i]) then
            menu:AddButton(Engine.Localize(string.format("MENU_%s",
                Engine.ToUpperCase(available_languages[i]))), function()
                LUI.yesnopopup({
                    title = Engine.Localize("MENU_CCS_RESTART_CONFIRMATION_TITLE"),
                    text = Engine.Localize("LUA_MENU_LANGUAGE_POPUP_RESTART_REQUIRED_TEXT"),
                    callback = function(result)
                        if (result) then
                            if not does_zone_folder_exists(available_languages[i]) then
                                LUI.confirmationpopup({
                                    title = Engine.Localize("LUA_MENU_LANGUAGE_POPUP_NO_ZONE_FOUND_TITLE"),
                                    text = Engine.Localize("LUA_MENU_LANGUAGE_POPUP_NO_ZONE_FOUND_TEXT"),
                                    buttontext = Engine.Localize("MENU_OK"),
                                    callback = function()
                                        LUI.FlowManager.RequestLeaveMenu(popup)
                                    end
                                })

                                return
                            end

                            set_language(available_languages[i])
                            updater.relaunch()
                        else
                            LUI.FlowManager.RequestLeaveMenu(popup)
                        end
                    end
                })
            end, available_languages[i] == current_language, true, nil, nil)
        end
    end

    menu:AddBackButton(function(unk1)
        if Engine.InFrontend() and Engine.IsMultiplayer() then
            if Engine.GetDvarBool("virtualLobbyPresentable") then
                Cac.NotifyVirtualLobby("leave_depot", 0)
            end
        end

        Engine.PlaySound(CoD.SFX.MenuBack)
        LUI.FlowManager.RequestLeaveMenu(unk1)
    end)

    return menu
end)

if Engine.InFrontend() and Engine.IsMultiplayer() then
    VLobby.InitMenuMode("language_menu", VirtualLobbyModes.LUI_MODE_LOBBY, PersistentBackground.FadeFromBlackSlow,
        PersistentBackground.FadeFromBlackSlow)
end
