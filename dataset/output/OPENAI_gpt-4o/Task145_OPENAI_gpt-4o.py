def max_subarray_sum(arr):
    max_current = max_global = arr[0]
    for num in arr[1:]:
        max_current = max(num, max_current + num)
        if max_current > max_global:
            max_global = max_current
    return max_global

# Example array
arr = [1, -3, 2, 1, -1]
print(f'Max contiguous subarray sum is: {max_subarray_sum(arr)}')