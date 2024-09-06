#include <string>
#include <sstream>

std::string to_jaden_case(const std::string &jadenCase) {
  std::string result;
  std::istringstream iss(jadenCase);
  std::string word;
  while (iss >> word) {
    if (!word.empty()) {
      word[0] = std::toupper(word[0]);
    }
    for (size_t i = 1; i < word.length(); ++i) {
      word[i] = std::tolower(word[i]);
    }
    result += word + " ";
  }
  if (!result.empty()) {
    result.pop_back(); 
  }
  return result;
}