#include <vector>
#include <string>
#include <algorithm>

std::vector<int> filter_list(const std::vector<std::string>& arr) {
  std::vector<int> result;
  for (const auto& item : arr) {
    try {
      int num = std::stoi(item);
      result.push_back(num);
    } catch (const std::invalid_argument& e) {
      // Ignore items that cannot be converted to integers
    } catch (const std::out_of_range& e) {
      // Ignore items that cause integer overflow
    }
  }
  return result;
}