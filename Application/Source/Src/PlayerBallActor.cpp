#include "PlayerBallActor.h"
#include "PlayerBallController.h"
#include "PlayerBallModel.h"

PlayerBallActor::PlayerBallActor()
{
	AddModel<PlayerBallModel>();
	AddController<PlayerBallController>();

	_isInitialized = true;
}

PlayerBallActor::~PlayerBallActor()
{
	if (_isInitialized)
		Release();
}

void PlayerBallActor::Release()
{
	IActor::Release();

	_isInitialized = false;
}
