#include <iostream>
#include <queue>
#include <vector>

int queueTime(std::vector<int> customers, int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> tills;
    for (int i = 0; i < n; i++) {
        tills.push(0);
    }
    for (int time : customers) {
        int earliestTill = tills.top();
        tills.pop();
        earliestTill += time;
        tills.push(earliestTill);
    }
    int totalTime = 0;
    while (!tills.empty()) {
        totalTime = tills.top();
        tills.pop();
    }
    return totalTime;
}

int main() {
    std::cout << queueTime({5, 3, 4}, 1) << std::endl; // should return 12
    std::cout << queueTime({10, 2, 3, 3}, 2) << std::endl; // should return 10
    std::cout << queueTime({2, 3, 10}, 2) << std::endl; // should return 12
    return 0;
}