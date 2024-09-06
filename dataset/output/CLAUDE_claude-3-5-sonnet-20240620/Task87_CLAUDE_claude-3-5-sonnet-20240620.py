
import time
import tempfile

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

if __name__ == "__main__":
    arr = sorted([1, 3, 5, 7, 9, 11, 13, 15, 17, 19])
    target = 13

    start_time = time.time()
    result = binary_search(arr, target)
    end_time = time.time()

    execution_time = end_time - start_time

    with tempfile.NamedTemporaryFile(mode='w', delete=False) as temp_file:
        temp_file.write(f"Execution time: {execution_time:.6f} seconds")
        print(f"Execution time written to: {temp_file.name}")

    print(f"Result: {result}")
