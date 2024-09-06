import sys
class Solution:
    def shortestSubarray(self, nums: list[int], k: int) -> int:
        n = len(nums)
        preSum = [0] * (n + 1)
        for i in range(n):
            preSum[i + 1] = preSum[i] + nums[i]
        res = sys.maxsize
        q = []
        for i in range(n + 1):
            while q and preSum[i] - preSum[q[0]] >= k:
                res = min(res, i - q.pop(0))
            while q and preSum[i] <= preSum[q[-1]]:
                q.pop()
            q.append(i)
        return res if res < sys.maxsize else -1