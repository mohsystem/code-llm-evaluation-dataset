#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::deque<int> dq;
    std::vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.front() == i - k) {
            dq.pop_front();
        }
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

int main() {
    std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    std::vector<int> res1 = maxSlidingWindow(nums1, k1);
    for (int num : res1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> res2 = maxSlidingWindow(nums2, k2);
    for (int num : res2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}