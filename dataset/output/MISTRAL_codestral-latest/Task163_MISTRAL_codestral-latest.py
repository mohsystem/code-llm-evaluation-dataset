def longestRun(arr):
    if not arr:
        return 0

    longest_sequence = 1
    current_sequence = 1

    for i in range(1, len(arr)):
        if arr[i] == arr[i-1] + 1 or arr[i] == arr[i-1] - 1:
            current_sequence += 1
        else:
            longest_sequence = max(longest_sequence, current_sequence)
            current_sequence = 1

    return max(longest_sequence, current_sequence)