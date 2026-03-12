#include "EnemyActor.h"
#include "EnemySpawnActor.h"
#include "GameScene.h"
#include "PlayerActor.h"

Result<void> GameScene::OnEnter()
{
	if (Result<void> result = CreateAndAddActor<PlayerActor>("Player"); !result.IsSuccess())
	{
		return result;
	}

	if (Result<void> result = CreateAndAddActor<EnemySpawnActor>("EnemySpawnActor"); !result.IsSuccess())
	{
		return result;
	}

	return Result<void>::Success();
}

Result<void> GameScene::OnExit()
{
	ClearActorMap();

	return Result<void>::Success();
}