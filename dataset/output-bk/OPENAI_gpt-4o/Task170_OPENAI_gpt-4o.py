def countRangeSum(nums, lower, upper):
    from sortedcontainers import SortedList
    prefix_sums = SortedList([0])
    current_sum = 0
    count = 0
    
    for num in nums:
        current_sum += num
        count += prefix_sums.bisect_right(current_sum - lower) - prefix_sums.bisect_left(current_sum - upper)
        prefix_sums.add(current_sum)
        
    return count

# Example Usage
nums = [-2, 5, -1]
lower = -2
upper = 2
print(countRangeSum(nums, lower, upper))  # Output: 3