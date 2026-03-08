#pragma once

#include "Macro/Macro.h"

class IActorModel
{
public:
	IActorModel() = default;
	virtual ~IActorModel() = default;

	DISALLOW_COPY_AND_ASSIGN(IActorModel);
};