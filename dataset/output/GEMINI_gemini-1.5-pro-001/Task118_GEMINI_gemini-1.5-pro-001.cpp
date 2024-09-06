#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool isValidIP(const string& ip) {
  regex regexPattern(
      "^((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$");
  return regex_match(ip, regexPattern);
}

int main() {
  string ipAddress;
  cout << "Enter an IP address: ";
  cin >> ipAddress;

  if (isValidIP(ipAddress)) {
    cout << "Valid IP address" << endl;
  } else {
    cout << "Invalid IP address" << endl;
  }

  return 0;
}