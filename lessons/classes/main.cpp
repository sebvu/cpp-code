#include <iostream>
#include <string>
#include "Car.h"

int main() {

    // car class is used as a blueprint
    Car Car1 = Car("Camry", "Toyota", 2016);

    Car1.PimpMyRide();

    GasCar FordFiesta = GasCar("Fiesta", "Ford", 2014, 11);
    ElectricCar CyberTruck = ElectricCar("Cybertruck", "Tesla", 2023, 19);

    FordFiesta.carDetails();
    FordFiesta.accelerate();
    FordFiesta.accelerate();
    FordFiesta.fillUp();
    FordFiesta.accelerate();
    FordFiesta.setModel("toyota");
    std::cout << "\n\n";
    CyberTruck.carDetails();
    CyberTruck.accelerate();
    CyberTruck.accelerate();
    CyberTruck.fillUp();
    CyberTruck.accelerate();
    CyberTruck.PimpMyRide();




    /* 
        Encapsulation:
            Make properties private so no class outside of main class can acces it.
            In order to access it, will have to go through properties set up. (setters and getters)
        Abstraction:
            Abstraction in this code allows us to define a general 'Car' concept with a public method PimpMyRide(). 
            This method encapsulates the logic of determining whether a car is eligible for pimping. 
            Other developers using the Car class don't need to worry about the internal implementation details of how this decision is made. 
            They simply call PimpMyRide() and rely on the contract that it will provide the expected behavior 
            (e.g., indicating whether the car is eligible or not).
        Inheritance:
            Base class, (super class/parent class) and derived class (job class/sub class)
            Base class has certain members that could be inherited to child classes
            which will obtain all the members of the base class. 
            Derived class can also have its own members specific to that class, however base class does not have access to it.
    */

} 