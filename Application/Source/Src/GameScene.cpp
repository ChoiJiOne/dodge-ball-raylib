// Application
#include "EnemyActor.h"
#include "GameScene.h"
#include "PlayerActor.h"

Result<void> GameScene::OnEnter()
{
	if (Result<void> result = CreateAndAddActor<PlayerActor>("Player"); !result.IsSuccess())
	{
		return result;
	}

	if (Result<void> result = CreateAndAddActor<EnemyActor>("Enemy"); !result.IsSuccess())
	{
		return Result<void>::Fail(result.GetError());
	}

	return Result<void>::Success();
}

Result<void> GameScene::OnExit()
{
	const auto& sceneActorMap = GetSceneActorMap();
	for (const auto& [key, sceneActor] : sceneActorMap)
	{
		DestroyActor(key);
	}

	return Result<void>::Success();
}