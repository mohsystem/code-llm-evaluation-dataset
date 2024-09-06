def shortest_subarray(nums, k):
    n = len(nums)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i]

    min_length = n + 1
    mono_queue = deque()
    for i in range(n + 1):
        while mono_queue and prefix_sum[i] - prefix_sum[mono_queue[0]] >= k:
            min_length = min(min_length, i - mono_queue.popleft())
        while mono_queue and prefix_sum[i] <= prefix_sum[mono_queue[-1]]:
            mono_queue.pop()
        mono_queue.append(i)

    return min_length if min_length <= n else -1