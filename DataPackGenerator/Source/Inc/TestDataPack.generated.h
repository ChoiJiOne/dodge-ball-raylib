#pragma once

#include <cstdint>
#include <vector>
#include <string>

struct TestDataPack
{
    int32_t A;
    float B;
    std::string C;
    bool D;
    std::vector<int32_t> E;

    MSGPACK_DEFINE(A, B, C, D, E);
};
