#include <iostream>
#include <string>
#include "Car.h"

int main() {

    // car class is used as a blueprint
    Car Car1 = Car("Camry", "Toyota", 2016);

    GasCar FordFiesta = GasCar("Fiesta", "Ford", 2014, 11);
    ElectricCar CyberTruck = ElectricCar("Cybertruck", "Tesla", 2023, 19);

    FordFiesta.carDetails(); // Override check
    FordFiesta.accelerate();
    FordFiesta.accelerate();
    FordFiesta.fillUp(); // Normal call check
    FordFiesta.accelerate();
    FordFiesta.PimpMyRide(); // Inheritence check
    std::cout << "\n\n";
    CyberTruck.carDetails();
    CyberTruck.accelerate();
    CyberTruck.accelerate();
    CyberTruck.fillUp();
    CyberTruck.accelerate();
    CyberTruck.PimpMyRide();

    std::cout << "\n\n"; // Polymorphism check
    // FordFiesta.maintenance();
    // CyberTruck.maintenance();

    Car* pCarFord = &FordFiesta; // Pointer of base class can hold reference to derived class object
    Car* pCarTesla = &CyberTruck; // Pointers are pointing to references of derived classes.

    pCarFord->maintenance(); // -> used to access members using a pointer
    pCarTesla->maintenance(); 

    /*
        If ran without virtual keyword to maintenance, would only run maintenance in normal base class.
        When virtual functions are invoked, it will check if there are implementations in its derived classes. If so, execute that instead.
        Since we have maintenance defined that overwrites our virtual maintenance in our base class, 
        pointers will point at maintenance overwriting instead.
        This is called runtime polymorphism!
    */ 



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
        Polymorphism:
            Compound of Poly & Morph.. Ability of an object/method to have many forms. 
            The most common use of polymorphism is when a parent class reference is used to refer to a child class object.
    */

} 