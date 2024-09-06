
def max_subarray_sum(arr):
    max_sum = float('-inf')
    current_sum = 0
    
    for num in arr:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    
    return max_sum

# Example usage
arr = list(map(int, input("Enter the array elements separated by space: ").split()))
result = max_subarray_sum(arr)
print("Maximum subarray sum:", result)
