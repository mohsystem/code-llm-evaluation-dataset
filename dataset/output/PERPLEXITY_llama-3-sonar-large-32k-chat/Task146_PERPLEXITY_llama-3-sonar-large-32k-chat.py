def find_missing_number(nums):
    n = len(nums) + 1
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(nums)
    return expected_sum - actual_sum

nums = list(map(int, input("Enter the array of numbers: ").split()))
print("The missing number is:", find_missing_number(nums))