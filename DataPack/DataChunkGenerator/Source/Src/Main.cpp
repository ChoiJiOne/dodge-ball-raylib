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

	BallDataChunk dataChunk;
	dataChunk.DataPacks = GenerateBallDataPacks(std::format("CSV/{0}.csv", dataName));

	if (DataChunkUtils::TrySaveDataChunk(std::format("Resource/{0}.bytes", dataName), dataChunk))
	{
		return;
	}
}

void GeneratePlayerDataChunk()
{
	std::string dataName = "Player";

	PlayerDataChunk dataChunk;
	dataChunk.DataPacks = GeneratePlayerDataPacks(std::format("CSV/{0}.csv", dataName));

	if (DataChunkUtils::TrySaveDataChunk(std::format("Resource/{0}.bytes", dataName), dataChunk))
	{
		return;
	}
}

int main(int argc, char* argv[])
{
	GenerateBallDataChunk();
	GeneratePlayerDataChunk();
	return 0;
}