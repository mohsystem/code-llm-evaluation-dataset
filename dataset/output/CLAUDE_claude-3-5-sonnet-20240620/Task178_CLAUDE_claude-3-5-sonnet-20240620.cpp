
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        deque<int> deq;
        int shortest = INT_MAX;
        
        for (int i = 0; i <= n; i++) {
            while (!deq.empty() && prefixSum[i] - prefixSum[deq.front()] >= k) {
                shortest = min(shortest, i - deq.front());
                deq.pop_front();
            }
            
            while (!deq.empty() && prefixSum[i] <= prefixSum[deq.back()]) {
                deq.pop_back();
            }
            
            deq.push_back(i);
        }
        
        return shortest == INT_MAX ? -1 : shortest;
    }
};
