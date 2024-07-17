class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        sorted_arr = []
        counts = [0] * n

        for i in range(n - 1, -1, -1):
            index = bisect.bisect_left(sorted_arr, nums[i])
            counts[i] = index
            sorted_arr.insert(index, nums[i])

        return counts