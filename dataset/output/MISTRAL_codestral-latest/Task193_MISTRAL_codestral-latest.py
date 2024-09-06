def xor_game(nums):
    xor = 0
    for num in nums:
        xor ^= num
    return xor != 0 and len(nums) % 2 == 1