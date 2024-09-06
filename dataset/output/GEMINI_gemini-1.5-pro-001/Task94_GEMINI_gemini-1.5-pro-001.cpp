#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to store key-value pairs
struct KeyValuePair {
    string key;
    string value;
};

// Comparison function for sorting based on keys
bool compareByKey(const KeyValuePair& a, const KeyValuePair& b) {
    return a.key < b.key;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    string filePath = argv[1];
    vector<KeyValuePair> keyValuePairs;

    // Read key-value pairs from the file
    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            size_t pos = line.find(' ');
            if (pos != string::npos) {
                KeyValuePair pair;
                pair.key = line.substr(0, pos);
                pair.value = line.substr(pos + 1);
                keyValuePairs.push_back(pair);
            }
        }
        inputFile.close();
    } else {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    // Sort the key-value pairs based on keys
    sort(keyValuePairs.begin(), keyValuePairs.end(), compareByKey);

    // Print the sorted key-value pairs
    for (const KeyValuePair& pair : keyValuePairs) {
        cout << pair.key << " " << pair.value << endl;
    }

    return 0;
}