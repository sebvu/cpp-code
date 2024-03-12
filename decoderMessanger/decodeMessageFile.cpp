#include <iostream>
#include <map>
#include <fstream>
#include <string>

// Declaring decode function that will take an ifstream object.
std::string decode (std::ifstream&);

int main() {
    // Recieving .txt file from user
    // An alternative would be to set inputFile filename of the given testcase, however multiple test cases are used for my purposes.
    std::string inputFile; 
    std::cin >> inputFile;
    // Open input file to parse in to a string for decoding.
    std::ifstream input(inputFile);
    // File validation to check if file is open.
    if (!input.is_open()) {
        std::cerr << "Error: File not found" << std::endl;
        return 1;
    }
    // After validating our file is open, we will put it through out decode function.
    std::cout << decode(input) << std::endl;

    input.close();

    return 0;
}

std::string decode (std::ifstream& input) {
    // With the format, (# word), we are able to store all input into a map inputMap.
    std::map<int, std::string> inputMap;
    // Will append all decoded messages into message to return.
    std::string message = "";
    std::string inputText;
    // Using delimeter " ", we can extract our key and value pairs that will assign each number (key) to the corresponding text (value) per parsed line.
    while (getline(input, inputText)) {
        // To avoid repetition, we are pre-assigning our key and values in terms of our delimeter spacePos.
        int spacePos = inputText.find(" ");
        int key = stoi(inputText.substr(0, spacePos)); // Converting to integer.
        std::string value = inputText.substr(spacePos + 1, inputText.size());
        // Insert key value pairs into inputMap.
        inputMap.insert(std::pair<int, std::string>(key, value));
    }
    // Input file text is now formatted into value key pair inputMap.

    // Using the Triangular Numbers Sequence formula n(n + 1)/2 (where we substitute n for key),
    // we can find all the number sequences paired values within inputMap.size() and append to message.
    // Value examples (1, 3, 6, 10, 15, 21....)
    
    for (int key = 1; key < inputMap.size(); key++) {
        int currentSequence = key * (key + 1) / 2; // Gives the sequence for current index.
        if (inputMap.size() < currentSequence) // Will return message if current sequence exceeds map size. Essential for avoiding out of range error.
            return message.erase(message.size()-1); // Returns message, removes trailing white space.
        message.append(inputMap.at(currentSequence)).append(" ");
    }
    return message.erase(message.size()-1); // Returns message, removes trailing white space.
}