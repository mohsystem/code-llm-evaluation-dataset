#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> result(n - k + 1);
    std::deque<int> window;

    for (int i = 0; i < n; i++) {
        while (!window.empty() && window.front() <= i - k) {
            window.pop_front();
        }
        while (!window.empty() && nums[window.back()] < nums[i]) {
            window.pop_back();
        }
        window.push_back(i);
        if (i >= k - 1) {
            result[i - k + 1] = nums[window.front()];
        }
    }

    return result;
}