#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include <msgpack.hpp>

struct BallDataPack
{
    int32_t Num;
    int32_t Speed;
    int32_t Size;
    std::vector<float> Color;

    MSGPACK_DEFINE(Num, Speed, Size, Color);
};
