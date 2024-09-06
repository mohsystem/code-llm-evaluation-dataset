def binary_array_to_number(arr):
  """
  This function converts a binary array to its equivalent decimal number.

  Args:
    arr: A list of integers representing the binary number.

  Returns:
    The decimal equivalent of the binary number.
  """
  decimal = 0
  for i in range(len(arr)):
    decimal += arr[i] * 2**(len(arr)-i-1)
  return decimal