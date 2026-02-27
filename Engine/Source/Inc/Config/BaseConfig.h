#pragma once

#include "Config/IConfig.h"

class BaseConfig : public IConfig
{
public:



private:
	int32_t _windowWidth = 800;
	int32_t _windowHeight = 600;
	std::string _windowTitle;
	int32_t _targetFPS = 60;
};