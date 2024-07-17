from collections import deque

def max_subsequence_sum(nums, k):
    n = len(nums)
    if n == 0:
        return 0

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

# Test cases
print(max_subsequence_sum([10, 2, -10, 5, 20], 2))  # 37
print(max_subsequence_sum([-1, -2, -3], 1))         # -1
print(max_subsequence_sum([10, -2, -10, -5, 20], 2)) # 23