class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = n + 1;
        deque<int> queue;
        for (int i = 0; i <= n; i++) {
            while (!queue.empty() && prefix[i] - prefix[queue.front()] >= k) {
                res = min(res, i - queue.front());
                queue.pop_front();
            }
            while (!queue.empty() && prefix[queue.back()] >= prefix[i]) {
                queue.pop_back();
            }
            queue.push_back(i);
        }
        return res <= n ? res : -1;
    }
};