def xorGame(nums):
    xor_all = 0
    count = 0
    for num in nums:
        xor_all ^= num
        if num % 2 == 0:
            count += 1
    return xor_all == 0 or count % 2 == 1