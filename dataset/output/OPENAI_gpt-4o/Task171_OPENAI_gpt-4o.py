def reversePairs(nums):
    def merge_sort(nums, l, r):
        if l >= r:
            return 0
        mid = l + (r - l) // 2
        count = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r)
        j = mid + 1
        for i in range(l, mid + 1):
            while j <= r and nums[i] > 2 * nums[j]:
                j += 1
            count += j - (mid + 1)
        nums[l:r + 1] = sorted(nums[l:r + 1])
        return count

    return merge_sort(nums, 0, len(nums) - 1)


nums1 = [1, 3, 2, 3, 1]
nums2 = [2, 4, 3, 5, 1]
print(reversePairs(nums1))  # Output: 2
print(reversePairs(nums2))  # Output: 3