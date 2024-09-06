#include <string>
#include <algorithm>

std::string spinWords(const std::string &str) {
  std::string result;
  std::string word;
  for (char c : str) {
    if (c == ' ') {
      if (word.length() >= 5) {
        std::reverse(word.begin(), word.end());
      }
      result += word + ' ';
      word = "";
    } else {
      word += c;
    }
  }
  if (word.length() >= 5) {
    std::reverse(word.begin(), word.end());
  }
  result += word;
  return result;
}