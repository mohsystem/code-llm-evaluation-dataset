// This code requires compiling and running in a terminal, 
// and a separate file needs to be provided as input. 
// It's recommended to use Python for a simpler file upload simulation.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename (including extension): ";
    cin >> filename;

    ifstream inputFile(filename, ios::binary);
    ofstream outputFile("uploads/" + filename, ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char buffer[1024];
    while (inputFile.read(buffer, sizeof(buffer))) {
        outputFile.write(buffer, inputFile.gcount());
    }

    inputFile.close();
    outputFile.close();

    cout << "File uploaded successfully!" << endl;

    return 0;
}