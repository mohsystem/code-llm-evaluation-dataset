#include <algorithm>
#include <vector>

std::vector<int> sortArray(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  return arr;
}