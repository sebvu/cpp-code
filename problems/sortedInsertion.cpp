#include <iostream>

int main() {    

    int userInputSize;
    int *arr;

    bool swapped = true;

    std::cin >> userInputSize;

    if (userInputSize == 0) {
        std::cout << "User input is 0.";
        return 1;
    }

    arr = new int[userInputSize]; // allocating memory for an array of integers of size userInputSize

    for (int i = 0; i < userInputSize; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < userInputSize - 1; i++) {
        swapped = false;
        for (int j = 0; j < userInputSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
        break;
        }
    }

    std::cout << "Printing ordered array: ";

    for (int i = 0; i < userInputSize; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}