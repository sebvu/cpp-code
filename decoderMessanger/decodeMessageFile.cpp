#include <iostream>
#include <map>
#include <fstream>
#include <string>

std::string decode (std::string &message) {
    
}

int main() {
    // Recieving .txt file from user
    // An altnerative would be to set ifstream input to filename, however it is set to take in user input to pass different test cases.
    std::string inputFile; 
    std::cin >> inputFile;
    // Open input file to parse in to a string for decoding.
    std::ifstream input(inputFile);
    // File validation to check if file is open.
    if (!input.is_open()) {
        std::cerr << "Error: File not found" << std::endl;
        return 1;
    }
    // With the format, (# word), we are able to store all input into a map inputMap.
    std::string inputText;
    std::map<int, std::string> inputMap;
    // Using delimeter " ", will extract input into a 
    while(getline(input, inputText)) {
        std::cout << "Value: " << inputText.substr(0, inputText.find(" ")) << std::endl;;
        inputMap[inputText[0]] = inputText.substr(0, inputText.find(" "));
    }



    input.close();

    return 0;
}