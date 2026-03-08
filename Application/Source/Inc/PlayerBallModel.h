#pragma once

#include "Actor/IActorModel.h"

class PlayerBallModel : public IActorModel
{
public:
	PlayerBallModel();
	virtual ~PlayerBallModel();

	DISALLOW_COPY_AND_ASSIGN(PlayerBallModel);
};