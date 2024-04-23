#include <iostream>
#include <string>

class Body {
private:
    std::string m_class;
    std::string m_style;
    std::string m_color;

public:
    Body(const std::string& p_class, const std::string& p_style, const std::string& p_color)
        : m_class(p_class), m_style(p_style), m_color(p_color) {}
};

class Engine {
private:
    std::string m_type;
    std::string m_manufacturer;
    int m_power = 0;

public:
    Engine(const std::string& p_type, const std::string& p_manufacturer, int p_power)
        : m_type(p_type), m_manufacturer(p_manufacturer), m_power(p_power) {}
};

class Transmission {
private:
    std::string m_type;
    int m_speed = 0;

public:
    Transmission(const std::string& p_type, int p_speed)
        : m_type(p_type), m_speed(p_speed) {}
};

class Car
{
private:
    std::string m_manufacturer;
    std::string m_model;
    int m_mileage = 0;
    int m_price = 0;
    int m_maxSpeed = 0;
    int m_year = 0;
    Body m_body;
    Engine m_engine;
    Transmission m_transmission;

public:
    Car(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_year,
        const std::string& p_bodyClass,
        const std::string& p_bodyStyle,
        const std::string& p_bodyColor,
        const std::string& p_engineType,
        const std::string& p_engineManufacturer,
        const int& p_enginePower,
        const std::string& p_transmissionType,
        const int& p_transmissionSpeed
    )
        : m_manufacturer(p_manufacturer),
        m_model(p_model),
        m_mileage(p_mileage),
        m_price(p_price),
        m_maxSpeed(p_maxSpeed),
        m_year(p_year),
        m_body(p_bodyClass, p_bodyStyle, p_bodyColor),
        m_engine(p_engineType, p_engineManufacturer, p_enginePower),
        m_transmission(p_transmissionType, p_transmissionSpeed)
    {}


    void setManufacturer(const std::string& p_manufacturer)
    {
        m_manufacturer = p_manufacturer;
    }

    void setModel(const std::string& p_model)
    {
        m_model = p_model;
    }

    void setPprice(const int& p_price)
    {
        m_price = p_price;
    }

    void setMaxSpeed(const int& p_maxSpeed)
    {
        m_maxSpeed = p_maxSpeed;
    }

    void setMileage(const int& p_mileage)
    {
        m_mileage = p_mileage;
    }

    void setYearProduced(const int& p_yearProduced)
    {
        m_year = p_yearProduced;
    }

    std::string getManufacturer() const { return m_manufacturer; }
    std::string getModel() const { return m_model; }
    int getMileage() const { return m_mileage; }
    int getPrice() const { return m_price; }
    int getMaxSpeed() const { return m_maxSpeed; }
    int getYearProduced() const { return m_year; }

    void printCarSummary() const
    {
        std::cout << "--- Car summary ---\n";
        std::cout << "Manufacturer: " << m_manufacturer << "\n";
        std::cout << "Model: " << m_model << "\n";
        std::cout << "Max speed: " << m_maxSpeed << "\n";
        std::cout << "Mileage: " << m_mileage << " km\n";
        std::cout << "Price: $" << m_price << "\n";
        std::cout << "Year: " << m_year << "\n";
    }
};

int main()
{
    Car car{
        "Aston Martin",
        "DB5", 
        10000,
        160000,
        233,
        1964,
        "Grand tourer",
        "Coupe",
        "Silver",
        "Straight-6",
        "Aston Martin",
        282,
        "Manual",
        5
    };

    car.printCarSummary();

    return 0;
}
