#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size, n = nums2Size;
    int half = (m + n + 1) / 2;
    int l = 0, r = m;
    
    while (l <= r) {
        int i = (l + r) / 2;
        int j = half - i;
        
        int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
        int Aright = (i == m) ? INT_MAX : nums1[i];
        int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
        int Bright = (j == n) ? INT_MAX : nums2[j];
        
        if (Aleft <= Bright && Bleft <= Aright) {
            if ((m + n) % 2) {
                return fmax(Aleft, Bleft);
            }
            return (fmax(Aleft, Bleft) + fmin(Aright, Bright)) / 2.0;
        }
        if (Aleft > Bright) r = i - 1;
        else l = i + 1;
    }
    return 0.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    printf("%lf
", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}