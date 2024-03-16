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

        Virtual keywords means that PimpMyRide can be overridden in derived classes.
        
    virtual void PimpMyRide() {
        std::cout << "Hell yeah! Pimp that ride no matter what." << std::endl;
    };
        
        This is a non-pure virtual function. Provides a default definition for PimpMyRide(), can be overwritten still.
        You do NOT have to provide an implementation.

        Pure virtual functions: 
            When you want to establish a contract that all derived classes must fulfill, providing a common interface with customizable behavior.
        Normal virtual functions: 
            When you have a default behavior that might work for most derived classes but allow for flexibility if needed.
    
    */

    virtual void PimpMyRide() = 0; //Pure virtual function.
};

class Car: private AbstractCar { //Car signed AbstractCar contract
private:
    std::string Model;
    std::string Company;
    int Year;
/*
protected
    In C++, protected members are inherited by derived classes but cannot be accessed directly using the dot operator on derived class objects. 
    They are accessible only through member functions of the derived class or the base class itself.

    Think of it as private members that could be inherited.
*/
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
            std::cout << Year << "?! Hell yeah! We like the OGs. Ride has been pimped." << std::endl;
        else
            std::cout << Year << ".. Ew.. car is too young man. No pimped ride for you." << std::endl;
    }

    void carDetails() {
        std::cout << "Model is - " << Model << std::endl;
        std::cout << "Company is - " << Company << std::endl;
        std::cout << "Year is - " << Year << std::endl;
    }

    virtual void maintenance() {
        std::cout << Year << " " << Company << " " << Model << " is going through maintenance.." << std::endl;
    }
};

class GasCar: public Car { //Child class, inhereted from base class Car
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

    void accelerate() {
        if (Gas >= 10) {
            Gas -= 10;
            std::cout << "Accelerating and using up 10 gas! You now have " << Gas << " remaining." << std::endl;
        }
        else
            std::cout << Gas << " is not enough gas to accelerate. Fuel up above 10!" << std::endl;;
    }   

    void fillUp() {
        Gas += 30;
        std::cout << "Filling up.... you now have +30 gas!" << std::endl;
    }

    void maintenance() {
        std::cout << getYear() << " " << getCompany() << " " << getModel() << " is going through an oil change.." << std::endl;
    }
};

class ElectricCar: public Car { //Child class, inhereted all properties from base class Car
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

    void accelerate() {
        if (Charge >= 10) {
            Charge -= 10;
            std::cout << "Accelerating and using up 10 charge! You now have " << Charge << " remaining." << std::endl;
        }
        else
            std::cout << Charge << " is not enough charge to accelerate. Charge up above 10!" << std::endl;;
    }   

    void fillUp() {
        Charge += 30;
        std::cout << "Charging up.... you now have +30 charge!" << std::endl;
    }

    void maintenance() {
        std::cout << getYear() << " " << getCompany() << " " << getModel() << " is going through an battery change.." << std::endl;
    }
};

#endif