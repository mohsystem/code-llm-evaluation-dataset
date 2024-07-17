#include <algorithm>
#include <vector>

int solveSuperMarketQueue(const std::vector<int>& customers, int n) {
  if (customers.empty()) return 0;
  if (customers.size() <= n) return *std::max_element(customers.begin(), customers.end());
  
  std::vector<int> tills(n, 0);
  size_t customerIndex = 0;
  
  for (int i = 0; i < n; ++i) {
    tills[i] = customers[customerIndex++];
  }

  while (customerIndex < customers.size()) {
    auto minTill = std::min_element(tills.begin(), tills.end());
    *minTill += customers[customerIndex++];
  }

  return *std::max_element(tills.begin(), tills.end());
}