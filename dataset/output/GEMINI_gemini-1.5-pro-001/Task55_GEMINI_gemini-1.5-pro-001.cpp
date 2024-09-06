#include <iostream>
#include <regex>
using namespace std;

bool isValidEmail(string email) {
  const regex regexPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
  return regex_match(email, regexPattern);
}

int main() {
  string email;
  cout << "Enter an email address: ";
  cin >> email;

  if (isValidEmail(email)) {
    cout << "Valid email address" << endl;
  } else {
    cout << "Invalid email address" << endl;
  }

  return 0;
}