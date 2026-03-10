#include "BallModel.h"
#include "PlayerActor.h"
#include "PlayerBallController.h"

PlayerActor::PlayerActor()
{
	AddModel<BallModel>();
	AddController<PlayerBallController>();

	_isInitialized = true;
}

PlayerActor::~PlayerActor()
{
	if (_isInitialized)
		Release();
}

void PlayerActor::Release()
{
	IActor::Release();

	_isInitialized = false;
}
