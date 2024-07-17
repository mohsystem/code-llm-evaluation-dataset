def longestRun(arr):
    if not arr:
        return 0

    max_length = 1
    current_length = 1

    # Check for increasing consecutive runs
    for i in range(1, len(arr)):
        if arr[i] == arr[i-1] + 1:
            current_length += 1
        else:
            max_length = max(max_length, current_length)
            current_length = 1
    max_length = max(max_length, current_length)

    current_length = 1

    # Check for decreasing consecutive runs
    for i in range(1, len(arr)):
        if arr[i] == arr[i-1] - 1:
            current_length += 1
        else:
            max_length = max(max_length, current_length)
            current_length = 1
    max_length = max(max_length, current_length)

    return max_length

print(longestRun([1, 2, 3, 5, 6, 7, 8, 9])) # ➞ 5
print(longestRun([1, 2, 3, 10, 11, 15])) # ➞ 3
print(longestRun([5, 4, 2, 1])) # ➞ 2
print(longestRun([3, 5, 7, 10, 15])) # ➞ 1