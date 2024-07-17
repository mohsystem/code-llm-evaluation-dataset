import time

def binarySearch(arr, target):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
target = 23
start_time = time.time()
result = binarySearch(arr, target)
end_time = time.time()
time_elapsed = (end_time - start_time) * 1000
with open("execution_time.txt", "w") as file:
    file.write("Execution time: {:.2f} milliseconds
".format(time_elapsed))
print("Element found at index", result)