#pragma once

#include <functional>

#include "Manager/ActorManager.h"
#include "Manager/ConfigManager.h"
#include "Manager/DataChunkManager.h"
#include "Manager/InputManager.h"
#include "Manager/RenderManager.h"

class AppContext
{
public:
	AppContext(
		ActorManager* actorMgr,
		ConfigManager* configMgr,
		DataChunkManager* dataChunkMgr,
		InputManager* inputMgr,
		RenderManager* renderMgr
	);
	virtual ~AppContext();

	DISALLOW_COPY_AND_ASSIGN(AppContext);

	void SetRequestQuit(const std::function<void()>& requestQuit) { _requestQuit = requestQuit; }
	void RequestQuit() const
	{
		if (_requestQuit)
			_requestQuit();
	}

	ActorManager* GetActorManager() const { return _actorMgr; }
	ConfigManager* GetConfigManager() const { return _configMgr; }
	DataChunkManager* GetDataChunkManager() const { return _dataChunkMgr; }
	InputManager* GetInputManager() const { return _inputMgr; }
	RenderManager* GetRenderManager() const { return _renderMgr; }

private:
	ActorManager* _actorMgr = nullptr;
	ConfigManager* _configMgr = nullptr;
	DataChunkManager* _dataChunkMgr = nullptr;
	InputManager* _inputMgr = nullptr;
	RenderManager* _renderMgr = nullptr;

	std::function<void()> _requestQuit;
};