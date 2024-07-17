#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubsequence(vector<int>& nums, int k) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1], nums[i]);
        for (int j = i-1; j >= max(-1, i-k-1); j--) {
            dp[i] = max(dp[i], dp[j] + nums[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}