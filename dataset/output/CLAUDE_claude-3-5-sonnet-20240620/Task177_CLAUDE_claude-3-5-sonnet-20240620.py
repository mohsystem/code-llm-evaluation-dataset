
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dq = collections.deque()
        for i in range(len(nums)):
            if dq:
                nums[i] += dq[0]
            while dq and dq[-1] < nums[i]:
                dq.pop()
            if nums[i] > 0:
                dq.append(nums[i])
            if i >= k and dq and dq[0] == nums[i - k]:
                dq.popleft()
        return max(nums)
