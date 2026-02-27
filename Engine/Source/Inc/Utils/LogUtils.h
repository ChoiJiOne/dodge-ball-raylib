#pragma once

#include <format>
#include <string>
#include <string_view>

#include <raylib.h>

class LogUtils 
{
public:
	template <typename... Args>
	static void Info(
		std::string_view file, 
		int32_t line,
		std::string_view func,
		std::format_string<Args...> fmt, 
		Args&&... args) 
	{
		LogInternal(LOG_INFO, file, line, func, fmt, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static void Warn(
		std::string_view file, 
		int32_t line,
		std::string_view func,
		std::format_string<Args...> fmt, 
		Args&&... args) 
	{
		LogInternal(LOG_WARNING, file, line, func, fmt, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static void Error(
		std::string_view file, 
		int32_t line,
		std::string_view func,
		std::format_string<Args...> fmt, 
		Args&&... args) 
	{
		LogInternal(LOG_ERROR, file, line, func, fmt, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static void Fatal(
		std::string_view file, 
		int32_t line,
		std::string_view func,
		std::format_string<Args...> fmt, 
		Args&&... args) 
	{
		LogInternal(LOG_FATAL, file, line, func, fmt, std::forward<Args>(args)...);
	}

private:
	template <typename... Args>
	static void LogInternal(
		int32_t level, 
		std::string_view file, 
		int line, std::string_view func,
		std::format_string<Args...> fmt, 
		Args&&... args) 
	{

		std::string msg = std::format(fmt, std::forward<Args>(args)...);
		std::string logLine = std::format("[{}:{}] ({}) {}", file, line, func, msg);
		TraceLog(level, logLine.c_str());
	}
};