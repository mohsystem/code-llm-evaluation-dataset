#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    string content;

    cout << "Enter the file name to create: ";
    cin >> filename;

    cout << "Enter the content to write to the file:
";
    getline(cin >> ws, content); // Read the entire line, including spaces

    ofstream MyFile(filename);

    if (MyFile.is_open()) {
        MyFile << content;
        MyFile.close();
        cout << "File created and content written successfully!";
    } else {
        cout << "Unable to open file";
    }

    return 0;
}