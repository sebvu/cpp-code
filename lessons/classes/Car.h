#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class AbstractCar {
    /*
         An abstract class is a class that serves as a blueprint or template for derived classes, but it cannot be used to create objects itself.
        It defines the interface (public methods) and potentially some common functionality, but it doesn't provide complete implementations for all methods.

        Which ever class decides to sign this 'contract', class has to provide implementation for given method.

        PimpMyRide is 'obligatory', force any class to provide implemention for said method.

        Virtual keywords means that PimpMyRIde can be overridden in derived classes.
        
    virtual void PimpMyRide() {
        std::cout << "Hell yeah! Pimp that ride no matter what." << std::endl;
    };
        
        This is a non-pure virtual function. Provides a default definition for PimpMyRide(), can be overwritten still.

        Pure virtual functions: 
            When you want to establish a contract that all derived classes must fulfill, providing a common interface with customizable behavior.
        Normal virtual functions: 
            When you have a default behavior that might work for most derived classes but allow for flexibility if needed.
    
    */

    virtual void PimpMyRide() = 0; //Pure virtual function.
};

class Car:AbstractCar { //Car signed AbstractCar contract
private:
    std::string Model;
    std::string Company;
    int Year;

public:
    Car(std::string Model, std::string Company, int Year) 
        : Model(Model), Company(Company), Year(Year) {}
    
    void setModel(std::string Model) {
        this->Model = Model; // setter
    }
    std::string getModel() {
        return Model; // getter
    }
    void setCompany(std::string Company) {
        this->Company = Company; // setter
    }
    std::string getCompany() {
        return Company; // getter
    }
    void setYear(int Year) {
        if(Year <= 2024) // we can set validation rules
            this->Year = Year; // setter
    }
    int getYear() {
        return Year; // getter
    }

    void PimpMyRide() {
        if(Year <= 2014)
            std::cout << "Hell yeah! We like the OGs. Ride has been pimped." << std::endl;
        else
            std::cout << "Ew.. car is too young man. No pimped ride for you." << std::endl;
    }
    
    void carDetails() {
        std::cout << "Model is - " << Model << std::endl;
        std::cout << "Company is - " << Company << std::endl;
        std::cout << "Year is - " << Year << std::endl;
    }
};

class GasCar:Car { //Child class, inhereted from base class Car
private:
    int Gas;

public:
    GasCar(std::string Model, std::string Company, int Year, int Gas) 
        : Car(Model, Company, Year), Gas(Gas) {}

    void setGas(int Gas) {
        this->Gas = Gas;
    }
    int getGas() {
        return Gas;
    }
    void carDetails() {
        Car::carDetails();
        std::cout << "Gas is at " << Gas << std::endl;
    }
};

class ElectricCar:Car { //Child class, inhereted all properties from base class Car
private:
    int Charge;
    
public:
    ElectricCar(std::string Model, std::string Company, int Year, int Charge) 
        : Car(Model, Company, Year), Charge(Charge) {}

    void setCharge(int Charge) {
        this->Charge = Charge;
    }
    int getCharge() {
        return Charge;
    }
    void carDetails() {
        Car::carDetails();
        std::cout << "Charge is at " << Charge << std::endl;
    }
};


#endif