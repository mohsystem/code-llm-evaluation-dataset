#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int* nums = malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            nums[k++] = nums1[i++];
        } else {
            nums[k++] = nums2[j++];
        }
    }
    while (i < m) {
        nums[k++] = nums1[i++];
    }
    while (j < n) {
        nums[k++] = nums2[j++];
    }

    double median;
    if ((m + n) % 2 == 0) {
        median = (nums[(m + n) / 2] + nums[(m + n) / 2 - 1]) / 2.0;
    } else {
        median = nums[(m + n) / 2];
    }

    free(nums);
    return median;
}