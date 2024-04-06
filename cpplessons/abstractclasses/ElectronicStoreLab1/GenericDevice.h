#ifndef GENERICDEVICE_H
#define GENERICDEVICE_H

#include <iostream>
#include <string>

// FIXME: Add the virtual qualifier and pure virtual functions when needed

class GenericDevice
{
    private:
        std::string manufacturer;
        std::string description;
        std::string serialNumber;
    public:
        GenericDevice(const std::string & _manufacturer, const std::string & _description, const std::string & _serialNumber);
        virtual std::string getType() const = 0;
        std::string getManufacturer() const;
        std::string getDescription() const;
        std::string getSerialNumber() const;
        void print() const;
        bool operator == (const GenericDevice &) const;
        virtual ~GenericDevice(){ std::cout << "Device deleted." << std::endl; }

};

#endif