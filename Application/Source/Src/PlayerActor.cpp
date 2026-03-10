#include "BallModel.h"
#include "PlayerActor.h"
#include "PlayerActorController.h"

PlayerActor::PlayerActor()
{
	AddModel<BallModel>();
	AddController<PlayerActorController>();

	_isInitialized = true;
}

PlayerActor::~PlayerActor()
{
	if (_isInitialized)
	{
		Release();
	}
}

void PlayerActor::Release()
{
	IActor::Release();

	_isInitialized = false;
}
