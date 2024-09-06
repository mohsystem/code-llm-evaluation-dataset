def longestRun(lst):
    if not lst:
        return 0
    longest = current = 1
    for i in range(1, len(lst)):
        if lst[i] == lst[i-1] + 1 or lst[i] == lst[i-1] - 1:
            current += 1
        else:
            longest = max(longest, current)
            current = 1
    return max(longest, current)