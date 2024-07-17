#include <vector>
#include <algorithm>

int queue_time(std::vector<int> customers, int n) {
    std::vector<int> tills(n, 0);
    for (int i : customers) {
        int minIndex = std::min_element(tills.begin(), tills.end()) - tills.begin();
        tills[minIndex] += i;
    }
    return *std::max_element(tills.begin(), tills.end());
}