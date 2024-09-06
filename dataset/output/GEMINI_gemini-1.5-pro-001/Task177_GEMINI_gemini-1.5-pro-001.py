class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [float('-inf')] * (n + 1)
        dp[0] = 0
        deque = collections.deque()
        
        for i in range(n):
            # Remove outdated elements from the deque
            while deque and deque[0] < i - k:
                deque.popleft()
            
            # Calculate dp[i] based on the maximum value in the deque
            dp[i + 1] = max(dp[i + 1], nums[i], dp[deque[0]] + nums[i] if deque else nums[i])
            
            # Maintain the deque to store indices of potential maximum values
            while deque and dp[deque[-1]] <= dp[i + 1]:
                deque.pop()
            deque.append(i + 1)
        
        return max(dp)