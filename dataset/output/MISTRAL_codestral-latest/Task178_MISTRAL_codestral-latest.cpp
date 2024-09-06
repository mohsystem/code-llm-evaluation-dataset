#include <vector>
#include <deque>
#include <climits>

int shortestSubarray(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int minLength = n + 1;
    std::deque<int> monoQueue;
    for (int i = 0; i <= n; i++) {
        while (!monoQueue.empty() && prefixSum[i] - prefixSum[monoQueue.front()] >= k) {
            minLength = std::min(minLength, i - monoQueue.front());
            monoQueue.pop_front();
        }
        while (!monoQueue.empty() && prefixSum[i] <= prefixSum[monoQueue.back()]) {
            monoQueue.pop_back();
        }
        monoQueue.push_back(i);
    }

    return minLength <= n ? minLength : -1;
}