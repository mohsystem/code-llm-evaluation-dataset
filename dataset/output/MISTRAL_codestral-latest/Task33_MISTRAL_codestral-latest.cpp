#include <vector>
#include <algorithm>

int queueTime(std::vector<int> customers, int n) {
    std::vector<int> tills(n, 0);
    for (int i : customers) {
        auto it = std::min_element(tills.begin(), tills.end());
        *it += i;
    }
    return *std::max_element(tills.begin(), tills.end());
}