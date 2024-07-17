#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubsequenceSum(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    deque<int> deq;
    deq.push_back(0);

    for (int i = 1; i < n; i++) {
        while (!deq.empty() && deq.front() < i - k) {
            deq.pop_front();
        }
        dp[i] = nums[i] + (deq.empty() ? 0 : dp[deq.front()]);
        while (!deq.empty() && dp[i] >= dp[deq.back()]) {
            deq.pop_back();
        }
        deq.push_back(i);
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums1 = {10, 2, -10, 5, 20};
    vector<int> nums2 = {-1, -2, -3};
    vector<int> nums3 = {10, -2, -10, -5, 20};
    cout << maxSubsequenceSum(nums1, 2) << endl;  // 37
    cout << maxSubsequenceSum(nums2, 1) << endl;  // -1
    cout << maxSubsequenceSum(nums3, 2) << endl;  // 23
    return 0;
}