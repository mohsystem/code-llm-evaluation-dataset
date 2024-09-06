#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    string filename = "input.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    map<string, string> records;
    string line, key, value;

    while (getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != string::npos) {
            key = line.substr(0, pos);
            value = line.substr(pos + 1);
            records[key] = value;
        }
    }

    file.close();

    for (auto const& pair : records) {
        cout << pair.first << "=" << pair.second << endl;
    }

    return 0;
}