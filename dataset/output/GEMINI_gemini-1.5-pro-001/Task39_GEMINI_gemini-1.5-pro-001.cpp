#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    string command = "cat " + filename;
    system(command.c_str());
    return 0;
}