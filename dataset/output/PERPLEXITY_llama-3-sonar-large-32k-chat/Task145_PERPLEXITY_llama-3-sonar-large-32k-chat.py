def max_subarray_sum(arr):
    max_current = max_global = arr[0]
    for i in range(1, len(arr)):
        max_current = max(arr[i], max_current + arr[i])
        if max_current > max_global:
            max_global = max_current
    return max_global

arr = [int(x) for x in input("Enter the array elements separated by space: ").split()]
print("Maximum contiguous sum is", max_subarray_sum(arr))