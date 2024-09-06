#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide a filename as argument." << endl;
        return 1;
    }
    string filename = argv[1];
    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    vector<pair<string, string>> records;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string key, value;
        iss >> key >> value;
        records.push_back(make_pair(key, value));
    }
    file.close();

    sort(records.begin(), records.end());

    for (const auto &record : records) {
        cout << record.first << " " << record.second << endl;
    }

    return 0;
}