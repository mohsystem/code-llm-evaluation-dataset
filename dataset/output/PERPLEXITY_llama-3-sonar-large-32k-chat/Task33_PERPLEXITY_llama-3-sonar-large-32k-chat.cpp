#include <vector>
#include <algorithm>

int queueTime(std::vector<int> customers, int n) {
    if (customers.empty()) {
        return 0;
    }
    std::vector<int> tills(n, 0);
    for (int time : customers) {
        int minTill = std::distance(tills.begin(), std::min_element(tills.begin(), tills.end()));
        tills[minTill] += time;
    }
    return *std::max_element(tills.begin(), tills.end());
}