#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filePath;
    ifstream file;

    cout << "Enter the file path: ";
    cin >> filePath;

    file.open(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}