class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1], nums[i]);
            for (int j = 1; j <= min(i, k); j++) {
                dp[i] = max(dp[i], dp[i-j-1] + nums[i]);
            }
        }
        return dp[n-1];
    }
};