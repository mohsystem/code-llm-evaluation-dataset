#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ifstream file("data.csv");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> data = split(line, ',');
            for (const auto& value : data) {
                cout << value << " ";
            }
            cout << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    return 0;
}