#include <iostream>
#include <vector>

bool xorGame(std::vector<int>& nums) {
    int xor_sum = 0;
    for(int num : nums) {
        xor_sum ^= num;
    }
    return xor_sum == 0 || nums.size() % 2 == 0;
}

int main() {
    std::vector<int> nums1 = {1, 1, 2};
    std::vector<int> nums2 = {0, 1};
    std::vector<int> nums3 = {1, 2, 3};
    std::cout << xorGame(nums1) << std::endl;  // Output: 0 (false)
    std::cout << xorGame(nums2) << std::endl;  // Output: 1 (true)
    std::cout << xorGame(nums3) << std::endl;  // Output: 1 (true)
    return 0;
}