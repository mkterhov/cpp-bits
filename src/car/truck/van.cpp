#include <iostream>
#include "van.hpp"

void Van::printSummary() const
{
    Truck::printSummary();
    std::cout << "Passenger seats: " << m_passengerSeats << " Tons" << "\n";
}