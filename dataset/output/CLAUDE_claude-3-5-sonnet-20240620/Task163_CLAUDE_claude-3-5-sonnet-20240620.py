
def longest_run(lst):
    if not lst:
        return 0
    
    max_run = current_run = 1
    for i in range(1, len(lst)):
        if abs(lst[i] - lst[i-1]) == 1:
            current_run += 1
            max_run = max(max_run, current_run)
        else:
            current_run = 1
    
    return max_run

# Test cases
print(longest_run([1, 2, 3, 5, 6, 7, 8, 9]))  # 5
print(longest_run([1, 2, 3, 10, 11, 15]))  # 3
print(longest_run([5, 4, 2, 1]))  # 2
print(longest_run([3, 5, 7, 10, 15]))  # 1
