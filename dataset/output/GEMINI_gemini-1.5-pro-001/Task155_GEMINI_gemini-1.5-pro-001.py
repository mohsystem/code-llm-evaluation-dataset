# Heap Sort in Python

def heapify(arr, n, i):
  largest = i
  l = 2 * i + 1  # left = 2*i + 1
  r = 2 * i + 2  # right = 2*i + 2

  # Check if left child is larger
  if l < n and arr[i] < arr[l]:
    largest = l

  # Check if right child is larger
  if r < n and arr[largest] < arr[r]:
    largest = r

  # Swap if a larger element is found
  if largest != i:
    arr[i], arr[largest] = arr[largest], arr[i]
    heapify(arr, n, largest)

def heapSort(arr):
  n = len(arr)

  # Build a maxheap
  for i in range(n // 2 - 1, -1, -1):
    heapify(arr, n, i)

  # One by one extract an element from heap
  for i in range(n - 1, 0, -1):
    arr[i], arr[0] = arr[0], arr[i]
    heapify(arr, i, 0)

# Example usage
arr = [12, 11, 13, 5, 6, 7]
heapSort(arr)
print("Sorted array is:", arr)
