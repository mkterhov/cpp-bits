#pragma once

#include <iostream>
#include <string>

class Car
{
private:
    std::string m_manufacturer;
    std::string m_model;
    int m_mileage = 0;
    int m_price = 0;
    int m_maxSpeed = 0;
    int m_year = 0;
public:
    Car(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year
    )
        : m_manufacturer(p_manufacturer),
        m_model(p_model),
        m_mileage(p_mileage),
        m_price(p_price),
        m_maxSpeed(p_maxSpeed),
        m_year(p_year)
    {}

    void printSummary() const;
};
