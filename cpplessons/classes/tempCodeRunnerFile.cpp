#include <iostream>
#include <string>
#include "Car.h"

int main() {
    Car car1 = Car("Cybertruck", "Tesla", 2023);
    Car car2 = Car("Fiesta", "Ford", 2014);
    
    car1.setYear(2096);
    std::cout << car1.getModel() << " is year " << car1.getYear() << std::endl;
    std::cout << car2.getModel() << " is year " << car2.getYear() << std::endl;

    car1.PimpMyRide();
    car2.PimpMyRide();

    GasCar FordFiesta = GasCar("Fiesta", "Ford", 2014, 100);

    FordFiesta.carDetails();