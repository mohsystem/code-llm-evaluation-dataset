#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("file.txt");
    vector<vector<string>> lines;
    string line, word;

    while (getline(file, line)) {
        istringstream stream(line);
        vector<string> row;
        while (stream >> word) {
            row.push_back(word);
        }
        lines.push_back(row);
    }
    file.close();

    for (size_t i = 0; i < lines[0].size(); i++) {
        for (size_t j = 0; j < lines.size(); j++) {
            cout << lines[j][i];
            if (j < lines.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}