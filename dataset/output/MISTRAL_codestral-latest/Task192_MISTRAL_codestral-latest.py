def xor_game(nums):
    xor = 0
    for num in nums:
        xor ^= num

    if xor == 0:
        return False
    elif len(nums) % 2 == 0:
        return False
    else:
        return True