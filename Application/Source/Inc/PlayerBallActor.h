#pragma once

#include "Actor/IActor.h"

class PlayerBallActor : public IActor
{
public:
	PlayerBallActor();
	virtual ~PlayerBallActor();

	virtual void Release() override;
};