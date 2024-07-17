#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    // Check if filename argument is provided
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    map<string, string> keyValueMap;
    string line;

    // Read key-value pairs from the file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string key, value;
        // Assuming key and value are separated by a space " "
        if (getline(iss, key, ' ') && getline(iss, value)) {
            keyValueMap[key] = value;
        } else {
            cerr << "Invalid format on line: " << line << endl;
        }
    }
    inputFile.close();

    // Print sorted key-value pairs (map automatically sorts by key)
    for (const auto& pair : keyValueMap) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}