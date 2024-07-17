def xorGame(nums):
    xorSum = 0
    for num in nums:
        xorSum ^= num
        
    if xorSum == 0 or len(nums) % 2 == 0:
        return True
    return False

# Testing example 1
print(xorGame([1, 1, 2]))  # False
# Testing example 2
print(xorGame([0, 1]))  # True
# Testing example 3
print(xorGame([1, 2, 3]))  # True