def count_smaller(nums):
    result = []
    for i in range(len(nums)):
        count = sum(1 for j in nums[i+1:] if j < nums[i])
        result.append(count)
    return result

nums = [int(x) for x in input().split()]
print(count_smaller(nums))