#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream infile("file.txt");
    string line;
    vector<vector<string>> data;

    // Read file into a vector of vectors (matrix)
    while (getline(infile, line)) {
        stringstream ss(line);
        string word;
        vector<string> row;
        while (ss >> word) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    // Transpose the matrix
    for (size_t i = 0; i < data[0].size(); ++i) {
        for (size_t j = 0; j < data.size(); ++j) {
            cout << data[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}