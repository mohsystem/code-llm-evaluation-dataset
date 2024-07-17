from collections import deque
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        preSum = [0] * (n + 1)
        for i in range(n):
            preSum[i + 1] = preSum[i] + nums[i]
        res = float('inf')
        queue = deque()
        for i in range(n + 1):
            while queue and preSum[i] - preSum[queue[0]] >= k:
                res = min(res, i - queue.popleft())
            while queue and preSum[i] <= preSum[queue[-1]]:
                queue.pop()
            queue.append(i)
        return res if res != float('inf') else -1