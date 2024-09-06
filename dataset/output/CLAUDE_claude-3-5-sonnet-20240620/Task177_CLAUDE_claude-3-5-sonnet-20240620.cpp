
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty()) {
                nums[i] += dq.front();
            }
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            if (nums[i] > 0) {
                dq.push_back(nums[i]);
            }
            if (i >= k && !dq.empty() && dq.front() == nums[i - k]) {
                dq.pop_front();
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
