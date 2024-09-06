#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Record {
    string key;
    string value;
};

bool compareRecords(const Record& a, const Record& b) {
    return a.key < b.key;
}

vector<Record> readFile(const string &filename) {
    vector<Record> records;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Record record;
        getline(ss, record.key, '=');
        getline(ss, record.value);
        records.push_back(record);
    }

    file.close();
    return records;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    vector<Record> records = readFile(filename);
    sort(records.begin(), records.end(), compareRecords);

    for (const auto &record : records) {
        cout << record.key << " = " << record.value << endl;
    }

    return 0;
}