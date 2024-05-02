#include <iostream>

int main() {
    int* myArray = new int[5]; // Can change the size of myArray on runtime
    // Can delete and re-allocate again

    // myArray is pointing to THE array, myArray is just an object pointing there.

    int myUglyArray[5]; // Set on runtime

    for (int i = 0; i < 5; i++) {
        myArray[i] = i;
    }
    
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << std::endl;
    }

    delete[] myArray; // still defined, but allocation is deleted

    myArray = new int[10];
    
    for (int i = 0; i < 10; i++) {
        std::cout << myArray[i] << std::endl;
    }
}