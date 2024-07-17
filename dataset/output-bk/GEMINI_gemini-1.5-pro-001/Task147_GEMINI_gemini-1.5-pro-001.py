def findKthLargest(nums, k):
    nums.sort()
    return nums[len(nums) - k]