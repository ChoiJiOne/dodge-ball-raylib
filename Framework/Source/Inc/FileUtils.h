#pragma once

#include <string>
#include <vector>

#include "Result.h"

class FileUtils
{
public:
	static Result<std::vector<uint8_t>> ReadFile(const std::string& path);
	static Result<std::vector<uint8_t>> ReadFile(const std::wstring& path);

	static Result<void> WriteFile(const std::string& path, const std::vector<uint8_t>& buffer);
	static Result<void> WriteFile(const std::wstring& path, const std::vector<uint8_t>& buffer);

	static Result<void> MakeDirectory(const std::string& path);
	static Result<void> MakeDirectory(const std::wstring& path);

	static bool IsValidPath(const std::string& path);
	static bool IsValidPath(const std::wstring& path);

	static std::string GetBasePath(const std::string& path); // NOTE: 전체 경로에서 베이스 경로를 얻습니다 (AA\\BB\\CC\\D.txt > AA\\BB\\CC\\)
	static std::wstring GetBasePath(const std::wstring& path); // NOTE: 전체 경로에서 베이스 경로를 얻습니다 (AA\\BB\\CC\\D.txt > AA\\BB\\CC\\)

	static std::string RemoveBasePath(const std::string& path); // NOTE: 전체 경로에서 베이스 경로를 삭제합니다 (AA\\BB\\CC\\D.txt > D.txt)
	static std::wstring RemoveBasePath(const std::wstring& path); // NOTE: 전체 경로에서 베이스 경로를 삭제합니다 (AA\\BB\\CC\\D.txt > D.txt)

	static std::string GetFileExtension(const std::string& path); // NOTE: 전체 경로에서 파일 확장자를 얻습니다 (AA\\BB\\CC\\D.txt > txt)
	static std::wstring GetFileExtension(const std::wstring& path); // NOTE: 전체 경로에서 파일 확장자를 얻습니다. (AA\\BB\\CC\\D.txt > txt)
};