#pragma once

#include <string>
#include "../../car/car.hpp"

class Truck : public Car
{
private:
    int m_maxLoad = 0;
    float m_height = .0f;
    float m_width = .0f;
    int m_range = 0;
    int m_trailerId = 0;
public:
    Truck(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const int& p_maxLoad,
        const float& p_height,
        const float& p_width,
        const int& p_range
    )
    :
    Car(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year),
    m_maxLoad(p_maxLoad),
    m_height(p_height),
    m_width(p_width),
    m_range(p_range)
    {
    }

    void printSummary() const;
    bool load(const float& p_weight);
    bool attachTrailer(const int& p_trailerId);
    bool unload();
};