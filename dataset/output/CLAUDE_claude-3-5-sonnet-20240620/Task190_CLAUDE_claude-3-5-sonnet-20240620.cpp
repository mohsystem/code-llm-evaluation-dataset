
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream file("file.txt");
    vector<vector<string>> content;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        vector<string> row;
        string word;
        while (iss >> word) {
            row.push_back(word);
        }
        content.push_back(row);
    }

    for (size_t j = 0; j < content[0].size(); ++j) {
        for (size_t i = 0; i < content.size(); ++i) {
            cout << content[i][j];
            if (i < content.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
