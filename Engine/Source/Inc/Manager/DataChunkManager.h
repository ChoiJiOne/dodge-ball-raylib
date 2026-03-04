#pragma once

#include "Manager/IManager.h"

class DataChunkManager : public IManager<DataChunkManager>
{
public:
	DISALLOW_COPY_AND_ASSIGN(DataChunkManager);

	virtual Result<void> Startup() override;
	virtual Result<void> Shutdown() override;

private:
	friend class IManager<DataChunkManager>;

	DataChunkManager() = default;
	virtual ~DataChunkManager() = default;
};