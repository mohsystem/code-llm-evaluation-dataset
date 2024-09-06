def findMedianSortedArrays(nums1, nums2):
  """
  Finds the median of two sorted arrays.

  Args:
      nums1: The first sorted array.
      nums2: The second sorted array.

  Returns:
      The median of the two sorted arrays.
  """

  m, n = len(nums1), len(nums2)
  if m > n:
    return findMedianSortedArrays(nums2, nums1)  # Ensure nums1 is smaller

  imin, imax, half_len = 0, m, (m + n + 1) // 2  # Handles odd/even case

  while imin <= imax:
    i = (imin + imax) // 2
    j = half_len - i
    if i < m and nums2[j-1] > nums1[i]:
      imin = i + 1
    elif i > 0 and nums1[i-1] > nums2[j]:
      imax = i - 1
    else:
      if i == 0: max_left = nums2[j-1]
      else: max_left = max(nums1[i-1], nums2[j-1])

      if j == 0: max_right = nums1[i]
      else: max_right = min(nums1[i], nums2[j])

      return max_left if (m + n) % 2 else (max_left + max_right) / 2

