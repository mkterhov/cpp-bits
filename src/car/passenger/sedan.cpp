#include <iostream>
#include "sedan.hpp"

void Sedan::printSummary() const
{
    Car::printSummary();
    std::cout << "Passengers:  " << m_passengers << " Tons" << "\n";
    std::cout << "Fuel consuption per 100km: " << m_fuelConsumption << "l" <<"\n";
}

float Sedan::getFuelConsumption() const
{
    return m_fuelConsumption;
}