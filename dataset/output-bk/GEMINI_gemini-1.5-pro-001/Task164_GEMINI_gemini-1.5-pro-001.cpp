#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> lastNameLensort(vector<string> names) {
  sort(names.begin(), names.end(), [](const string& a, const string& b) {
    string lastNameA = a.substr(a.find(" ") + 1);
    string lastNameB = b.substr(b.find(" ") + 1);
    if (lastNameA.length() == lastNameB.length()) {
      return lastNameA < lastNameB;
    }
    return lastNameA.length() < lastNameB.length();
  });
  return names;
}