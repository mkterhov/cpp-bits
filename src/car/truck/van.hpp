#pragma once

#include <string>
#include "truck.hpp"

class Van : public Truck
{
private:
    int m_passengerSeats = 0;
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
        const float& p_width,
        const int& p_range,
        const int& p_passengerSeats
    )
    :
    Truck(p_manufacturer, p_model, p_mileage, p_price, p_maxSpeed, p_year, p_maxLoad, p_height,  p_width, p_range),
    m_passengerSeats(p_passengerSeats)
    {
    }

    void printSummary() const;
};