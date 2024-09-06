
def find_missing_number(arr):
    n = len(arr) + 1
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(arr)
    return expected_sum - actual_sum

# Example usage
input_array = [1, 2, 4, 6, 3, 7, 8]
missing_number = find_missing_number(input_array)
print(f"The missing number is: {missing_number}")
