def find_missing_number(arr):
  n = len(arr) + 1
  expected_sum = n * (n + 1) // 2
  actual_sum = sum(arr)
  return expected_sum - actual_sum