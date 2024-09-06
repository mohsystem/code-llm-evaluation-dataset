def find_kth_largest(nums, k):
    nums.sort(reverse=True)
    return nums[k-1]

nums = [int(x) for x in input("Enter the array of integers: ").split()]
k = int(input("Enter the value of k: "))
print("The kth largest element is:", find_kth_largest(nums, k))