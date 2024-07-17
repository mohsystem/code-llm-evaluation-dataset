
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = nums.copy()
        dq = collections.deque()
        
        for i in range(n):
            if dq and i - dq[0] > k:
                dq.popleft()
            
            if dq:
                dp[i] = max(dp[i], nums[i] + dp[dq[0]])
            
            while dq and dp[dq[-1]] <= dp[i]:
                dq.pop()
            
            if dp[i] > 0:
                dq.append(i)
        
        return max(dp)
