import time
import tempfile

def binary_search(arr, x):
    l = 0
    r = len(arr) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1

arr = [2, 3, 4, 10, 40]
x = 10

start_time = time.time()
result = binary_search(arr, x)
end_time = time.time()
execution_time = end_time - start_time

with tempfile.NamedTemporaryFile(delete=False) as temp_file:
    temp_file.write(f"Execution time: {execution_time}".encode())