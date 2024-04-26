#pragma once

#include <string>
#include "car.hpp"

class Van : public Car
{
private:
    int m_maxLoad;
    float m_height;
    float m_width;
public:
    Van(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const int& p_maxLoad,
        const float& p_height,
        const float& p_width
    )
    :
    Car(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year),
    m_maxLoad(p_maxLoad),
    m_height(p_height),
    m_width(p_width)
    {
    }

    void printSummary() const;
    bool load(float weight);
};