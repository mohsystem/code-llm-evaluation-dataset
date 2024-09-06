#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filePath;

    cout << "Enter the path to the file you want to upload: ";
    getline(cin, filePath);

    ifstream file(filePath, ios::binary);

    if (file.is_open()) {
        // Get the file size
        file.seekg(0, ios::end);
        streampos fileSize = file.tellg();
        file.seekg(0, ios::beg);

        // Read the file content into a buffer
        char* buffer = new char[fileSize];
        file.read(buffer, fileSize);
        file.close();

        // Process the uploaded file content (buffer) here
        // ...

        delete[] buffer;

        cout << "File uploaded successfully!" << endl;
    } else {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    return 0;
}