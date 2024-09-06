# Program in Python
def find_missing_number(arr, n):
    total_sum = n * (n + 1) // 2
    array_sum = sum(arr)
    return total_sum - array_sum

# Example usage
arr = [1, 2, 4, 5, 6]
n = 6
print("Missing number is:", find_missing_number(arr, n))