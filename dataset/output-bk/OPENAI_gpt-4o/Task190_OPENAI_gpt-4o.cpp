#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void transposeFile(const string& filePath) {
    ifstream file(filePath);
    vector<vector<string>> lines;
    string line;
    
    while (getline(file, line)) {
        vector<string> row;
        string word;
        for (char c : line) {
            if (c == ' ') {
                row.push_back(word);
                word.clear();
            } else {
                word += c;
            }
        }
        row.push_back(word);
        lines.push_back(row);
    }
    file.close();

    int columns = lines[0].size();
    for (int i = 0; i < columns; i++) {
        for (const auto& row : lines) {
            cout << row[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    transposeFile("file.txt");
    return 0;
}