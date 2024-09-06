#include <iostream>
#include <string>
#include <vector>
using namespace std;

string tweakLetters(string txt, vector<int> arr) {
  string res = "";
  for (int i = 0; i < txt.length(); i++) {
    if (arr[i] == 1) {
      res += char(txt[i] + 1);
    } else if (arr[i] == -1) {
      res += char(txt[i] - 1);
    } else {
      res += txt[i];
    }
  }
  return res;
}

int main() {
    // test the code
    cout << tweakLetters("apple", {0, 1, -1, 0, -1}) << endl;
    cout << tweakLetters("many", {0, 0, 0, -1}) << endl;
    cout << tweakLetters("rhino", {1, 1, 1, 1, 1}) << endl;
    return 0;
}