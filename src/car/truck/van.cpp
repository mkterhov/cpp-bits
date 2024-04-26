#include <iostream>
#include "van.hpp"

void Van::printSummary() const
{
    Car::printSummary();
    std::cout << "Max load: " << m_maxLoad << " Tons" << "\n";
    std::cout << "Height: " << m_height << "m" <<"\n";
    std::cout << "Width: " << m_width << "m" << "\n";
}

bool Van::load(float weight)
{
    if(static_cast<float>(m_maxLoad) <  weight)
    {
        return false;
    }
    
    return true;
}