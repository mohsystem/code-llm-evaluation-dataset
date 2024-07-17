#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename, line;

    cout << "Enter the file name: ";
    cin >> filename;

    try {
        ifstream infile(filename);
        if (!infile.is_open()) {
            throw runtime_error("Error: File not found: " + filename);
        }

        ofstream outfile("temp.txt");
        if (!outfile.is_open()) {
            throw runtime_error("Error: Could not create temporary file.");
        }

        while (getline(infile, line)) {
            outfile << line << endl;
        }

        infile.close();
        outfile.close();
        
        cout << "File copied to temporary location: temp.txt" << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}