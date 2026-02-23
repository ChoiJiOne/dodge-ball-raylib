#include <windows.h>
#include <Shlwapi.h>

#include "FileUtils.h"
#include "StringUtils.h"

Result<std::vector<uint8_t>> FileUtils::ReadFile(const std::string& path)
{
	HANDLE file = ::CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
	if (file == INVALID_HANDLE_VALUE)
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CREATE_FILE_HANDLE(path:%s)", path.c_str());
		return Result<std::vector<uint8_t>>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	DWORD fileSize = ::GetFileSize(file, nullptr);
	std::vector<uint8_t> buffer(fileSize);

	DWORD bytesRead;
	if (!::ReadFile(file, buffer.data(), fileSize, &bytesRead, nullptr))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_READ_FILE(path:%s)", path.c_str());
		return Result<std::vector<uint8_t>>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	if (!::CloseHandle(file))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CLOSE_FILE(path:%s)", path.c_str());
		return Result<std::vector<uint8_t>>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	return Result<std::vector<uint8_t>>::Success(buffer);
}

Result<std::vector<uint8_t>> FileUtils::ReadFile(const std::wstring& path)
{
	HANDLE file = ::CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
	if (file == INVALID_HANDLE_VALUE)
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CREATE_FILE_HANDLE(path:%s)", path.c_str());
		return Result<std::vector<uint8_t>>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	DWORD fileSize = ::GetFileSize(file, nullptr);
	std::vector<uint8_t> buffer(fileSize);

	DWORD bytesRead;
	if (!::ReadFile(file, buffer.data(), fileSize, &bytesRead, nullptr))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_READ_FILE(path:%s)", path.c_str());
		return Result<std::vector<uint8_t>>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	if (!::CloseHandle(file))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CLOSE_FILE(path:%s)", path.c_str());
		return Result<std::vector<uint8_t>>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	return Result<std::vector<uint8_t>>::Success(buffer);
}

Result<void> FileUtils::WriteFile(const std::string& path, const std::vector<uint8_t>& buffer)
{
	HANDLE file = ::CreateFileA(path.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (file == INVALID_HANDLE_VALUE)
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CREATE_FILE_HANDLE(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	DWORD writeByteSize = 0;
	if (!::WriteFile(file, buffer.data(), static_cast<DWORD>(buffer.size()), &writeByteSize, nullptr))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_WRITE_FILE(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	if (!::CloseHandle(file))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CLOSE_FILE(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	return Result<void>::Success();
}

Result<void> FileUtils::WriteFile(const std::wstring& path, const std::vector<uint8_t>& buffer)
{
	HANDLE file = ::CreateFileW(path.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (file == INVALID_HANDLE_VALUE)
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CREATE_FILE_HANDLE(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	DWORD writeByteSize = 0;
	if (!::WriteFile(file, buffer.data(), static_cast<DWORD>(buffer.size()), &writeByteSize, nullptr))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_WRITE_FILE(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	if (!::CloseHandle(file))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CLOSE_FILE(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	return Result<void>::Success();
}

Result<void> FileUtils::MakeDirectory(const std::string& path)
{
	if (!::CreateDirectoryA(path.c_str(), nullptr))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CREATE_DIRECTORY(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	return Result<void>::Success();
}

Result<void> FileUtils::MakeDirectory(const std::wstring& path)
{
	if (!::CreateDirectoryW(path.c_str(), nullptr))
	{
		std::string errMsg = StringUtils::PrintF("FAILED_TO_CREATE_DIRECTORY(path:%s)", path.c_str());
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::PLATFORM_API_FAILED, errMsg));
	}

	return Result<void>::Success();
}

bool FileUtils::IsValidPath(const std::string& path)
{
	return PathFileExistsA(path.c_str());
}

bool FileUtils::IsValidPath(const std::wstring& path)
{
	return PathFileExistsW(path.c_str());
}


std::string FileUtils::GetBasePath(const std::string& path)
{
	std::size_t lastSlash;

	if ((lastSlash = path.rfind('/')) != std::string::npos)
	{
		return path.substr(0, lastSlash + 1);
	}
	else if ((lastSlash = path.rfind('\\')) != std::string::npos)
	{
		return path.substr(0, lastSlash + 1);
	}
	else
	{
		return "";
	}
}

std::wstring FileUtils::GetBasePath(const std::wstring& path)
{
	std::size_t lastSlash;

	if ((lastSlash = path.rfind(L'/')) != std::wstring::npos)
	{
		return path.substr(0, lastSlash + 1);
	}
	else if ((lastSlash = path.rfind(L'\\')) != std::wstring::npos)
	{
		return path.substr(0, lastSlash + 1);
	}
	else
	{
		return L"";
	}
}

std::string FileUtils::RemoveBasePath(const std::string& path)
{
	std::size_t lastSlash;

	if ((lastSlash = path.rfind('/')) != std::string::npos)
	{
		return path.substr(lastSlash + 1, std::string::npos);
	}
	else if ((lastSlash = path.rfind('\\')) != std::string::npos)
	{
		return path.substr(lastSlash + 1, std::string::npos);
	}
	else
	{
		return path;
	}
}

std::wstring FileUtils::RemoveBasePath(const std::wstring& path)
{
	std::size_t lastSlash;

	if ((lastSlash = path.rfind(L'/')) != std::wstring::npos)
	{
		return path.substr(lastSlash + 1, std::wstring::npos);
	}
	else if ((lastSlash = path.rfind(L'\\')) != std::wstring::npos)
	{
		return path.substr(lastSlash + 1, std::wstring::npos);
	}
	else
	{
		return path;
	}
}

std::string FileUtils::GetFileExtension(const std::string& path)
{
	std::string filename = RemoveBasePath(path);
	std::size_t offset = filename.rfind('.');

	return (offset == std::string::npos) ? "" : filename.substr(offset + 1);
}

std::wstring FileUtils::GetFileExtension(const std::wstring& path)
{
	std::wstring filename = RemoveBasePath(path);
	std::size_t offset = filename.rfind('.');

	return (offset == std::wstring::npos) ? L"" : filename.substr(offset + 1);
}