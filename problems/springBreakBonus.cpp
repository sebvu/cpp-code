#include <iostream>
#include <cmath>


int sumOfDiv3Or5(int& number) {
    int totalSum = 0;

    for (int i = 0; i < number; i++)
        if (i % 3 == 0 || i % 5 == 0)
            totalSum += i;
    return totalSum;
}

bool isPrime(int& num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int sumOfPrimeNumbers() {
    int number = 5;
    int totalAmountOfPrimes = 2; // Already counting 2 and 3
    int totalPrimeSum = 5; // Already summing 2 and 3

    while (totalAmountOfPrimes < 500) {
        number += 2; // Increment by 2 to check only odd numbers after 3
        if (isPrime(number)) {
            totalAmountOfPrimes++;
            totalPrimeSum += number;
        }
    }

    return totalPrimeSum;
}

int certainPrimeNumber(int& number) {
    int totalAmountOfPrimes = 2;
    int potentialPrime = 0;

    while (totalAmountOfPrimes <= number) {
        if (totalAmountOfPrimes == number) {
            break;
        }
        if (isPrime(potentialPrime))
            totalAmountOfPrimes++;
        potentialPrime++;
    }
    return potentialPrime;

}

int main() {

int number = 2023;

std::cout << "Sum of 3 and 5 for " << number << " is " << sumOfDiv3Or5(number) << std::endl;

std::cout << "The sum of the first 500 prime numbers is: " << sumOfPrimeNumbers() << std::endl;

number = 101;

std::cout << "The " << number << " prime number is: " << certainPrimeNumber(number) << std::endl; 

}