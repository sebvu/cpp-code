#include <map>
#include <iostream>

void intFrequency(int n);

int main() {

    int n = 0;
    std::cout << "Enter a number to find the highest frequency." << std::endl;
    std::cin >> n;

    intFrequency(n);

    return 0;
}

void intFrequency(int n) {
    int digit;
    // the actual question
    std::map<int, int> frequency_map;
    
    while (n > 0) {
        digit = n % 10;
        if (frequency_map.count(digit) != 0) { // if digit is not a key, then insert. first iteration will result in 0
            frequency_map.insert(std::pair<int, int>(digit, 1));
        } else {
            frequency_map[digit] += 1;
        }
        n /= 10;
    }
    // end of question

    for (auto& pair : frequency_map) {
        std::cout << "number:" << pair.first << " happened " << pair.second << " times" <<std::endl;
    }

}
