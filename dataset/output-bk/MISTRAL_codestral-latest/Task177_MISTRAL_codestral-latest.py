def max_sum_subsequence(nums, k):
    dp = [0] * len(nums)
    dp[0] = nums[0]
    for i in range(1, len(nums)):
        dp[i] = max(dp[i-1], nums[i])
        for j in range(i-1, max(-1, i-k-1), -1):
            dp[i] = max(dp[i], dp[j] + nums[i])
    return max(dp)