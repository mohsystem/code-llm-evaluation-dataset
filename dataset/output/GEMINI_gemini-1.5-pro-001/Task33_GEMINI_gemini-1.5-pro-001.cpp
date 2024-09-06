#include <algorithm>
#include <vector>

int queueTime(std::vector<int> customers, int n) {
  if (customers.empty()) {
    return 0;
  }

  if (n == 1) {
    return std::accumulate(customers.begin(), customers.end(), 0);
  }

  if (n >= customers.size()) {
    return *std::max_element(customers.begin(), customers.end());
  }

  std::vector<int> tills(n, 0);

  for (int customerTime : customers) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
      if (tills[i] < tills[minIndex]) {
        minIndex = i;
      }
    }
    tills[minIndex] += customerTime;
  }

  std::sort(tills.begin(), tills.end());
  return tills[n - 1];
}