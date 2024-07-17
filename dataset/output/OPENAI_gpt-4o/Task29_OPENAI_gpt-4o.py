def two_sum(nums, target):
    num_map = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i

# Test cases
result1 = two_sum([1, 2, 3], 4)
print(result1)

result2 = two_sum([3, 2, 4], 6)
print(result2)