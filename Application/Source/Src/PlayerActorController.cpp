#include "Actor/IActor.h"
#include "Manager/InputManager.h"
#include "Utils/LogUtils.h"
#include "Macro/Macro.h"

#include "BallModel.h"
#include "PlayerActorController.h"

void PlayerActorController::OnInitialize(IActor* owner)
{
	IActorController::OnInitialize(owner);

	_inputMgr = InputManager::GetPtr();

	Result<BallModel*> result = _ownerActor->GetModel<BallModel>();
	if (!result.IsSuccess()) // Get이 실패할 수 있을까...?
	{
		LOG_E("FAILED_TO_GET_PLAYER_BALL_MODEL"); // 일단 로그를 찍어보자.
	}
	else
	{
		_model = result.GetValue();
	}

	_boundDistance = 500.0f;
	_leftBoundPosition = _model->GetPosition();
	_rightBoundPosition = _model->GetPosition();

	_leftBoundPosition.x -= _boundDistance * 0.5f;
	_rightBoundPosition.x += _boundDistance * 0.5f;

	_model->SetMoveDirection(glm::vec2(1.0f, 0.0f));
}

void PlayerActorController::OnRelease()
{
	_inputMgr = nullptr;
	_model = nullptr;
}

void PlayerActorController::OnTick(float deltaSeconds)
{
	glm::vec2 position = _model->GetPosition();
	glm::vec2 direction = _model->GetMoveDirection();
	float speed = _model->GetMoveSpeed();

	position += direction * deltaSeconds * speed;
	position = glm::clamp(position, _leftBoundPosition, _rightBoundPosition);

	_model->SetPosition(position);

	if (position.x <= _leftBoundPosition.x)
	{
		if (direction.x < 0.0f)
		{
			direction.x *= -1.0f;
			_model->SetMoveDirection(direction);
		}
	}
	else if (position.x >= _rightBoundPosition.x)
	{
		if (direction.x > 0.0f)
		{
			direction.x *= -1.0f;
			_model->SetMoveDirection(direction);
		}
	}
}
