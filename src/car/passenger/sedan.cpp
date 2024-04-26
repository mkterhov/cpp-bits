#include <iostream>
#include "sedan.hpp"

void Sedan::printSummary() const
{
    PassengerCar::printSummary();
    std::cout << "Style:  " << m_style <<  "\n";
}
