import bisect

def rangeSum(nums, lower, upper):
    n = len(nums)
    preSum = [0] * n
    preSum[0] = nums[0]
    for i in range(1, n):
        preSum[i] = preSum[i - 1] + nums[i]
    
    ans = 0
    for i in range(n):
        lo = i
        hi = n-1
        idx = -1
        while lo <= hi:
            mid = (lo + hi) // 2
            cur = preSum[mid]
            if i > 0:
                cur -= preSum[i - 1]
            if cur < lower:
                lo = mid + 1
            else:
                idx = mid
                hi = mid - 1
        if idx != -1:
            cur = preSum[idx]
            if i > 0:
                cur -= preSum[i - 1]
            if lower <= cur <= upper:
                ans += 1
    return ans

print(rangeSum([-2,5,-1], -2, 2))
print(rangeSum([0], 0, 0))