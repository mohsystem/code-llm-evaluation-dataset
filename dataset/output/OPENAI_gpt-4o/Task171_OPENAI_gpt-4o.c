#include <stdio.h>
#include <stdlib.h>

int mergeAndCount(int* nums, int l, int mid, int r) {
    int count = 0;
    int* merged = (int*)malloc((r - l + 1) * sizeof(int));
    int i = l, j = mid + 1, k = 0;

    for (i = l; i <= mid; i++) {
        while (j <= r && nums[i] > 2L * nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            merged[k++] = nums[i++];
        } else {
            merged[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        merged[k++] = nums[i++];
    }
    while (j <= r) {
        merged[k++] = nums[j++];
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        nums[i] = merged[k];
    }

    free(merged);
    return count;
}

int mergeSortAndCount(int* nums, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int mid = l + (r - l) / 2;
    int count = mergeSortAndCount(nums, l, mid) + mergeSortAndCount(nums, mid + 1, r);
    count += mergeAndCount(nums, l, mid, r);
    return count;
}

int reversePairs(int* nums, int numsSize) {
    return mergeSortAndCount(nums, 0, numsSize - 1);
}

int main() {
    int nums1[] = {1, 3, 2, 3, 1};
    int nums2[] = {2, 4, 3, 5, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%d
", reversePairs(nums1, size1));  // Output: 2
    printf("%d
", reversePairs(nums2, size2));  // Output: 3
    return 0;
}