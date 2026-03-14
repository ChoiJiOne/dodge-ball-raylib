#pragma once

#include <glm/glm.hpp>

#include "Actor/IActorController.h"

class BallModel;
class EnemySpawnActorModel;

class EnemySpawnActorController : public IActorController
{
public:
	EnemySpawnActorController() = default;
	virtual ~EnemySpawnActorController() = default;

	DISALLOW_COPY_AND_ASSIGN(EnemySpawnActorController);

	virtual void OnInitialize(IActor* owner) override;
	virtual void OnRelease() override;
	virtual void OnTick(float deltaSeconds) override;

private:
	void SpawnEnemyActor();
	void SetBallModel(BallModel* model);

private:
	EnemySpawnActorModel* _model = nullptr;

	std::map<std::string, int32_t> _enemyActorKeyMap;

	float _spawnTime = 1.0f;
	float _timeSinceLastSpawn = 0.0f;
	int32_t _spawnedCount = 0;

	float _minXPosition;
	float _maxXPosition;
	float _yPosition;
};