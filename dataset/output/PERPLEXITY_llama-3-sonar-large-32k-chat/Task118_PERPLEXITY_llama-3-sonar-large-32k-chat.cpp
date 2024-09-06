#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool validateIP(string ip) {
    vector<string> parts;
    stringstream ss(ip);
    string part;
    while (getline(ss, part, '.')) {
        parts.push_back(part);
    }
    if (parts.size() != 4) {
        return false;
    }
    for (string part : parts) {
        int num = stoi(part);
        if (num > 255 || num < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string ip;
    cout << "Enter an IP address: ";
    cin >> ip;
    if (validateIP(ip)) {
        cout << "IP address is valid" << endl;
    } else {
        cout << "IP address is not valid" << endl;
    }
    return 0;
}