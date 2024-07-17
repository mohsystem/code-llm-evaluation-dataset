#include <iostream>
#include <regex>

using namespace std;

bool isValidIP(string ipAddress) {
    regex ipPattern("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");
    return regex_match(ipAddress, ipPattern);
}

int main() {
    string ipAddress = "192.168.1.1";
    if (isValidIP(ipAddress)) {
        cout << ipAddress << " is a valid IP address." << endl;
    } else {
        cout << ipAddress << " is not a valid IP address." << endl;
    }
    return 0;
}