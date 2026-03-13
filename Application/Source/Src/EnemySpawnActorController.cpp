#include "BallDataChunk.h"

#include "Actor/IActor.h"
#include "Utils/LogUtils.h"
#include "Macro/Macro.h"
#include "Manager/DataChunkManager.h"
#include "Manager/SceneManager.h"
#include "Scene/IScene.h"

#include "EnemyActor.h"
#include "EnemySpawnActorController.h"
#include "EnemySpawnActorModel.h"

void EnemySpawnActorController::OnInitialize(IActor* owner)
{
	IActorController::OnInitialize(owner);

	if (Result<EnemySpawnActorModel*> result = _ownerActor->GetModel<EnemySpawnActorModel>();  !result.IsSuccess())
	{
		LOG_E("FAILED_TO_GET_ENEMY_SPAWN_MODEL");
		return;
	}
	else
	{
		_model = result.GetValue();
	}
	
	DataChunkManager& dataChunkMgr = DataChunkManager::Get();
	if (Result<const BallDataChunk*> result = dataChunkMgr.GetDataChunk<BallDataChunk>(); !result.IsSuccess())
	{
		LOG_E("FAILED_TO_GET_BALL_DATA_PACK");
		return;
	}
	else
	{
		const BallDataChunk* dataChunk = result.GetValue();
		for (auto& [num, idx] : dataChunk->NumToIdx)
		{

		}
	}

	_leftBoundPosition = glm::vec2(0.0f, -50.0f);
	_rightBoundPosition = glm::vec2(600.0f, -50.0f);
}

void EnemySpawnActorController::OnRelease()
{
	_model = nullptr;
}

void EnemySpawnActorController::OnTick(float deltaSeconds)
{
	_timeSinceLastSpawn += deltaSeconds;
	if (_timeSinceLastSpawn < _spawnTime) 
	{
		return;
	}

	SpawnEnemyActor();
}

void EnemySpawnActorController::SpawnEnemyActor()
{
	SceneManager& sceneMgr = SceneManager::Get();
	IScene* currentScene = sceneMgr.GetCurrentScene();

	std::string key = std::format("EnemyActor_{0}", _spawnedCount);
	Result<void> result = currentScene->CreateAndAddActor<EnemyActor>(std::format("EnemyActor_{0}", _spawnedCount));
	if (!result.IsSuccess())
	{
		LOG_E("FAILED_TO_CREATE_AND_ADD_ENEMY_ACTOR:(count:{0})", _spawnedCount);
		return;
	}

	_enemyActorKeyMap.emplace(key, _spawnedCount);
	_spawnedCount++;
	_timeSinceLastSpawn = 0.0f;
}
