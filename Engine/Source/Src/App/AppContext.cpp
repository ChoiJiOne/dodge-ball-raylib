#include "App/AppContext.h"

AppContext::AppContext(
	ActorManager* actorMgr,
	ConfigManager* configMgr,
	DataChunkManager* dataChunkMgr,
	InputManager* inputMgr,
	RenderManager* renderMgr
) : _actorMgr(actorMgr),
	_configMgr(configMgr),
	_dataChunkMgr(dataChunkMgr),
	_inputMgr(inputMgr),
	_renderMgr(renderMgr)
{
}

AppContext::~AppContext()
{
	_actorMgr = nullptr;
	_configMgr = nullptr;
	_dataChunkMgr = nullptr;
	_inputMgr = nullptr;
	_renderMgr = nullptr;
}