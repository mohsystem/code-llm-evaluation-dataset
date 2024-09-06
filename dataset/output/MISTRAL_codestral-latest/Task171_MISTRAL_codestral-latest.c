int reversePairs(int* nums, int numsSize) {
    int mergeSort(int* nums, int start, int end) {
        if (start >= end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long)nums[i] > 2 * (long)nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        int* temp = malloc(sizeof(int) * (end - start + 1));
        memcpy(temp, nums + start, sizeof(int) * (end - start + 1));
        int left = start, right = mid + 1;
        for (int i = start; i <= end; i++) {
            if (left > mid) {
                nums[i] = temp[right - start];
                right++;
            } else if (right > end) {
                nums[i] = temp[left - start];
                left++;
            } else if (temp[left - start] <= temp[right - start]) {
                nums[i] = temp[left - start];
                left++;
            } else {
                nums[i] = temp[right - start];
                right++;
            }
        }
        free(temp);
        return count;
    }
    return mergeSort(nums, 0, numsSize - 1);
}