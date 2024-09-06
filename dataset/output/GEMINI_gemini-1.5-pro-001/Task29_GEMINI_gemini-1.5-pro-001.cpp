#include <vector>
#include <unordered_map>

std::vector<int> two_sum(const std::vector<int>& numbers, int target) {
    std::unordered_map<int, int> nums;
    for (int i = 0; i < numbers.size(); ++i) {
        int complement = target - numbers[i];
        if (nums.count(complement)) {
            return {nums[complement], i};
        }
        nums[numbers[i]] = i;
    }
    return {}; 
}