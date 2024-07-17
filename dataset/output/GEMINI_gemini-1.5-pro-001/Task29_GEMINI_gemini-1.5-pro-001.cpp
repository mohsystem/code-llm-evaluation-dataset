#include <vector>

std::vector<int> two_sum(const std::vector<int>& numbers, int target) {
  for (size_t i = 0; i < numbers.size(); i++) {
    for (size_t j = i + 1; j < numbers.size(); j++) {
      if (numbers[i] + numbers[j] == target) {
        return {static_cast<int>(i), static_cast<int>(j)};
      }
    }
  }
  return {};
}