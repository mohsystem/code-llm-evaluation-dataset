#include <iostream>
#include <vector>
#include <algorithm>

int queueTime(std::vector<int> customers, int n) {
    std::vector<int> tills(n, 0);
    for (int time : customers) {
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (tills[i] < tills[minIndex]) {
                minIndex = i;
            }
        }
        tills[minIndex] += time;
    }
    return *std::max_element(tills.begin(), tills.end());
}