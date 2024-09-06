#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int merged[nums1Size + nums2Size];
    int i = 0, j = 0, k = 0;
    
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    
    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }
    
    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }
    
    int len = nums1Size + nums2Size;
    if (len % 2 == 0) {
        return (merged[len / 2 - 1] + merged[len / 2]) / 2.0;
    } else {
        return merged[len / 2];
    }
}

int main() {
    int nums1a[] = {1, 3};
    int nums2a[] = {2};
    printf("%lf\n", findMedianSortedArrays(nums1a, 2, nums2a, 1));
    
    int nums1b[] = {1, 2};
    int nums2b[] = {3, 4};
    printf("%lf\n", findMedianSortedArrays(nums1b, 2, nums2b, 2));

    return 0;
}