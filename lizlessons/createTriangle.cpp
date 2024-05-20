#include <iostream>

int main()
{
    char character;
    int triangleDimension = 0;

    for (int i = 0; i < 3; i++) {
        std::cout
            << "Please enter the character that will make up the right triangle."
            << std::endl;
        std::cin >> character;
        std::cout << "Please enter the dimension of the right triangle."
                  << std::endl;
        std::cin >> triangleDimension;

        for (int i = 0; i < triangleDimension; i++) {
            for (int j = 0; j < i; j++) {
                std::cout << character;
            }
            std::cout << std::endl;
        }
    }
}
