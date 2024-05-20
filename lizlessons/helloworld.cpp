#include <iostream>

int main() {   
    int userInput = 0;
      
    for (int i = 0; i < 6; i++) {
        std::cout << "Give me a number" << std::endl;
        std::cin >> userInput;

        userInput = userInput + 5;

        std::cout << userInput << std::endl;
    }
}
