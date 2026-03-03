#pragma once

#include "PlayerDataPack.generated.h"

struct PlayerDataChunk
{
	std::vector<PlayerDataPack> DataPacks;

	MSGPACK_DEFINE(DataPacks);
};