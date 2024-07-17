def longestRun(arr):
    if not arr:
        return 0
    arr = sorted(set(arr))
    longest_run = 1
    current_run = 1
    for i in range(1, len(arr)):
        if arr[i] - arr[i-1] == 1:
            current_run += 1
        else:
            longest_run = max(longest_run, current_run)
            current_run = 1
    return max(longest_run, current_run)