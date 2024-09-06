class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        count = 0
        for i in range(n-1):
            for j in range(i+1, n):
                if nums[i] > 2 * nums[j]:
                    count += 1
        return count