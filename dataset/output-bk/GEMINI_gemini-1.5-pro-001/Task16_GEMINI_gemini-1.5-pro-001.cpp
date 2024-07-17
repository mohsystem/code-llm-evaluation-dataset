#include <iostream>
#include <string>

bool solution(const std::string& str, const std::string& ending) {
  if (str.length() < ending.length()) {
    return false;
  }
  return str.find(ending, str.length() - ending.length()) != std::string::npos;
}

int main() {
  std::cout << solution("abc", "bc") << std::endl; // 1 (true)
  std::cout << solution("abc", "d") << std::endl; // 0 (false)
  return 0;
}