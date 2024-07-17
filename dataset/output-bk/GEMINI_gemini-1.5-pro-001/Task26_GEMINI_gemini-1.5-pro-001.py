def find_odd(arr):
    result = 0
    for num in arr:
        result ^= num
    return result

arr1 = [7]
arr2 = [0]
arr3 = [1, 1, 2]
arr4 = [0, 1, 0, 1, 0]
arr5 = [1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1]

print(find_odd(arr1))
print(find_odd(arr2))
print(find_odd(arr3))
print(find_odd(arr4))
print(find_odd(arr5))