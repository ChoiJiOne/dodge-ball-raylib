#pragma once

#include "Config/IConfig.h"
#include "Manager/IManager.h"

class ConfigManager : public IManager<ConfigManager>
{
public:
	DISALLOW_COPY_AND_ASSIGN(ConfigManager);

	virtual Result<void> Startup() override;
	virtual Result<void> Shutdown() override;

private:
	bool LoadConfigFromFile(const std::string& filePath, IConfig& outConfig);

private:
	friend class IManager<ConfigManager>;

	ConfigManager() = default;
	virtual ~ConfigManager() = default;

private:
	
};