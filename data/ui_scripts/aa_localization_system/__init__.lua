if game:getcurrentgamelanguage() == "english" then
	return
end

-- set table full of localized strings
localizations = {}

-- requiring the actual game language localization file
require(string.format("localizations.%s", game:getcurrentgamelanguage()))

-- adding them all
for k, v in pairs(localizations) do
    local exists = game:localizedstringexists(k)

    if not exists then
        game:addlocalizedstring(k, v)
    else
        game:replacelocalizedstring(k, v)
    end
end
