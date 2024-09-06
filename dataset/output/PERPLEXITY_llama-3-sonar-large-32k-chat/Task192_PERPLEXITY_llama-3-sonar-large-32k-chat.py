def xorGame(nums):
    xor_all = 0
    for num in nums:
        xor_all ^= num
    if xor_all == 0:
        return True
    count = sum(num % 2 == 0 for num in nums)
    return count % 2 == 0