
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        deque = collections.deque()
        shortest = float('inf')
        
        for i in range(n + 1):
            while deque and prefix_sum[i] - prefix_sum[deque[0]] >= k:
                shortest = min(shortest, i - deque.popleft())
            
            while deque and prefix_sum[i] <= prefix_sum[deque[-1]]:
                deque.pop()
            
            deque.append(i)
        
        return shortest if shortest != float('inf') else -1
