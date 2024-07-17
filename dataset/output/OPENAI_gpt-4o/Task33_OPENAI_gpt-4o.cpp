#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int queueTime(std::vector<int> customers, int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> tills;
    for (int i = 0; i < n; i++) {
        tills.push(0);
    }
    for (int time : customers) {
        int current = tills.top();
        tills.pop();
        tills.push(current + time);
    }
    while (!tills.empty()) {
        int totalTime = tills.top();
        tills.pop();
        if (tills.empty()) {
            return totalTime;
        }
    }
    return 0;
}

int main() {
    std::cout << queueTime({5, 3, 4}, 1) << std::endl; // should return 12
    std::cout << queueTime({10, 2, 3, 3}, 2) << std::endl; // should return 10
    std::cout << queueTime({2, 3, 10}, 2) << std::endl; // should return 12
    
    return 0;
}