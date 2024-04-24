#include <iostream>
#include <string>

class Parking;

class Car
{
private:
    std::string m_manufacturer;
    std::string m_model;
    int m_mileage = 0;
    int m_price = 0;
    int m_maxSpeed = 0;
    int m_year = 0;
    Parking* m_parking = nullptr;
public:
    Car()
    {

    }
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
    void setParking(Parking* parking);
    bool isParked() const;

    ~Car()
    {
        this->m_parking = nullptr;
    }
};

class Parking
{
private:
    int m_occupied = 0;
    int m_capacity = 0;
    Car** cars = nullptr;
public:
    Parking(const int& capacity) : m_capacity{capacity}
    {
        this->cars = new Car * [this->m_capacity];
    }

    Parking& operator=(const Parking& obj) = delete;

    Parking(const Parking& obj) = delete;

    ~Parking()
    {
        m_occupied = 0;
        m_capacity = 0;

        delete[] cars;
        cars = nullptr;
    }

    bool registerCar(Car* car);
    bool removeCar(Car* car);
    void printCars() const;
};

bool Car::isParked() const
{
    return m_parking != nullptr;
}

void Car::setParking(Parking* parking)
{
    m_parking = parking;
}

void Car::printSummary() const
{
    std::cout << "--- Car summary ---\n";
    std::cout << "Manufacturer: " << m_manufacturer << "\n";
    std::cout << "Model: " << m_model << "\n";
    std::cout << "Max speed: " << m_maxSpeed << "\n";
    std::cout << "Mileage: " << m_mileage << " km\n";
    std::cout << "Price: $" << m_price << "\n";
    std::cout << "Year: " << m_year << "\n";
    std::cout << "-----------------------\n";
}

bool Parking::registerCar(Car* car)
{
    bool res = false;
    if (this->m_occupied < m_capacity && !car->isParked())
    {
        car->setParking(this);
        this->cars[this->m_occupied] = car;
        this->m_occupied++;
        res = true;
    }

    return res;
}

bool Parking::removeCar(Car* car)
{
    bool res = false;
    int carIndex = -1;
    for (int i = 0; i < m_occupied; i++) {
        if (car == this->cars[i])
        {
            carIndex = i;
        }
    }

    if (carIndex != -1) {

        this->cars[carIndex]->setParking(nullptr);

        for (int i = carIndex; i < m_occupied - 1; i++) {
            cars[i] = cars[i + 1];
        }

        m_occupied--;
        cars[m_occupied] = nullptr;

        res = true;
    }

    return res;
}

void Parking::printCars() const
{
    std::cout << "--- Parked cars | " << this->m_occupied << " / " << this->m_capacity <<" -- - \n";

    for (int i = 0; i < m_occupied; i++) {
        this->cars[i]->printSummary();
    }
    
    std::cout << "--- Parked cars | " << this->m_occupied << " / " << this->m_capacity <<" -- - \n";

}

void attemptPark(Car* car, Parking* parking)
{
    if (parking->registerCar(car)) {
        std::cout << "Car parked successfully." << std::endl;
    }

    else {
        std::cout << "Failed to park car." << std::endl;
    }
}

int main()
{
    int testNr = 10;
    Parking parking(testNr);

    Car car1{
        "Aston Martin",
        "DB5",
        10000,
        160000,
        233,
        1964
    };

    Car car2{
        "Ford",
        "Mustang",
        10000,
        100000,
        355,
        1967
    };

    Car car3{
        "Dodge",
        "Challenger",
        23000,
        58000,
        290,
        1970
    };

    attemptPark(&car1, &parking);
    attemptPark(&car2, &parking);
    attemptPark(&car3, &parking);

    Car** arr = new Car*[testNr];

    for (int i = 0; i < testNr; i++)
    {
        Car* car = new Car(
            "Dodge" + std::to_string(i),
            "Challenger " + std::to_string(i),
            23000 + i,
            58000 + i,
            200 + (i * 10),
            1970 + i
        );
        arr[i] = car;
        attemptPark(car, &parking);
    }
    parking.removeCar(&car1);
    parking.removeCar(&car2);
    parking.removeCar(&car3);

    parking.printCars();

    for (int i = 0; i < testNr; i++)
    {
        delete arr[i];
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
