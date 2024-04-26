#pragma once

#include <string>
#include <array>
#include "machinery.hpp"

class Excavator : public Machinery
{
private:
    std::string m_bucket;
public:
    static const std::array<std::string, 4> m_bucketTypes;
    
    Excavator(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const int& p_maxLoad,
        const float& p_height,
        const float& p_width,
        const std::string& p_type,
        const std::string& p_bucket
    )
    :
    Machinery(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year, p_type),
    m_bucket(p_bucket)
    {
    }

    void printSummary() const;
    bool changeBucketType(std::string p_bucketType);
};