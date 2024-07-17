
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            
            window.push_back(i);
            
            if (i >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }
        
        return result;
    }
};
