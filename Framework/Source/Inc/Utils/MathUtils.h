#pragma once

#include <glm/glm.hpp>
#include <raylib.h>

class MathUtils
{
public:
	static inline Vector2 ToVector2(const glm::vec2& v)
	{
		return Vector2{ v.x, v.y };
	}

	static inline Vector3 ToVector3(const glm::vec3& v)
	{
		return Vector3{ v.x, v.y, v.z };
	}

	static inline Vector4 ToVector4(const glm::vec4& v)
	{
		return Vector4{ v.x, v.y, v.z, v.w };
	}
	
	static Color ToColor8Bit(const glm::vec4& colorVec)
	{
		return Color{
			static_cast<unsigned char>(colorVec.r * 255.0f),
			static_cast<unsigned char>(colorVec.g * 255.0f),
			static_cast<unsigned char>(colorVec.b * 255.0f),
			static_cast<unsigned char>(colorVec.a * 255.0f)
		};
	}

	static int32_t GenerateRandomInt(int32_t minValue, int32_t maxValue); // [minValue, maxValue]
	static float GenerateRandomFloat(float minValue, float maxValue); // [minValue, maxValue)
};