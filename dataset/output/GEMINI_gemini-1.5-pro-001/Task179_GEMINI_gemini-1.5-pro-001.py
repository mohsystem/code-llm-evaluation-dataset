def maxSlidingWindow(nums, k):
    if not nums:
        return []
    if k == 1:
        return nums
    
    n = len(nums)
    max_left = [0] * n
    max_right = [0] * n
    max_left[0] = nums[0]
    max_right[n - 1] = nums[n - 1]

    for i in range(1, n):
        max_left[i] = nums[i] if i % k == 0 else max(max_left[i - 1], nums[i])
        j = n - i - 1
        max_right[j] = nums[j] if (j + 1) % k == 0 else max(max_right[j + 1], nums[j])

    result = [0] * (n - k + 1)
    for i in range(n - k + 1):
        result[i] = max(max_right[i], max_left[i + k - 1])

    return result