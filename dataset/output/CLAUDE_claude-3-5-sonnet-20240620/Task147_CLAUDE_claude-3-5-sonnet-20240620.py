
def find_kth_largest(nums, k):
    nums.sort(reverse=True)
    return nums[k-1]

if __name__ == "__main__":
    nums = list(map(int, input("Enter the array elements separated by space: ").split()))
    k = int(input("Enter the value of k: "))
    result = find_kth_largest(nums, k)
    print(f"The {k}th largest element is: {result}")
