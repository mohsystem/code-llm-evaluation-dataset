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
        int left_count = mergeSort(nums, left, mid);
        int right_count = mergeSort(nums, mid + 1, right);
        int merged_count = merge(nums, left, mid, right);
        return left_count + right_count + merged_count;
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int left_index = left, right_index = mid + 1, temp_index = 0, count = 0;
        while (left_index <= mid && right_index <= right) {
            if (nums[left_index] <= 2 * nums[right_index]) {
                temp[temp_index++] = nums[left_index++];
            } else {
                temp[temp_index++] = nums[right_index++];
                count += mid - left_index + 1;
            }
        }
        while (left_index <= mid) {
            temp[temp_index++] = nums[left_index++];
        }
        while (right_index <= right) {
            temp[temp_index++] = nums[right_index++];
        }
        copy(temp.begin(), temp.end(), nums.begin() + left);
        return count;
    }
};