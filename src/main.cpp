#include <iostream>
#include <string>

#include "car/car.hpp"
#include "car/van.hpp"
#include "car/sedan.hpp"
#include "car/truck.hpp"

int main()
{
    Car car1{
        "Aston Martin",
        "DB5",
        10000,
        160000,
        233,
        1964
    };
    car1.printSummary();
    Van van{
        "Ford",
        "Transit",
        120000,
        12300,
        100,
        2010,
        2,
        2.5,
        4
    };
    van.printSummary();

    Truck truck{
        "Ford",
        "Transit",
        120000,
        12300,
        100,
        2010,
        2,
        2.5,
        4,
        300
    };
    truck.printSummary();
    truck.attachTrailer(2);
    truck.printSummary();
}