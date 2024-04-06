#include "ElectronicStoreInventory.h"
#include "Printer.h"
#include "Computer.h"

ElectronicStoreInventory::ElectronicStoreInventory() {
    // Default constructor implementation
    count = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        Inventory[i] = nullptr;
    }
}

bool ElectronicStoreInventory::addDevice(const GenericDevice & _device) {
    // Implementation to add a device to the inventory
    // Check if the inventory is full
    if (count >= MAX_SIZE) {
        std::cout << "Inventory is full. Cannot add more devices." << std::endl;
        return false;
    }
    // Check if the device is a Computer or Printer
    if (_device.getType() == "Computer") {
        Inventory[count] = new Computer(dynamic_cast<const Computer&>(_device));
    } else if (_device.getType() == "Printer") {
        Inventory[count] = new Printer(dynamic_cast<const Printer&>(_device));
    } else {
        std::cout << "Unknown device type. Cannot add to inventory." << std::endl;
        return false;
    }
    count++;
    return true;
}

bool ElectronicStoreInventory::removeDevice(const std::string & _serialNumber) {
    // Implementation to remove a device from the inventory
    for (int i = 0; i < count; ++i) {
        if (Inventory[i] != nullptr && Inventory[i]->getSerialNumber() == _serialNumber) {
            delete Inventory[i];
            Inventory[i] = nullptr;
            // Shift remaining elements to fill the gap
            for (int j = i; j < count - 1; ++j) {
                Inventory[j] = Inventory[j + 1];
                Inventory[j + 1] = nullptr;
            }
            count--;
            return true;
        }
    }
    // Device with the given serial number not found
    std::cout << "Device with serial number " << _serialNumber << " not found in inventory." << std::endl;
    return false;
}

void ElectronicStoreInventory::print() const
{
    for (int i = 0; i < count; ++i)
    {
        if (Inventory[i] != nullptr)
        {
            if (Inventory[i]->getType() == "Computer")
            {
                Computer* computer = dynamic_cast<Computer*>(Inventory[i]);
                if (computer != nullptr)
                {
                    computer->print(); // Call the print() function of Computer
                }
            }
            else if (Inventory[i]->getType() == "Printer")
            {
                Printer* printer = dynamic_cast<Printer*>(Inventory[i]);
                if (printer != nullptr)
                {
                    printer->print(); // Call the print() function of Printer
                }
            }
        }
    }
}




void ElectronicStoreInventory::summary() const
{
    int computerCount = 0;
    int printerCount = 0;
    
    for (int i = 0; i < count; ++i) {
        if (Inventory[i] != nullptr) {
            if (Inventory[i]->getType() == "Computer") {
                computerCount++;
            } else if (Inventory[i]->getType() == "Printer") {
                printerCount++;
            }
        }
    }
    
    std::cout << "Total number of computers in the store = " << computerCount << std::endl;
    std::cout << "Total number of printers in the store = " << printerCount << std::endl;
}


ElectronicStoreInventory::~ElectronicStoreInventory() {
    // Destructor implementation to delete objects in the inventory
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (Inventory[i] != nullptr) {
            delete Inventory[i];
            Inventory[i] = nullptr;
        }
    }
}

const GenericDevice & ElectronicStoreInventory::getDevice(int pos) {
    // Implementation to get a device from the inventory
    if (pos >= 0 && pos < count && Inventory[pos] != nullptr) {
        return *Inventory[pos];
    } else {
        std::cout << "Invalid position or device not found." << std::endl;
        exit(0);
    }
}
