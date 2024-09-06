#include <algorithm>
#include <iostream>
#include <vector>

int longestRun(std::vector<int> nums) {
    if (nums.empty()) {
        return 0;
    }
    std::sort(nums.begin(), nums.end());
    int longest_run = 1;
    int current_run = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - nums[i-1] == 1) {
            current_run += 1;
        } else {
            longest_run = std::max(longest_run, current_run);
            current_run = 1;
        }
    }
    return std::max(longest_run, current_run);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 9};
    std::cout << longestRun(nums) << std::endl;
    return 0;
}