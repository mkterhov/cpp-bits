#pragma once

#include <string>
#include "car.hpp"

class Machinery : public Car
{
private:
    std::string m_type;
public:
    Machinery(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const std::string& p_type
    )
    :
    Car(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year),
    m_type(p_type)
    {
    }

    void printSummary() const;
};