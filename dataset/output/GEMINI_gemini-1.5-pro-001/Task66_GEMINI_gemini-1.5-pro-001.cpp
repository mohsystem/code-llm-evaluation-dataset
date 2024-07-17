#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <array>
#include <sstream>

using namespace std;

bool is_valid_command(const string& command) {
    for (char c : command) {
        if (!isalnum(c) && !isspace(c) && 
            string("./_-").find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    string command;

    cout << "Enter a bash command: ";
    getline(cin, command);

    if (is_valid_command(command)) {
        int result = system(command.c_str());
        if (result != 0) {
            cerr << "Error executing command: " << command << endl;
        }
    } else {
        cout << "Invalid command format. Please use only alphanumeric characters, spaces, and './-_' " << endl;
    }

    return 0;
}