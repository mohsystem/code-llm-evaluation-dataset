def xor_game(nums):
    xor = 0
    for num in nums:
        xor ^= num
    return len(nums) % 2 == 1 and xor != 0