#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string command;
    cout << "Enter OS command: ";
    getline(cin, command);
    system(command.c_str());
    return 0;
}