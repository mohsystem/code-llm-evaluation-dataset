int reversePairs(int* nums, int numsSize) {
    int mergeSort(int* nums, int start, int end) {
        if (start >= end) {
            return 0;
        }
        int mid = (start + end) / 2;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && (long) nums[i] > 2 * (long) nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        int* temp = malloc(sizeof(int) * (end - start + 1));
        memcpy(temp, nums + start, sizeof(int) * (end - start + 1));
        merge(temp, nums + start, end - start + 1);
        free(temp);
        return count;
    }

    void merge(int* temp, int* nums, int size) {
        int i = 0, j = size / 2, k = 0;
        while (i < size / 2 && j < size) {
            if (temp[i] <= temp[j]) {
                nums[k++] = temp[i++];
            } else {
                nums[k++] = temp[j++];
            }
        }
        while (i < size / 2) {
            nums[k++] = temp[i++];
        }
        while (j < size) {
            nums[k++] = temp[j++];
        }
    }

    return mergeSort(nums, 0, numsSize - 1);
}