def find_missing_number(nums):
    n = len(nums) + 1
    total = n * (n + 1) // 2
    return total - sum(nums)

nums = list(map(int, input("Enter the array of unique integers: ").split()))
print("The missing number is:", find_missing_number(nums))