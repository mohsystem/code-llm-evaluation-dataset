#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string inputString;
  cout << "Enter a string: ";
  getline(cin, inputString);
  reverse(inputString.begin(), inputString.end());
  cout << inputString << endl;
  return 0;
}