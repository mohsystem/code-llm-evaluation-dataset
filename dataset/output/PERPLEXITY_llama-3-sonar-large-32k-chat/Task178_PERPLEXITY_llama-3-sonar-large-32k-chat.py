def shortest_subarray(nums, k):
    n = len(nums)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i]
    res = n + 1
    queue = []
    for i in range(n + 1):
        while queue and prefix_sum[i] - prefix_sum[queue[0]] >= k:
            res = min(res, i - queue.pop(0))
        while queue and prefix_sum[i] <= prefix_sum[queue[-1]]:
            queue.pop()
        queue.append(i)
    return res if res <= n else -1