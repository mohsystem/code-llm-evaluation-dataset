#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    string command = "cat " + filename;
    int result = system(command.c_str());
    if (result != 0) {
        cerr << "Error displaying file." << endl;
        return 1;
    }

    return 0;
}