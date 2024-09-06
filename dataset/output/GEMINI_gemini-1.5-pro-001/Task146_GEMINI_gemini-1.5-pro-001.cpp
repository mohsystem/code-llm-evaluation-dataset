#include <vector>
#include <numeric>

int findMissingNumber(std::vector<int> arr) {
  int n = arr.size() + 1;
  int expectedSum = n * (n + 1) / 2;
  int actualSum = std::accumulate(arr.begin(), arr.end(), 0);
  return expectedSum - actualSum;
}