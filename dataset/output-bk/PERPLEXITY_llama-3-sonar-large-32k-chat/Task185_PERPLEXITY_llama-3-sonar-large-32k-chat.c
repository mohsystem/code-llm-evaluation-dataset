#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* merged = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        merged[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        merged[nums1Size + i] = nums2[i];
    }
    for (int i = 0; i < nums1Size + nums2Size; i++) {
        for (int j = i + 1; j < nums1Size + nums2Size; j++) {
            if (merged[i] > merged[j]) {
                int temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }
    int length = nums1Size + nums2Size;
    if (length % 2 == 0) {
        return (merged[length / 2 - 1] + merged[length / 2]) / 2.0;
    } else {
        return merged[length / 2];
    }
}