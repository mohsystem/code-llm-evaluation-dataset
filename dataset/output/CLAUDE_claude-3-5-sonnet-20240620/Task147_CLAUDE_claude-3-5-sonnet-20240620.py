
def find_kth_largest(nums, k):
    return sorted(nums, reverse=True)[k-1]

if __name__ == "__main__":
    nums = list(map(int, input("Enter the array elements separated by space: ").split()))
    k = int(input("Enter the value of k: "))
    print(f"The {k}th largest element is: {find_kth_largest(nums, k)}")
