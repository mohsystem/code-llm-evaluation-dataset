def find_missing_number(lst):
    n = len(lst) + 1
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(lst)
    return expected_sum - actual_sum

lst = [1, 2, 4, 5, 6]  # Input your array here
print("Missing number is:",find_missing_number(lst))