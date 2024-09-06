#include <cmath>
#include <string>

bool narcissistic(int value) {
  std::string strValue = std::to_string(value);
  int numDigits = strValue.length();
  int total = 0;
  for (int i = 0; i < numDigits; ++i) {
    int digit = strValue[i] - '0';
    total += std::pow(digit, numDigits);
  }
  return total == value;
}