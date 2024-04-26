#pragma once

#include <string>
#include "passsengerCar.hpp"

class Sedan : public PassengerCar
{
private:
    std::string  m_style;
public:
    Sedan(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const int& p_passengers,
        const float& p_fuelConsumption,
        const std::string& p_style
    )
    :
    PassengerCar(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year, p_passengers, p_fuelConsumption),
    m_style(p_style)
    {
    }

    void printSummary() const;
};