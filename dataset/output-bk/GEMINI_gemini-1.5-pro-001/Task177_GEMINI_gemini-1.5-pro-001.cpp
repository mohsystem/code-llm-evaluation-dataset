class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;
        deque<int> q;
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && i - q.front() > k + 1) {
                q.pop_front();
            }
            dp[i] = max(dp[i - 1], (q.empty() ? 0 : dp[q.front()]) + nums[i - 1]);
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[n];
    }
};