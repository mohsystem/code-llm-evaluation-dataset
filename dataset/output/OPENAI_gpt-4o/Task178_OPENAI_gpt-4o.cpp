#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    deque<int> dq;
    int minLength = INT_MAX;

    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
            minLength = min(minLength, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main() {
    vector<int> nums1 = {1};
    vector<int> nums2 = {1, 2};
    vector<int> nums3 = {2, -1, 2};

    cout << shortestSubarray(nums1, 1) << endl; // Output: 1
    cout << shortestSubarray(nums2, 4) << endl; // Output: -1
    cout << shortestSubarray(nums3, 3) << endl; // Output: 3

    return 0;
}