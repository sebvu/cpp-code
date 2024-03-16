#include <vector>
#include <iostream>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    std::vector<int> staircasesets = {};
    int step = 1;

    while(step != arr.size()) {
        if (step <= arr.size())
            staircasesets.push_back(arr[arr.begin(), step]);
            arr.erase(0, step);
        else {
            std::cout << "Not a staircase" << std::endl;
            return 1;
        }
        step++;
    }

    std::cout << "g" << std::endl;

    return 0;


}