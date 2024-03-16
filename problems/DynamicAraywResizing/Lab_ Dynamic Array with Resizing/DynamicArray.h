#include <iostream>

using namespace std;

class DynamicArray{
private:
    int *arr;
    int length;
    int size;
public:
    DynamicArray();
    DynamicArray(int s);
    ~DynamicArray();

    void addElement(int val);
    int getLength();
    int getSize();
    int getElement(int pos);
};
