#include <iostream>
#include <vector>

std::vector<int> countSmaller(const std::vector<int>& nums) {
    std::vector<int> result;
    for (size_t i = 0; i < nums.size(); i++) {
        int count = 0;
        for (size_t j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}

int main() {
    std::vector<int> nums = {5, 2, 6, 1};
    std::vector<int> result = countSmaller(nums);
    for (int count : result) {
        std::cout << count << " ";
    }
    return 0;
}