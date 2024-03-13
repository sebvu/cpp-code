#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <random>
#include <algorithm>

void generateTestCase(const std::vector<std::string>& randomWords, std::ofstream& fout, const std::vector<std::string>& encodingWords) {

    std::map<int, std::string> encodedTriangleSequenceMap;

    int maxSize = (encodingWords.size() * (encodingWords.size() + 1)) / 2; // amount of randonmly generated words

    for (int i = 0; i < maxSize; i++) {
        std::random_device randomWordIndex;
        std::uniform_int_distribution<int> dist(0, randomWords.size() - 1); //INDEXED ZERO. have to do - 1 because it is 1 value above the actual max index
        std::string value = randomWords[dist(randomWordIndex)]; //dist(randomWordIndex which is a random index from 0, randomWords.size())
        encodedTriangleSequenceMap.insert(std::pair<int, std::string>(i + 1, value));
    }

    for (int i = 1; i <= encodingWords.size(); i++) {
        int triangleSequenceValue = (i * (i + 1)) / 2;
        std::string value = encodingWords[i - 1];
        encodedTriangleSequenceMap[triangleSequenceValue] = value;
    } 

    std::vector<std::pair<int, std::string>> mapEntries(encodedTriangleSequenceMap.begin(), encodedTriangleSequenceMap.end());
    std::random_device rd;
    std::shuffle(mapEntries.begin(), mapEntries.end(), rd); // shuffles all key value pairs randomly using the shuffle algorithm

    for (const auto& pair : mapEntries) {
        std::cout << pair.first << " - " << pair.second << std::endl;
        fout << pair.first << " " << pair.second << std::endl;
    }
}

int main () {

    const std::vector<std::string> uniqueWords = {
        "apple", "banana", "orange", "grape", "pineapple",
        "watermelon", "strawberry", "blueberry", "kiwi", "mango",
        "peach", "pear", "apricot", "plum", "cherry",
        "raspberry", "blackberry", "lemon", "lime", "coconut",
        "pomegranate", "fig", "nectarine", "guava", "papaya",
        "avocado", "dragonfruit", "lychee", "melon", "cantaloupe",
        "honeydew", "passionfruit", "kiwano", "starfruit", "persimmon",
        "breadfruit", "durian", "jackfruit", "kumquat", "tangerine",
        "tangelo", "clementine", "mandarin", "grapefruit", "boysenberry",
        "loganberry", "elderberry", "mulberry", "cranberry", "gooseberry",
        "bilberry", "blackcurrant", "rhubarb", "apostrophe", "hyacinth",
        "daisy", "tulip", "rose", "lily", "sunflower",
        "daffodil", "carnation", "orchid", "peony", "dandelion",
        "marigold", "violet", "poppy", "lilac", "iris",
        "jasmine", "lavender", "chrysanthemum", "dahlia", "hydrangea",
        "azalea", "begonia", "camellia", "geranium", "petunia",
        "snapdragon", "zinnia", "aster", "crocus", "gladiolus",
        "freesia", "narcissus", "anemone", "bluebell", "buttercup",
        "columbine", "forget-me-not", "foxglove", "honeysuckle", "primrose",
        "pansy", "sweetpea", "tigerlily", "verbena", "wisteria",
        "cyclamen", "magnolia", "moonflower", "morning glory", "nasturtium",
        // Additional puppy, cat, and animal terms
        "puppy", "kitten", "whiskers", "tail", "fur",
        "paw", "meow", "woof", "bark", "growl",
        "purr", "scratch", "claw", "pet", "feline",
        "canine", "animal", "mammal", "professor", "academic",
        "scholar", "intellectual", "lecture", "research", "study",
        "knowledge", "wisdom", "education", "university", "learning",
        "classroom", "lesson", "theory", "thesis", "discipline",
        "pedagogy", "curriculum", "syllabus", "literature", "lecture",
        "seminar", "workshop", "conference", "symposium", "colloquium",
        "dean", "professorship", "department", "faculty", "lecture",
        "teaching", "instruction", "lesson", "educator", "mentor"
    };

    // Triangle sequence encoder!
    // Will create a file in your directory with the test case format.

    // formula is n * (n + 1) / 2
    std::string input = "", fileOutput = "";
    std::vector <std::string> wordsToEncode = {};
    
    std::cout << "Please provide a list of words in any specific order to encode. Click enter once all words have been entered."
    << "\n- Add a SINGULAR space between each word. No space should exceed more then one."
    << "\n- Any punctuation and numbers are allowed"
    << "\n- There should be no trailing white spaces on either end.\n";

    getline(std::cin, input);

    std::cout << "Enter text file output name: ";

    std::cin >> fileOutput;

    std::string directoryFileOutput = "./testCases/";

    directoryFileOutput.append(fileOutput).append(".txt"); // ./testCases/file_name.txt

    std::ofstream output(directoryFileOutput);

    if (!output.is_open()) {
        std::cerr << "Error: Output file is not open" << std::endl;
        return 1;
    }

    // We have everything from the user.

    std::cout << "Generating test case. Please wait." << std::endl;

    std::stringstream ss(input);
    std::string word;
    while (ss >> word) {
        wordsToEncode.push_back(word);
    }

    generateTestCase(uniqueWords, output, wordsToEncode);

    std::cout << "\nFile " << fileOutput << ".txt has been created within directory testCases/\n\nFormat is (# word) in a randomized order.\n\nHappy hacking!" << std::endl;
    
    // count how many words there will be
    // generate the number of triangle sequences up to that count
    // assign all the given words to those triangle sequence values
    // generate random words up to that number triangle sequence in a map
    // replace the keys at the triangle sequence with the actual
    // randomly insert them into the output file

    output.close();

}