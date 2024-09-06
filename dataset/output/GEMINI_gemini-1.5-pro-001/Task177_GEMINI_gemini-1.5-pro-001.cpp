#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;
        deque<int> dq;
        
        for (int i = 0; i < n; ++i) {
            // Remove outdated elements from the deque
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            // Calculate dp[i + 1] based on the maximum value in the deque
            dp[i + 1] = max(dp[i + 1], max(nums[i], (dq.empty() ? 0 : dp[dq.front()]) + nums[i]));
            
            // Maintain the deque to store indices of potential maximum values
            while (!dq.empty() && dp[dq.back()] <= dp[i + 1]) {
                dq.pop_back();
            }
            dq.push_back(i + 1);
        }
        
        return *max_element(dp.begin() + 1, dp.end());
    }
};