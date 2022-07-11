#include <std_include.hpp>
#include "loader/component_loader.hpp"
#include "localized_strings.hpp"
#include <utils/hook.hpp>
#include <utils/string.hpp>
#include <utils/concurrency.hpp>
#include "game/game.hpp"

namespace localized_strings
{
	namespace
	{
		utils::hook::detour seh_string_ed_get_string_hook;

		using localized_map = std::unordered_map<std::string, std::string>;
		utils::concurrency::container<localized_map> localized_overrides;

		const char* seh_string_ed_get_string(const char* reference)
		{
			return localized_overrides.access<const char*>([&](const localized_map& map)
			{
				const auto entry = map.find(reference);
				if (entry != map.end())
				{
					return utils::string::va("%s", entry->second.data());
				}

				return seh_string_ed_get_string_hook.invoke<const char*>(reference);
			});
		}
	}

	bool add(const std::string& key, const std::string& value)
	{
		bool result;

		localized_overrides.access([&](localized_map& map)
		{
			if (!map.contains(key))
			{
				map[key] = value;
				result = true;
				return;
			}

			// put a warning in the console that the localized string is already existing
			result = false;
		});

		return result;
	}

	void override(const std::string& key, const std::string& value)
	{
		localized_overrides.access([&](localized_map& map)
		{
			map[key] = value;
		});
	}

	bool exists(const std::string& key)
	{
		bool result;

		localized_overrides.access([&](const localized_map& map)
		{
			result = map.contains(key);
		});

		return result;
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			// Change some localized strings
			seh_string_ed_get_string_hook.create(SELECT_VALUE(0x3E6CE0_b, 0x585DA0_b), &seh_string_ed_get_string);
		}
	};
}

REGISTER_COMPONENT(localized_strings::component)