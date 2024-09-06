#include <vector>

int findIt(const std::vector<int>& arr) {
  int result = 0;
  for (int i : arr) {
    result ^= i;
  }
  return result;
}