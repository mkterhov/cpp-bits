#include <iostream>
#include "car.hpp"

void Car::printSummary() const
{
    std::cout << "--- Car summary ---\n";
    std::cout << "Manufacturer: " << m_manufacturer << "\n";
    std::cout << "Model: " << m_model << "\n";
    std::cout << "Max speed: " << m_maxSpeed << "\n";
    std::cout << "Mileage: " << m_mileage << " km\n";
    std::cout << "Price: $" << m_price << "\n";
    std::cout << "Year: " << m_year << "\n";
}
