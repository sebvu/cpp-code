#include <iostream>

using namespace std;

class DynamicArray{
private:
    int *arr;
    int usedLength;
    int size;

public:
    DynamicArray() : usedLength(0), size(1) {
        arr = new int[size]; // new int allocated memory for single integer, [size] is our multiplier
    }
    DynamicArray(int s) : usedLength(0), size(s) {
        arr = new int[size];
    }
    ~DynamicArray() {
        delete[] arr; // Delete allocated memory
    };

    void addElement(int val) {
        
    }

    int getUsedLength() {
        return usedLength;
    }
    int getSize() {
        return size;
    } 
    int getElement(int pos) {
        return arr[pos];
    }
};
