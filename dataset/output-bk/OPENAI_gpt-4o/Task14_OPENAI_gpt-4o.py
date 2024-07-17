def find_equal_index(arr):
    total_sum = sum(arr)
    left_sum = 0

    for i, num in enumerate(arr):
        if left_sum == total_sum - left_sum - num:
            return i
        left_sum += num

    return -1

arr = [20, 10, -80, 10, 10, 15, 35]
print(find_equal_index(arr))