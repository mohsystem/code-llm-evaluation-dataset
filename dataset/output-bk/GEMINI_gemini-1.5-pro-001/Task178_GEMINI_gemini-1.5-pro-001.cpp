#include <vector>
#include <deque>
#include <limits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        int res = INT_MAX;
        deque<int> queue;
        for (int i = 0; i < n + 1; i++) {
            while (!queue.empty() && preSum[i] - preSum[queue.front()] >= k) {
                res = min(res, i - queue.front());
                queue.pop_front();
            }
            while (!queue.empty() && preSum[i] <= preSum[queue.back()]) {
                queue.pop_back();
            }
            queue.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};