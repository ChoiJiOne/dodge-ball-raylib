#pragma once
#include <csv.hpp>

#include "BallDataPack.generated.h"
#include "DataPackUtils.h"

inline std::vector<BallDataPack> GenerateBallDataPacks(const std::string& filePath)
{
    csv::CSVReader reader(filePath);
    std::vector<BallDataPack> dataPacks;
    bool isTypeDefineRow = true;
    for (csv::CSVRow& row : reader)
    {
        if (isTypeDefineRow)
        {
            isTypeDefineRow = false;
            continue;
        }
        
        BallDataPack dataPack;
        dataPack.Num = row[0].get<int32_t>();
        dataPack.Speed = row[1].get<int32_t>();
        dataPack.Size = row[2].get<int32_t>();
        dataPack.Color = DataPackUtils::ParseFloatArray(row[3].get<std::string>());

        dataPacks.push_back(dataPack);
    }
    return dataPacks;
}