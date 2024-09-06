def findKthLargest(nums, k):
    nums.sort()
    return nums[k*-1]