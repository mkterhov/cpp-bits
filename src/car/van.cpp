#include <iostream>
#include "van.hpp"

void Van::printSummary() const
{
    Car::printSummary();
    std::cout << "Max load: " << m_maxLoad << " Tons" << "\n";
    std::cout << "Height: " << m_height << "m" <<"\n";
    std::cout << "Width: " << m_width << "m" << "\n";
}