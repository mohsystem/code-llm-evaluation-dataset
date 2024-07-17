def countRangeSum(nums, lower, upper):
    n = len(nums)
    sums = [0] * (n + 1)
    for i in range(n):
        sums[i + 1] = sums[i] + nums[i]
    res = 0
    for i in range(n):
        for j in range(i, n):
            if lower <= sums[j + 1] - sums[i] <= upper:
                res += 1
    return res