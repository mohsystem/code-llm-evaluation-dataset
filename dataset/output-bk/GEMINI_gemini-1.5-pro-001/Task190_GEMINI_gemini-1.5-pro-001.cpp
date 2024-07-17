#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<vector<string>> matrix;
    ifstream file("file.txt");
    string line;

    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ' ')) {
            row.push_back(cell);
        }
        matrix.push_back(row);
    }

    for (size_t j = 0; j < matrix[0].size(); j++) {
        for (size_t i = 0; i < matrix.size(); i++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}