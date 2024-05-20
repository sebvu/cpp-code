#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Configuration {
  int difficulty;
  string playerName;
};

Configuration loadConfig(const string& filename) {
  ifstream configFile(filename);
  if (!configFile.is_open()) {
    cerr << "Error: Could not open configuration file: " << filename << endl;
    exit(1);
  }

  string line;
  Configuration config;

  while (getline(configFile, line)) {
    stringstream ss(line);
    string key, value;
    getline(ss, key, '=');
    getline(ss, value);

    if (key == "difficulty") {
      config.difficulty = stoi(value);
    } else if (key == "playerName") {
      config.playerName = value;
    }
  }

  configFile.close();
  return config;
}

void updateConfig(const string& filename, const Configuration& newConfig) {
  ofstream configFile(filename);
  if (!configFile.is_open()) {
    cerr << "Error: Could not open configuration file for writing: " << filename << endl;
    exit(1);
  }

  configFile << "difficulty=" << newConfig.difficulty << endl;
  configFile << "playerName=" << newConfig.playerName << endl;

  configFile.close();
}

int main() {
  const string configFile = "config.txt";
  Configuration config = loadConfig(configFile);

  cout << "Welcome, " << config.playerName << "!" << endl;
  cout << "Difficulty level: " << config.difficulty << endl;

  // Simulate gameplay logic here...

  // Update configuration at runtime
  config.difficulty++;
  config.playerName = "New Player";

  updateConfig(configFile, config);

  cout << "Configuration updated:" << endl;
  cout << "  Difficulty: " << config.difficulty << endl;
  cout << "  Player Name: " << config.playerName << endl;

  return 0;
}

