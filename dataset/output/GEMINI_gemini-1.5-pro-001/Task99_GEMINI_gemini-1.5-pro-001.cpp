#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;
    regex pattern("^\\d+\\.$");

    while (getline(file, line)) {
        if (regex_match(line, pattern)) {
            cout << line << endl;
        }
    }

    file.close();
    return 0;
}