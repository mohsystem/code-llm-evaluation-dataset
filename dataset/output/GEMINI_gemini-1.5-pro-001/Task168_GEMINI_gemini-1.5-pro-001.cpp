#include <string>
#include <vector>

using namespace std;

string tweakLetters(string txt, vector<int> arr) {
  string newTxt = "";
  for (int i = 0; i < txt.length(); i++) {
    if (arr[i] == 1) {
      newTxt += (char) (txt[i] + 1);
    } else if (arr[i] == -1) {
      newTxt += (char) (txt[i] - 1);
    } else {
      newTxt += txt[i];
    }
  }
  return newTxt;
}