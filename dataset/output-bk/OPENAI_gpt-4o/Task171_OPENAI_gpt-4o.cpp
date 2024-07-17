#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2L * nums[j])
                j++;
            count += j - (mid + 1);
        }

        sort(nums.begin() + left, nums.begin() + right + 1);
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 2, 3, 1};
    vector<int> nums2 = {2, 4, 3, 5, 1};
    cout << sol.reversePairs(nums1) << endl;  // Output: 2
    cout << sol.reversePairs(nums2) << endl;  // Output: 3
    return 0;
}