#include <iostream>
#include <fstream> 
#include <string>
#include <limits>

struct Employee {
    std::string name;
    int nKeysPossessed;
    std::string keys[5];
};

bool reader(std::string input_filename, Employee employees[], int& nEmployees) {
/* 
    Load key information and store it in an Employee array.
    Will take in a string for filename, array of Employee array, and number of employees passed as reference.
    Function will attempt to open the input file. If the input file does not exist, the function returns false.
    Otherwise, the function will load the key information, then return true.

    <number of employees>
    <employee 1's name>
    <number of keys employee 1 possesses> <employee 1's key1> <employee 1's key 2> ...
    <employee 2's name>
    <number of keys employee 2 possesses> <employee 2's key1> <employee 2's key 2> ...
    .....
*/

    std::ifstream inputFile(input_filename);

    if (!inputFile.is_open())
        return false;

    inputFile >> nEmployees; // Take number of employees from first line

    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < nEmployees; i++) { // loop through number of Employees
        
        getline(inputFile, employees[i].name); // extract name

        inputFile >> employees[i].nKeysPossessed;

        for (int j = 0; j < employees[i].nKeysPossessed; j++)
            inputFile >> employees[i].keys[j];

        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    inputFile.close();
    return true;
}

void writer(std::string output_filename, Employee employees[], int nEmployees) {
    
    std::ofstream outputFile(output_filename);

    if (!outputFile.is_open()) {
        std::cout << "File not open." << std::endl;
    }

    outputFile << nEmployees << std::endl; // adding number of employees to beginning

    for (int i = 0; i < nEmployees; i++) {
        outputFile << employees[i].name << std::endl;

        outputFile << employees[i].nKeysPossessed;

        for (int j = 0; j < employees[i].nKeysPossessed; j++) {
            outputFile << " " << employees[i].keys[j];
        }
        outputFile << std::endl;
    }
    outputFile.close();
}

bool addKeyForEmployee(Employee employees[], int nEmployees, std::string emp_name, std::string newKey) {

    int employeeIndex;

    for (int i = 0; i < nEmployees; i++) { //iiterate through employees array to find employee index
        if (employees[i].name == emp_name) {
            employeeIndex = i;
            break;
        }
        if (i == nEmployees-1) { // if employee is not found, return false.
            std::cout << "Cannot find the specified employee!" << std::endl;
            return false;
        }
    }

    if (employees[employeeIndex].nKeysPossessed == 5) { // checker to prevent exceeding 5 keys
        std::cout << "This employee already has 5 keys!" << std::endl << std::endl;
        return false;
    }

    for (int i = 0; i < employees[employeeIndex].nKeysPossessed; i++) { // checker to prevent copied keys
        if (employees[employeeIndex].keys[i] == newKey) {
            std::cout << "This employee already has this key!" << std::endl << std::endl;
            return false;
        }
    }

    // If all checks pass, add newKey at end of array and increase key possession by 1.

    employees[employeeIndex].keys[employees[employeeIndex].nKeysPossessed] = newKey;
    employees[employeeIndex].nKeysPossessed++;

    return true;
}

bool returnAKey(Employee employees[], int nEmployees, std::string emp_name, std::string returnKey) {
    int employeeIndex;
    int keyIndex;

    for (int i = 0; i < nEmployees; i++) { //iiterate through employees array to find employee index
        if (employees[i].name == emp_name) {
            employeeIndex = i;
            break;
        }
        if (i == nEmployees-1) { // if employee is not found, return false.
            std::cout << "Cannot find the specified employee!" << std::endl;
            return false;
        }
    }

    for (int i = 0; i < employees[employeeIndex].nKeysPossessed; i++) { // checks if key exists
        if (employees[employeeIndex].keys[i] == returnKey) {
            keyIndex = i;
            break;
        }
        
        if (i == employees[employeeIndex].nKeysPossessed-1) {
            std::cout << "This employee does not have the specified key!" << std::endl << std::endl;
            return false;
        }
    }

    for (int i = keyIndex; i < employees[employeeIndex].nKeysPossessed-1; i++) {// removing specified key and shifting elements
        employees[employeeIndex].keys[i] = employees[employeeIndex].keys[i + 1];
        /*
            starting at specified keyIndex in which the index will be deleted, we will
            iterate until the number of keys possessed - 1 to prevent a segmentation fault error.
            we will set to the index above.
        */
    }
    
    employees[employeeIndex].keys[employees[employeeIndex].nKeysPossessed - 1] = ""; // Assuming keys are strings, replace "" with default value if necessary

    employees[employeeIndex].nKeysPossessed--;
    return true;

}

