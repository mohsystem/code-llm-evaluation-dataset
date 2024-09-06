def xorGame(nums):
    xor_value = 0
    for num in nums:
        xor_value ^= num
    return xor_value == 0 or len(nums) % 2 == 0

# Example usage
print(xorGame([1,1,2]))  # Output: False
print(xorGame([0,1]))    # Output: True
print(xorGame([1,2,3]))  # Output: True