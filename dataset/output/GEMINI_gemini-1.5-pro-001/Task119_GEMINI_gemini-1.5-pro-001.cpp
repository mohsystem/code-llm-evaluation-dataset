#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("data.csv");
    string line;
    vector<vector<string>> data;

    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    for (const auto &row : data) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}