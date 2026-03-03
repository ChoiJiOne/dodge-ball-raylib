#pragma once

#include "BallDataPack.generated.h"

struct BallDataChunk
{
	std::vector<BallDataPack> DataPacks;

	MSGPACK_DEFINE(DataPacks);
};