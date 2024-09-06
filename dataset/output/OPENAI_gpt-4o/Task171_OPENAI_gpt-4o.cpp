#include <vector>
#include <iostream>
#include <algorithm>

class ReversePairs {
public:
    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size());
    }

private:
    int mergeSort(std::vector<int>& nums, int start, int end) {
        if (end - start <= 1) {
            return 0;
        }

        int mid = (start + end) / 2;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid, end);
        int j = mid;

        for (int i = start; i < mid; i++) {
            while (j < end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - mid;
        }

        std::inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end);
        return count;
    }
};

int main() {
    std::vector<int> nums1 = {1, 3, 2, 3, 1};
    ReversePairs solution;
    std::cout << solution.reversePairs(nums1) << std::endl;  // Output: 2

    std::vector<int> nums2 = {2, 4, 3, 5, 1};
    std::cout << solution.reversePairs(nums2) << std::endl;  // Output: 3
    
    return 0;
}