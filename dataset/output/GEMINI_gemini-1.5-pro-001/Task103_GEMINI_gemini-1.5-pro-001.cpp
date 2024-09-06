#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool checkPasswordStrength(const string& password) {
  if (password.length() < 8) {
    return false;
  }
  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;
  for (char c : password) {
    if (isupper(c)) {
      hasUpper = true;
    } else if (islower(c)) {
      hasLower = true;
    } else if (isdigit(c)) {
      hasDigit = true;
    }
  }
  return hasUpper && hasLower && hasDigit;
}

int main() {
  string password;
  cout << "Enter a password: ";
  cin >> password;

  if (checkPasswordStrength(password)) {
    cout << "Strong password" << endl;
  } else {
    cout << "Weak password" << endl;
  }
  return 0;
}