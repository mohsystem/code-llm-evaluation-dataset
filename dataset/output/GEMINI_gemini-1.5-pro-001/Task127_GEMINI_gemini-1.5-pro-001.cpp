#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void processFile(const string& sourceFilePath) {
    try {
        ifstream sourceFile(sourceFilePath, ios::binary);
        if (!sourceFile.is_open()) {
            throw runtime_error("Error: File not found at " + sourceFilePath);
        }

        string tempFilePath = tmpnam(nullptr); 
        ofstream tempFile(tempFilePath, ios::binary);
        if (!tempFile.is_open()) {
            throw runtime_error("Error: Could not create temporary file");
        }

        tempFile << sourceFile.rdbuf();

        cout << "File copied successfully to: " << tempFilePath << endl;

        sourceFile.close();
        tempFile.close();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }
}

int main() {
    string sourceFilePath = "/path/to/your/source/file";
    processFile(sourceFilePath);
    return 0;
}