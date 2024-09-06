import bisect

def findMedianSortedArrays(nums1, nums2):
  nums1.extend(nums2)
  nums1.sort()
  n = len(nums1)
  if n % 2 == 0:
    return (nums1[n // 2] + nums1[n // 2 - 1]) / 2
  else:
    return nums1[n // 2]