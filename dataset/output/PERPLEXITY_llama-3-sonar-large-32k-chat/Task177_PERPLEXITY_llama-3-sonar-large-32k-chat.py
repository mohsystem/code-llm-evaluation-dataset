def maxSum(nums, k):
    n = len(nums)
    dp = [0] * n
    dp[0] = nums[0]
    for i in range(1, n):
        dp[i] = max(dp[i-1], nums[i])
        for j in range(1, min(i, k) + 1):
            dp[i] = max(dp[i], dp[i-j-1] + nums[i])
    return dp[-1]