#include <iostream>
#include <string>
#include <algorithm>

std::string accum(const std::string& s) {
  std::string result;
  for (size_t i = 0; i < s.length(); ++i) {
    if (i > 0) result += "-";
    result += std::toupper(s[i]);
    result += std::string(i, std::tolower(s[i]));
  }
  return result;
}

int main() {
  std::cout << accum("abcd") << std::endl;
  std::cout << accum("RqaEzty") << std::endl;
  std::cout << accum("cwAt") << std::endl;
  return 0;
}