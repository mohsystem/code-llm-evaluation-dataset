def longestRun(lst):
    if not lst:
        return 0
    max_run = 1
    current_run = 1
    for i in range(1, len(lst)):
        if lst[i] == lst[i-1] + 1 or lst[i] == lst[i-1] - 1:
            current_run += 1
        else:
            max_run = max(max_run, current_run)
            current_run = 1
    return max(max_run, current_run)

print(longestRun([1, 2, 3, 5, 6, 7, 8, 9]))
print(longestRun([1, 2, 3, 10, 11, 15]))
print(longestRun([5, 4, 2, 1]))
print(longestRun([3, 5, 7, 10, 15]))