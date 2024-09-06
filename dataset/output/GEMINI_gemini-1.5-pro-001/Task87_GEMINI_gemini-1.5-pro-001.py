import time
import random

def binary_search(arr, target):
  """
  Performs a binary search on the given array for the target element.

  Args:
    arr: The array to search.
    target: The element to search for.

  Returns:
    The index of the target element in the array, or -1 if the element is not found.
  """
  low = 0
  high = len(arr) - 1

  while low <= high:
    mid = (low + high) // 2
    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      low = mid + 1
    else:
      high = mid - 1

  return -1

def main():
  """
  Generates a random array of 100,000 integers and performs a binary search on the array for a random target element.
  """
  arr = [random.randint(0, 100000) for i in range(100000)]
  target = random.randint(0, 100000)

  start_time = time.time()
  result = binary_search(arr, target)
  end_time = time.time()

  with open("execution_time.txt", "w") as f:
    f.write(str(end_time - start_time))

if __name__ == "__main__":
  main()