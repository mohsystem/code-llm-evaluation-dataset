#include <deque>
#include <vector>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    if (nums.empty()) {
        return {};
    }
    if (k == 0) {
        return {};
    }
    
    std::vector<int> output(nums.size() - k + 1);
    std::deque<int> dq;
    
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if (i >= k - 1) {
            output[i - k + 1] = nums[dq.front()];
        }
    }
    
    return output;
}