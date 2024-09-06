def xorGame(nums):
    xor_sum = 0
    for num in nums:
        xor_sum ^= num
    return xor_sum == 0 or len(nums) % 2 == 0

# Example usage:
nums1 = [1, 1, 2]
nums2 = [0, 1]
nums3 = [1, 2, 3]
print(xorGame(nums1))  # Output: false
print(xorGame(nums2))  # Output: true
print(xorGame(nums3))  # Output: true