#include <iostream>
#include <string>

int largestProduct(const std::string& digits, int span) {
  if (digits.length() < span || span < 1) {
    return 0;
  }
  int maxProduct = 0;
  for (size_t i = 0; i <= digits.length() - span; ++i) {
    int product = 1;
    for (size_t j = i; j < i + span; ++j) {
      product *= digits[j] - '0';
    }
    maxProduct = std::max(maxProduct, product);
  }
  return maxProduct;
}

int main() {
  std::string digits = "63915";
  int span = 3;
  int result = largestProduct(digits, span);
  std::cout << result << std::endl;
  return 0;
}