class Solution:
    def countRangeSum(self, nums, lower, upper):
        def merge_sort(lo, hi):
            if lo == hi:
                return 0
            mid = (lo+hi) // 2
            count = merge_sort(lo, mid) + merge_sort(mid+1, hi)
            i = j = mid + 1
            for left in sums[lo:mid+1]:
                while i <= hi and sums[i] - left < lower:
                    i += 1
                while j <= hi and sums[j] - left <= upper:
                    j += 1
                count += j - i
            sums[lo:hi+1] = sorted(sums[lo:hi+1])
            return count
        
        sums = [0]
        for num in nums:
            sums.append(sums[-1] + num)
        return merge_sort(0, len(sums) - 1)

nums = [-2, 5, -1]
lower, upper = -2, 2
sol = Solution()
print(sol.countRangeSum(nums, lower, upper))  # Output: 3