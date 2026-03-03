#include <format>
#include <iostream>

#include "DataChunkUtils.h"
#include "DataPackUtils.h"

#include "BallDataChunk.h"
#include "PlayerDataChunk.h"

#include "BallDataPackParser.generated.h"
#include "PlayerDataPackParser.generated.h"

void GenerateBallDataChunk()
{
	std::string dataName = "Ball";
	std::cout << std::format("[{0}] Generating data chunk...", dataName) << std::endl;

	BallDataChunk dataChunk;
	dataChunk.DataPacks = GenerateBallDataPacks(std::format("CSV/{0}.csv", dataName));

	if (!DataChunkUtils::TrySaveDataChunk(std::format("Resource/{0}.bytes", dataName), dataChunk))
	{
		std::cout << std::format("[{0}] Error: Failed to generate data chunk!", dataName) << std::endl;
		return;
	}

	std::cout << std::format("[{0}] Successfully generated data chunk.", dataName) << std::endl;
}

void GeneratePlayerDataChunk()
{
	std::string dataName = "Player";
	std::cout << std::format("[{0}] Generating data chunk...", dataName) << std::endl;

	PlayerDataChunk dataChunk;
	dataChunk.DataPacks = GeneratePlayerDataPacks(std::format("CSV/{0}.csv", dataName));

	if (!DataChunkUtils::TrySaveDataChunk(std::format("Resource/{0}.bytes", dataName), dataChunk))
	{
		std::cout << std::format("[{0}] Error: Failed to generate data chunk!", dataName) << std::endl;
		return;
	}

	std::cout << std::format("[{0}] Successfully generated data chunk.", dataName) << std::endl;
}

int main(int argc, char* argv[])
{
	std::cout << "--- Start Data Chunk Generation ---" << std::endl;
	GenerateBallDataChunk();
	GeneratePlayerDataChunk();
	// NOTE: 여기 아래에 계속해서 추가.
	std::cout << "--- Data Chunk Generation Finished ---" << std::endl;
	return 0;
}