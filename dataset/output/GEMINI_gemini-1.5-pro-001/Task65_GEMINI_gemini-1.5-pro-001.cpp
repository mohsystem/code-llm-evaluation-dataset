#include <iostream>
#include <fstream>

using namespace std;

string readFile(const string& filename) {
    ifstream file(filename);
    string content;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        return content;
    } else {
        cerr << "Error: Could not open file '" << filename << "'" << endl;
        return "";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    string fileContent = readFile(filename);

    if (!fileContent.empty()) {
        cout << fileContent;
    }

    return 0;
}