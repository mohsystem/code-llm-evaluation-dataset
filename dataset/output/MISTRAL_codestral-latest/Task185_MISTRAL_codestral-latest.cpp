#include <vector>
#include <algorithm>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums;
    nums.insert(nums.end(), nums1.begin(), nums1.end());
    nums.insert(nums.end(), nums2.begin(), nums2.end());
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        return (nums[n/2] + nums[n/2 - 1]) / 2.0;
    } else {
        return nums[n/2];
    }
}