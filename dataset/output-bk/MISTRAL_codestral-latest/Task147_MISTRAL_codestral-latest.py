def find_kth_largest(nums, k):
    nums.sort(reverse=True)
    return nums[k-1]