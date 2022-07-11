#pragma once

namespace localized_strings
{
	bool add(const std::string& key, const std::string& value);
	void override(const std::string& key, const std::string& value);
	bool exists(const std::string& key);
}
