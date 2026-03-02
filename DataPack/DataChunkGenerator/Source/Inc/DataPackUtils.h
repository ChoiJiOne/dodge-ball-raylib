#pragma once

#include <string>
#include <iostream>
#include <vector>

#include <msgpack.hpp>

class DataPackUtils
{
public:
	static bool ParseBool(const std::string& fieldValue);
	
	static std::vector<int32_t> ParseIntArray(const std::string& fieldValue);
	static std::vector<float> ParseFloatArray(const std::string& fieldValue);
	static std::vector<std::string> ParseStringArray(const std::string& fieldValue);
	static std::vector<bool> ParseBoolArray(const std::string& fieldValue);

private:
	static constexpr std::string_view STRING_VALUE_TRUE = "true";
	static constexpr std::string_view STRING_VALUE_FALSE = "false";
};