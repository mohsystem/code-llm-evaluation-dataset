class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int leftCount = mergeSort(nums, left, mid);
        int rightCount = mergeSort(nums, mid + 1, right);
        int mergedCount = merge(nums, left, mid, right);
        return leftCount + rightCount + mergedCount;
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int leftIndex = left, rightIndex = mid + 1, tempIndex = 0, mergedCount = 0;
        while (leftIndex <= mid && rightIndex <= right) {
            if (nums[leftIndex] <= 2 * nums[rightIndex]) {
                temp[tempIndex++] = nums[leftIndex++];
            } else {
                temp[tempIndex++] = nums[rightIndex++];
                mergedCount += mid - leftIndex + 1;
            }
        }
        while (leftIndex <= mid) {
            temp[tempIndex++] = nums[leftIndex++];
        }
        while (rightIndex <= right) {
            temp[tempIndex++] = nums[rightIndex++];
        }
        copy(temp.begin(), temp.end(), nums.begin() + left);
        return mergedCount;
    }
};