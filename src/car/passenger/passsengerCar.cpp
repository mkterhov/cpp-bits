#include <iostream>
#include "passsengerCar.hpp"

void PassengerCar::printSummary() const
{
    Car::printSummary();
    std::cout << "Passengers:  " << m_passengers << " Tons" << "\n";
    std::cout << "Fuel consuption per 100km: " << m_fuelConsumption << "l" <<"\n";
}

float PassengerCar::getFuelConsumption() const
{
    return m_fuelConsumption;
}