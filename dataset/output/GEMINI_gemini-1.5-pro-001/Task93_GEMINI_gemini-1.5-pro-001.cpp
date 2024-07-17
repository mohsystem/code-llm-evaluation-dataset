#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    // Replace "input.txt" with the actual input file name
    string inputFileName = "input.txt";

    // Use a map to store key-value pairs, which automatically sorts by key
    map<string, string> sortedRecords;

    // Read the input file and populate the map
    ifstream inputFile(inputFileName);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            // Assuming key and value are separated by a space
            size_t pos = line.find(" ");
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 1);
                sortedRecords[key] = value;
            }
        }
        inputFile.close();
    } else {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    // Print the sorted key-value pairs
    for (auto const& [key, value] : sortedRecords) {
        cout << key << " " << value << endl;
    }

    return 0;
}