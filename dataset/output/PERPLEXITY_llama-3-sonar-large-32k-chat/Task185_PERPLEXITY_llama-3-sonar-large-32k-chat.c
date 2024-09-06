#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* merged = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        merged[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        merged[nums1Size + i] = nums2[i];
    }
    qsort(merged, nums1Size + nums2Size, sizeof(int), compare);
    int length = nums1Size + nums2Size;
    if (length % 2 == 0) {
        return (merged[length / 2 - 1] + merged[length / 2]) / 2.0;
    } else {
        return merged[length / 2];
    }
}