#include <iostream>

int main() {
  int lowerBound, upperBound;

  std::cout << "Please enter lower starting value, and upper exclusive bound of counted numbers." << std::endl;

  std::cin >> lowerBound >> upperBound;

  for (int i = lowerBound; i < upperBound; i++) {
    std::cout << i << std::endl;
  }


  std::cout << "Thanks for playing!" << std::endl;
  return 0;
}
