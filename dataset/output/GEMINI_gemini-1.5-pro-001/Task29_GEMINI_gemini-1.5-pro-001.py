def two_sum(numbers, target):
    nums = {}
    for index, num in enumerate(numbers):
        complement = target - num
        if complement in nums:
            return [nums[complement], index]
        nums[num] = index