#pragma once

#include "game/game.hpp"

namespace fastfiles
{
	bool exists(const std::string& zone);

	std::string get_current_fastfile();

	void enum_assets(const game::XAssetType type,
		const std::function<void(game::XAssetHeader)>& callback, const bool includeOverride);
}
