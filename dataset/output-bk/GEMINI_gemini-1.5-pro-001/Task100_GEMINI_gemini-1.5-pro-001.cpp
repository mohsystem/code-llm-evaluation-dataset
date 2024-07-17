#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <regex> <filename>" << endl;
        return 1;
    }

    string regex = argv[1];
    string filename = argv[2];

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    regex pattern(regex);
    while (getline(file, line)) {
        smatch match;
        if (regex_search(line, match, pattern)) {
            cout << match.str() << endl;
        }
    }

    file.close();
    return 0;
}