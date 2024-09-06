#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    getline(cin, filename);
    string command = "type " + filename;
    if (system(nullptr)) {
        command = ("cat " + filename);
    }
    system(command.c_str());
    return 0;
}