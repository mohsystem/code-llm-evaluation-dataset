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
        deque<int> q;
        for (int i = 0; i < n + 1; i++) {
            while (!q.empty() && preSum[i] - preSum[q.front()] >= k) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && preSum[i] <= preSum[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};