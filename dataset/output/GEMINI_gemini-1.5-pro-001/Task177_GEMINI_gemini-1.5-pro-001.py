class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [float('-inf')] * (n + 1)
        dp[0] = 0
        from collections import deque
        q = deque()
        for i in range(1, n + 1):
            while q and i - q[0] > k + 1:
                q.popleft()
            dp[i] = max(dp[i - 1], dp[q[0]] + nums[i - 1])
            while q and dp[q[-1]] <= dp[i]:
                q.pop()
            q.append(i)
        return dp[n]