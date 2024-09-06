def shortest_subarray(nums, k):
    from collections import deque
    n = len(nums)
    prefix_sum = [0]
    for num in nums:
        prefix_sum.append(prefix_sum[-1] + num)

    deque_indices = deque()
    min_length = float('inf')

    for i in range(n + 1):
        while deque_indices and prefix_sum[i] - prefix_sum[deque_indices[0]] >= k:
            min_length = min(min_length, i - deque_indices.popleft())
        while deque_indices and prefix_sum[i] <= prefix_sum[deque_indices[-1]]:
            deque_indices.pop()
        deque_indices.append(i)

    return min_length if min_length != float('inf') else -1

# Example usage
print(shortest_subarray([1], 1))  # Output: 1
print(shortest_subarray([1, 2], 4))  # Output: -1
print(shortest_subarray([2, -1, 2], 3))  # Output: 3