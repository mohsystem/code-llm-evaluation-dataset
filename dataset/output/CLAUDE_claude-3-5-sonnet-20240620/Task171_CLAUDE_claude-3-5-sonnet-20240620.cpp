
#include <vector>
#include <iostream>

class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
private:
    int mergeSort(std::vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        
        merge(nums, left, mid, right);
        return count;
    }
    
    void merge(std::vector<int>& nums, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        for (int p = 0; p < temp.size(); p++) {
            nums[left + p] = temp[p];
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3, 2, 3, 1};
    std::vector<int> nums2 = {2, 4, 3, 5, 1};
    std::cout << solution.reversePairs(nums1) << std::endl;  // Output: 2
    std::cout << solution.reversePairs(nums2) << std::endl;  // Output: 3
    return 0;
}
