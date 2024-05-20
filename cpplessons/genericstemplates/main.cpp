#include <iostream>

template <typename T>

void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

int main() {
    int x = 5, y = 2;
    int f = 2, z = 9;
    std::string h = "hello", o = "hi";
    char one = '1', two = '2';
    double doubleone = 1.54, doubletwo = 2.54;

    std::cout << x << " - " << y << std::endl;
    std::cout << f << " - " << z << std::endl;
    std::cout << h << " - " << o << std::endl;
    std::cout << one << " - " << two << std::endl;
    std::cout << doubleone << " - " << doubletwo << std::endl;

    std::cout << "Swapping.." << std::endl;

    swap(x, y);
    swap(f, z);
    swap(h, o);
    swap(one, two);

    std::cout << x << " - " << y << std::endl;
    std::cout << f << " - " << z << std::endl;
    std::cout << h << " - " << o << std::endl;
    std::cout << one << " - " << two << std::endl;
    std::cout << doubleone << " - " << doubletwo << std::endl;
}