int userOptionsDisplay() { // Display user prompt for employees
    int userInput = 0;
    do {
    std::cout << "Please select from the following options: " << std::endl
    << "  1. show all employees and their keys" << std::endl
    << "  2. show the keys an employee possesses" << std::endl
    << "  3. show which employees possess a specific key" << std::endl
    << "  4. add a key to an employee" << std::endl
    << "  5. return a key by an employee" << std::endl
    << "  6. save the current key status" << std::endl
    << "  7. exit the program" << std::endl;
    
    std::cin >> userInput;
    if (userInput < 1 || userInput > 7)
    std::cout << "Not a valid option. Please try again." << std::endl << std::endl;
    } while (userInput < 1 || userInput > 7); // Loop continues only for invalid input

    return userInput;
}

void printEmployeesAndKeys(Employee employees[], int nEmployees) {
    for (int i = 0; i < nEmployees; i++) {
        std::cout << "Name: " << employees[i].name << std::endl << "Keys possessed: ";
        for (int j = 0; j < employees[i].nKeysPossessed; j++) 
            std::cout << employees[i].keys[j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void showKeysAnEmployeePossesses(std::string name, Employee employee[], int nEmployees) {
    int employeeIndex;
    bool exists = false;

    for (int i = 0; i < nEmployees; i++) {
        if (employee[i].name == name) {
            employeeIndex = i;
            exists = true;
            break;
        }
        if (i == nEmployees - 1) {
            std::cout << "Cannot find the specified employee!";
        }
    }
    if(exists) {
        std::cout << employee[employeeIndex].name << " possess the following keys: ";
        for (int i = 0; i < employee[employeeIndex].nKeysPossessed; i++) {
            std::cout << employee[employeeIndex].keys[i] << " ";
        }
    }
    std::cout << std::endl << std::endl;;
}

void whichEmployeePossessesSpecificKey(Employee employee[], std::string key, int nEmployees) {
    std::string employeesPossessing = "";
    bool isPossessed = false;
    
    for (int i = 0; i < nEmployees; i++) {
        for (int j = 0; j < employee[i].nKeysPossessed; j++) {
            if (employee[i].keys[j] == key) {
                isPossessed = true;
                employeesPossessing.append(employee[i].name).append(", ");
            }
        }
    }

    if (isPossessed) {
        employeesPossessing.append("possess this key.");
        std::cout << employeesPossessing << std::endl << std::endl;
    }
    else
        std::cout << "No one possesses this key." << std::endl << std::endl;
}

int main() {
    Employee employees[10];
    int nEmployees;

    std::string filename;

    std::cout << "Please enter key file name to start: ";

    std::cin >> filename;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(!reader(filename, employees, nEmployees)) {
        std::cout << "File not found, exiting the program..." << std::endl;
        return 0;
    }

    // All file validation checks are complete.
    
    while(true) {

        int userInput = userOptionsDisplay();

        std::cin.ignore(1);

        if (userInput == 1)
            printEmployeesAndKeys(employees, nEmployees);
        else if (userInput == 2) {
            std::string name;
            std::cout << "Please enter employee's name: ";
            getline(std::cin, name);
            showKeysAnEmployeePossesses(name, employees, nEmployees);
        }
        else if (userInput == 3) {
            std::string key;
            std::cout << "Please enter a key: ";
            std::cin >> key;
            whichEmployeePossessesSpecificKey(employees, key, nEmployees);
        }
        else if (userInput == 4) {
            std::string name, newKey;
            std::cout << "Please enter employee's name: ";
            getline(std::cin, name);
            std::cout << "Please enter a new key: ";
            std::cin >> newKey;
            if (addKeyForEmployee(employees, nEmployees, name, newKey))
                std::cout << "Key added successfully." << std::endl << std::endl;
        }
        else if (userInput == 5) {
            std::string name, returnedKey;
            std::cout << "Please enter employee's name: ";
            getline(std::cin, name);
            std::cout << "Please enter the returned key: ";
            std::cin >> returnedKey;
            if (returnAKey(employees, nEmployees, name, returnedKey))
                std::cout << "Key returned successfully." << std::endl << std::endl;
        }
        else if (userInput == 6) {
            std::string outputFileName;
            std::cout << "Please enter output file name: " << std::endl;
            std::cin >> outputFileName;
            writer(outputFileName, employees, nEmployees);
        }
        else if (userInput == 7) {
            writer("keys_updated.txt", employees, nEmployees);
            break;
        }
    }

    std::cout << "Thank you for using the system! Goodbye!" << std::endl;

    return 0;
}