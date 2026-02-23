#include "AppContext.h"

AppContext::AppContext(ActorManager* actorMgr, InputManager* inputMgr)
	: _actorMgr(actorMgr)
	, _inputMgr(inputMgr)
{
}

AppContext::~AppContext()
{
	_actorMgr = nullptr;
	_inputMgr = nullptr;
}