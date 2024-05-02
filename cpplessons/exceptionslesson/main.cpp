#include <iostream>
#include <cmath>
#include "exception.h"

float Solve(float number) {

    float result = 0;

    result = number/2;

    if (result < 0)
        throw BadValue(number);
    else if (result == 0)
        throw ZeroValue{};

    return result;

}

float Calculate(float number) {
    number *= 2;
    return Solve(number);
}

int main() {
    float number;
    std::cin >> number;

    try {
        float result = Calculate(number);
        std::cout << "Divided by 2: " << result << std::endl;
    }
    catch(BadValue& ex) {
        std::cout << "There was a problem with the value: " << ex.GetValue() <<std::endl;
    }
    catch(ZeroValue ex) {
        std::cout << "Zero value exception" << std::endl;
    }
    catch(...) {
        std::cout << "There is an error" << std::endl;
    }
    std::cout << "All done here." << std::endl;
}