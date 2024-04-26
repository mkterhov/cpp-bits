#pragma once

#include <string>
#include "car.hpp"

class PassengerCar : public Car
{
private:
    int m_passengers;
    float m_fuelConsumption;
public:
    PassengerCar(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const int& p_passengers,
        const float& p_fuelConsumption
    )
    :
    Car(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year),
    m_passengers(p_passengers),
    m_fuelConsumption(p_fuelConsumption)
    {
    }

    void printSummary() const;
    float getFuelConsumption() const;
};