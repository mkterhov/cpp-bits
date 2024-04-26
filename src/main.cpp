#include <iostream>
#include <string>

#include "car/truck/van.hpp"
#include "car/passenger/sedan.hpp"
#include "car/machinery/excavator.hpp"

int main()
{
    Van van{
        "Ford",
        "Transit",
        120000,
        12300,
        100,
        2010,
        2,
        2.5,
        4,
        200,
        2
    };
    van.printSummary();
    van.attachTrailer(2);
    van.printSummary();

    Sedan sedan{
        "Lexus",
        "LS",
        120000,
        12300,
        200,
        2010,
        3,
        2.5,
        "saloon"
    };
    
    sedan.printSummary();

    Excavator excavator{
        "Hyundai",
        "ABCD1234",
        300000,
        40000,
        30,
        2020,
        3,
        6.0,
        4.0,
        "excavator",
        "mud"
    };
    
    excavator.printSummary();

}