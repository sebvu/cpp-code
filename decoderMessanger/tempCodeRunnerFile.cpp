std::string decode (std::ifstream& inputFile) {
//     std::map<int, std::string> inputMap;
//     std::string message = "";
//     std::string inputText;

//     while (getline(inputFile, inputText)) {
//         int spacePos = inputText.find(" ");
//         int key = stoi(inputText.substr(0, spacePos)); 
//         std::string value = inputText.substr(spacePos + 1, inputText.size());
//         inputMap.insert(std::pair<int, std::string>(key, value));
//     }
    
//     for (int key = 1; key < inputMap.size(); key++) {
//         int currentTriangleSequence = key * (key + 1) / 2;
//         if (inputMap.size() < currentTriangleSequence)
//             break;
//         message.append(inputMap.at(currentTriangleSequence)).append(" ");
//     }
//     return message.erase(message.size()-1); 
// }