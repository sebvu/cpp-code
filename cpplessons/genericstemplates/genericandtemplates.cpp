#include <iostream>

// create typename T,
// typename T is a GENERIC data type
// will work for any datatype
template <typename T>

void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Issue below is copying code. This is where generics come in using templates.
// Idea is using the same logic, however with different datatypes.

// void Swap (int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }
//
// void Swap (char &a, char &b) {
//     char temp = a;
//     a = b;
//     b = temp;
// }

int main() {

    int a = 7, b = 5;
    std::cout << a << " - " << b << std::endl;
    Swap(a, b);
    std::cout << a << " - " << b << std::endl;

    char f = 'a', d = 'b';
    std::cout << f << " - " << d << std::endl;
    Swap(f, d);
    std::cout << f << " - " << d << std::endl;
}
