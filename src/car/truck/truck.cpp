#include <string>
#include "truck.hpp"

bool Truck::attachTrailer(const int& p_trailerId)
{
    if (m_trailerId != 0) {
        return false;
    }
    
    m_trailerId = p_trailerId;

    return true;
}

bool Truck::load(const float& p_weight)
{
    if(static_cast<float>(m_maxLoad) <  p_weight)
    {
        return false;
    }
    
    return true;
}

bool Truck::unload()
{
    if(m_maxLoad > 0)
    {
        m_maxLoad = 0;
        return true;
    }
    
    return false;
}

void Truck::printSummary() const
{

     auto trailerCheck = [](int trailer) -> std::string  {
        if (trailer == 0) {
            return "Trailer: no trailer attached";
        }
        return "Trailer id: " + std::to_string(trailer);
    };

    Car::printSummary();
    std::cout << "Max load: " << m_maxLoad << " Tons" << "\n";
    std::cout << "Height: " << m_height << "m" <<"\n";
    std::cout << "Width: " << m_width << "m" << "\n";
    std::cout << "Range: " << m_range << "m" << "\n";
    std::cout << trailerCheck(m_trailerId) << "\n";

}