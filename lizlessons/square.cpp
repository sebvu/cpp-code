#include <iostream>

int main() {
    /*
        *****
        *****
        *****
        *****
        *****
    */
    
    int userInput = 0;

    std::cout << "Enter size of square" << std::endl;
    std::cin >> userInput;


    for (int i = 0; i < userInput; i++) {
        for (int x = 0; x < userInput; x++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}