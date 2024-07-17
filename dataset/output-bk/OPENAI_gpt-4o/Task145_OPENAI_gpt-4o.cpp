#include <iostream>
#include <vector>
#include <cstdlib>

int maxSubArray(const std::vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

int main(int argc, char* argv[]) {
    std::vector<int> nums;
    for (int i = 1; i < argc; ++i) {
        nums.push_back(std::atoi(argv[i]));
    }
    std::cout << "C++: " << maxSubArray(nums) << std::endl;
    return 0;
}