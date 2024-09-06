#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int m = nums1Size, n = nums2Size;
  if (m > n) return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

  int imin = 0, imax = m, half_len = (m + n + 1) / 2;

  while (imin <= imax) {
    int i = (imin + imax) / 2;
    int j = half_len - i;
    if (i < m && nums2[j - 1] > nums1[i]) {
      imin = i + 1;
    } else if (i > 0 && nums1[i - 1] > nums2[j]) {
      imax = i - 1;
    } else {
      int max_left = (i == 0) ? INT_MIN : nums1[i - 1];
      max_left = max(max_left, nums2[j - 1]);

      int max_right = (j == 0) ? INT_MAX : nums1[i];
      max_right = min(max_right, nums2[j]);

      return (m + n) % 2 ? max_left : (max_left + max_right) / 2.0;
    }
  }
  return 0.0;
}
