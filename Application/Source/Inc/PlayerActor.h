#pragma once

#include "Actor/IActor.h"

class PlayerActor : public IActor
{
public:
	PlayerActor();
	virtual ~PlayerActor();

	virtual void Release() override;
};