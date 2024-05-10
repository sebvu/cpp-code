#include <fstream>
#include <iostream>
#include <string>

// will reap words before or after specified delimeter into its text file

int main() {
    std::string fileName;
    char delimeter;
    int reapWhere;
    std::ifstream file;

    while (true) {  // check if file exists
        std::cout << "Type txt file name: ";
        std::cin >> fileName;

        file.open(fileName);

        if (!file.is_open()) {
            std::cout << "File does not exist." << std::endl;
            continue;
        } else {
            break;
        }
    }

    std::cout << std::endl;  // delimeter splitter
    std::cout << "What is the delimeter? Will find first occurence."
              << std::endl
              << "Note that if the delimeter does not exist in a line, it will "
                 "skip that line."
              << std::endl
              << std::endl
              << "Type delimeter: ";
    std::cin >> delimeter;

    std::cout << std::endl;
    while (true) {  // reap before or after
        std::cout << "Reap\n(1) before\n(2) after\n\nEnter reap: ";
        std::cin >> reapWhere;
        if (reapWhere != 1 && reapWhere != 2) {
            std::cout << "Not an option." << std::endl;
            continue;
        } else {
            break;
        }
    }

    std::string reapedFileName = "./reaped/";  // reaped directory

    switch (reapWhere) {

    case 1:
        reapedFileName.append("before_");
        break;
    case 2:
        reapedFileName.append("after_");
        break;
    }

    reapedFileName.append(fileName);

    try {
        std::ofstream reapFile(reapedFileName);  // open output file

        if (!reapFile.is_open()) {
            throw std::runtime_error("Failed to open output file " +
                                     reapedFileName);
        }

        std::cout << std::endl;  // success message, reap will start.
        std::cout << "Successfully opened output file." << std::endl;

        std::string currentLine = "";  // current file line

        // will reap according to parameters
        std::cout << "Reaping." << std::endl;

        while (getline(file, currentLine)) {
            int delimeterPos =
                currentLine.find(delimeter);  // find delimeter pos
            // will reap line depending on reapWhere option and delimeter
            if (delimeterPos == -1) {
                continue;  // will not print out line without delimeter
            } else {
                switch (reapWhere) {
                case 1:  // before delimeter
                    reapFile << currentLine.substr(0, delimeterPos);
                    break;
                case 2:  // after delimeter
                    reapFile << currentLine.substr(delimeterPos + 1,
                                                   currentLine.size() - 1);
                    break;
                }
            }
            reapFile << std::endl;
        }

        std::cout << "Reaping has finished. Please check reaped folder."
                  << std::endl
                  << std::endl
                  << "Happy mayas!" << std::endl;

        file.close();
        reapFile.close();
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}
