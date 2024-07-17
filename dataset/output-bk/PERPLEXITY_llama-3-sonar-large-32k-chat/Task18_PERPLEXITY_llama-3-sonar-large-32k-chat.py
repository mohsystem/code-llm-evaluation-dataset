def binary_array_to_number(arr):
    num = 0
    for i in range(len(arr)):
        num += arr[i] * 2 ** (len(arr) - i - 1)
    return num

arr1 = [0, 0, 0, 1]
arr2 = [0, 0, 1, 0]
arr3 = [0, 1, 0, 1]
arr4 = [1, 0, 0, 1]
arr5 = [0, 0, 1, 0]
arr6 = [0, 1, 1, 0]
arr7 = [1, 1, 1, 1]
arr8 = [1, 0, 1, 1]

print(binary_array_to_number(arr1))
print(binary_array_to_number(arr2))
print(binary_array_to_number(arr3))
print(binary_array_to_number(arr4))
print(binary_array_to_number(arr5))
print(binary_array_to_number(arr6))
print(binary_array_to_number(arr7))
print(binary_array_to_number(arr8))