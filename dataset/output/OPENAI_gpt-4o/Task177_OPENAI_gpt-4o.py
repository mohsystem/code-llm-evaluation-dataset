from collections import deque

def maxSubsequenceSum(nums, k):
    if not nums:
        return 0
    
    n = len(nums)
    dp = [0] * n
    dp[0] = nums[0]
    deq = deque([0])
    
    for i in range(1, n):
        while deq and deq[0] < i - k:
            deq.popleft()
        
        dp[i] = nums[i] + (dp[deq[0]] if deq else 0)
        
        while deq and dp[i] >= dp[deq[-1]]:
            deq.pop()

        deq.append(i)
    
    return max(dp)

nums = [10, 2, -10, 5, 20]
k = 2
print(maxSubsequenceSum(nums, k)) # Output: 37

nums = [-1,-2,-3]
k = 1
print(maxSubsequenceSum(nums, k)) # Output: -1

nums = [10, -2, -10, -5, 20]
k = 2
print(maxSubsequenceSum(nums, k)) # Output: 23