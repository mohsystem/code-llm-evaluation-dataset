
def find_missing(arr):
    n = len(arr) + 1
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(arr)
    return expected_sum - actual_sum

# Example usage
arr = [1, 2, 4, 6, 3, 7, 8]
print(find_missing(arr))
