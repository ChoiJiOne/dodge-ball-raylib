#pragma once

#include <string>
#include <iostream>
#include <vector>

#include <msgpack.hpp>

class DataChunkUtils
{
public:
	template <typename TDataChunk>
	static bool TrySaveDataChunk(const std::string& filePath, TDataChunk dataChunk)
	{
		msgpack::sbuffer sbuffer;
		msgpack::pack(sbuffer, dataChunk);

		std::ofstream ofs(filePath, std::ios::binary);
		if (!ofs.is_open())
		{
			std::cout << "Failed to save data chunk file to path: '" << filePath << "'" << std::endl;
			return false;
		}

		ofs.write(sbuffer.data(), sbuffer.size());
		ofs.close();

		std::cout << "Successfully saved data chunk file to path: '" << filePath << "'" << std::endl;
		return true;
	}
};