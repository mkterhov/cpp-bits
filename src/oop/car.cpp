#include <iostream>
#include <string>

class Car
{
private:
    std::string manufacturer;
    std::string model;
    std::string type;
    int horsepower = 0;
    int mileage = 0;
    int price = 0;
    int maxSpeed = 0;
    int accelaration = 0;
    int yearProduced = 0;

public:
    Car()
    {
    }

    Car(
        const std::string& p_manufacturer,
        const std::string& p_model,
        const std::string& p_type,
        const int& p_horsepower, 
        const int& p_mileage,
        const int& p_price,
        const int& p_maxSpeed,
        const int& p_acceleration,
        const int& p_yearProduced
    )
    :   manufacturer{p_manufacturer},
        model{p_model}, 
        type{p_type},
        horsepower{p_horsepower},
        mileage{p_mileage},
        price{p_price},
        maxSpeed{p_maxSpeed},
        accelaration{p_acceleration},
        yearProduced{p_yearProduced}
    {
    }    

    void setManufacturer(const std::string& p_manufacturer)
    {
        manufacturer = p_manufacturer;   
    }

    void setModel(const std::string& p_model)
    {
        model = p_model;   
    }

    void setType(const std::string& p_type)
    {
        type = p_type;   
    }

    void setPprice(const int& p_price)
    {
        price = p_price;
    }

    void setPhorsepower(const int& p_horsepower)
    {
        horsepower = p_horsepower;
    }

    void setMaxSpeed(const int& p_maxSpeed)
    {
        maxSpeed = p_maxSpeed;
    }

    void setAcceleration(const int& p_acceleration)
    {
        accelaration = p_acceleration;
    }

    void setMileage(const int& p_mileage)
    {
        mileage = p_mileage;
    }

    void setYearProduced(const int& p_yearProduced)
    {
        yearProduced = p_yearProduced;
    }

    std::string getManufacturer() const { return manufacturer; }
    std::string getModel() const { return model; }
    std::string getType() const { return type; }
    int getHorsepower() const { return horsepower; }
    int getMileage() const { return mileage; }
    int getPrice() const { return price; }
    int getMaxSpeed() const { return maxSpeed; }
    int getAccelaration() const { return accelaration; }
    int getYearProduced() const { return yearProduced; }

    void printCarSummary() const
    {
        std::cout << "--- Car summary ---\n";
        std::cout << "Manufacturer: " << manufacturer << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Type: " << type << "\n";
        std::cout << "Horsepower: " << horsepower << "\n";
        std::cout << "Max speed: " << maxSpeed << "\n";
        std::cout << "Accelaration: " << accelaration << "m/s \n";
        std::cout << "Mileage: " << mileage << " km\n";
        std::cout << "Price: $" << price << "\n";
    }
};

int main()
{
    Car car;

    car.printCarSummary();

    Car carSecond{"Toyota", "Camry", "Sedan", 130, 23000, 1600000, 150, 10, 2015};

    carSecond.printCarSummary();

    return 0;
}
