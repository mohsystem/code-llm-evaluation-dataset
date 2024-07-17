def shortestSubarray(nums, k):
    n = len(nums)
    prefix = [0] * (n + 1)
    for i in range(n):
        prefix[i + 1] = prefix[i] + nums[i]
    res = n + 1
    queue = []
    for i in range(n + 1):
        while queue and prefix[i] - prefix[queue[0]] >= k:
            res = min(res, i - queue.pop(0))
        while queue and prefix[queue[-1]] >= prefix[i]:
            queue.pop()
        queue.append(i)
    return res if res <= n else -1