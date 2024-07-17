def count_smaller(nums):
    result = []
    for i in range(len(nums)):
        count = 0
        for j in range(i+1, len(nums)):
            if nums[j] < nums[i]:
                count += 1
        result.append(count)
    return result

# Example usage:
nums = [5, 2, 6, 1]
print(count_smaller(nums))