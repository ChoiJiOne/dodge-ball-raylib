#pragma once

#include <glm/glm.hpp>

#include "Actor/IActorController.h"

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

private:
	EnemySpawnActorModel* _model = nullptr;

	std::map<std::string, int32_t> _enemyActorKeyMap;

	float _spawnTime = 2.0f;
	float _timeSinceLastSpawn = 0.0f;
	int32_t _spawnedCount = 0;

	glm::vec2 _leftBoundPosition;
	glm::vec2 _rightBoundPosition;
};