#pragma once

#include "Macro/Macro.h"

class IActor;

class IActorController
{
public:
	IActorController() = default;
	virtual ~IActorController() = default;

	DISALLOW_COPY_AND_ASSIGN(IActorController);

	virtual void Release() = 0;
	virtual void Tick(float deltaSeconds) = 0;

	void SetOwnerActor(IActor* owner)
	{
		_ownerActor = owner;
	}

protected:
	IActor* _ownerActor = nullptr;
};