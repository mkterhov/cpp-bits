#include <iostream>
#include "machinery.hpp"

void Machinery::printSummary() const
{

    Car::printSummary();
    std::cout << "Machinery type: " << m_type << "m" << "\n";
}