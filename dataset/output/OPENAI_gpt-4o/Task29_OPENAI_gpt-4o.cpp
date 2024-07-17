#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    throw std::invalid_argument("No two sum solution");
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> result1 = twoSum(nums1, 4);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]
";

    std::vector<int> nums2 = {3, 2, 4};
    std::vector<int> result2 = twoSum(nums2, 6);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]
";

    return 0;
}