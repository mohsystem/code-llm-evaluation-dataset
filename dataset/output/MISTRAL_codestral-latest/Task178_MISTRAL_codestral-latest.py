def shortest_subarray(nums, k):
    n = len(nums)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i]

    ans = n + 1
    deque = collections.deque()
    for i in range(n + 1):
        while deque and prefix_sum[i] - prefix_sum[deque[0]] >= k:
            ans = min(ans, i - deque.popleft())
        while deque and prefix_sum[i] <= prefix_sum[deque[-1]]:
            deque.pop()
        deque.append(i)

    return ans if ans <= n else -1