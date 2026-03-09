#include "PlayerBallModel.h"

PlayerBallModel::PlayerBallModel()
{
	_position = glm::vec2(400.0f, 300.0f);
	_radius = 30.0f;
	_color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
}

PlayerBallModel::~PlayerBallModel()
{

}
