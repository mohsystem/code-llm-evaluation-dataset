
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Input
arr = list(map(int, input("Enter integers separated by space: ").split()))

# Sort
bubble_sort(arr)

# Output
print("Sorted array:", arr)
