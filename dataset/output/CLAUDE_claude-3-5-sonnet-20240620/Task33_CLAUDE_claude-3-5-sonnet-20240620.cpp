
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    static int queueTime(std::vector<int> customers, int n) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> tills;
        
        for (int i = 0; i < n; i++) {
            tills.push(0);
        }
        
        for (int customerTime : customers) {
            int tillTime = tills.top();
            tills.pop();
            tills.push(tillTime + customerTime);
        }
        
        int maxTime = 0;
        while (!tills.empty()) {
            maxTime = tills.top();
            tills.pop();
        }
        
        return maxTime;
    }
};
