#pragma once

#include "Actor/IActorController.h"

class PlayerBallController : public IActorController
{
public:
	PlayerBallController();
	virtual ~PlayerBallController();

	DISALLOW_COPY_AND_ASSIGN(PlayerBallController);

	virtual void Release() override;
	virtual void Tick(float deltaSeconds) override;

private:

};