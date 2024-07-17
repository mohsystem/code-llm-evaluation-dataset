import time

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

start_time = time.time_ns()
result = binary_search(arr, x)
end_time = time.time_ns()

execution_time = end_time - start_time

with open("execution_time.txt", "w") as file:
    file.write(f"Execution time in nanoseconds: {execution_time}
")

if result == -1:
    print("Element not present")
else:
    print(f"Element found at index {result}")