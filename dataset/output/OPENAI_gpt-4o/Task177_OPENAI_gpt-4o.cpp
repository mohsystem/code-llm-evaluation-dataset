#include <iostream>
#include <deque>
#include <vector>
#include <climits>

using namespace std;

int maxSubsequenceSum(vector<int>& nums, int k) {
    if (nums.empty()) return 0;

    int n = nums.size();
    vector<int> dp(n);
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
    int k1 = 2;
    cout << maxSubsequenceSum(nums1, k1) << endl; // Output: 37

    vector<int> nums2 = {-1, -2, -3};
    int k2 = 1;
    cout << maxSubsequenceSum(nums2, k2) << endl; // Output: -1

    vector<int> nums3 = {10, -2, -10, -5, 20};
    int k3 = 2;
    cout << maxSubsequenceSum(nums3, k3) << endl; // Output: 23

    return 0;
}