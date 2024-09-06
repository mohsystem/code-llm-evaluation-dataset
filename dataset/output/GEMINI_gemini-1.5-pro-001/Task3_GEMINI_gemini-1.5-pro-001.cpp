#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool isPangram(string str) {
  set<char> alphabet;
  for (char c : str) {
    if (isalpha(c)) {
      alphabet.insert(tolower(c));
    }
  }
  return alphabet.size() == 26;
}