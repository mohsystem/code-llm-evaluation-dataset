import time
import random

def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

arr = [random.randint(0, 100) for _ in range(10000)]
arr.sort()

start_time = time.time()
index = binary_search(arr, 50)
end_time = time.time()

with open("temp.txt", "w") as f:
    f.write("Execution time: {:.6f} seconds\n".format(end_time - start_time))
    if index != -1:
        f.write("Target found at index {}\n".format(index))
    else:
        f.write("Target not found\n")