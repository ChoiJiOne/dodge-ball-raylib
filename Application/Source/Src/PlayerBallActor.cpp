#include "PlayerBallActor.h"

PlayerBallActor::PlayerBallActor()
{
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
