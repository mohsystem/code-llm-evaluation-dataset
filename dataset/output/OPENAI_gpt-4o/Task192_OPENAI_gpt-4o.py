def xorGame(nums):
    xor_sum = 0
    for num in nums:
        xor_sum ^= num
    return xor_sum == 0 or len(nums) % 2 == 0

nums = [1, 1, 2]
print(xorGame(nums))    # Output: false
nums = [0, 1]
print(xorGame(nums))    # Output: true
nums = [1, 2, 3]
print(xorGame(nums))    # Output: true