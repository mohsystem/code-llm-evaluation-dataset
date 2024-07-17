def binary_array_to_integer(binary_array):
    decimal_value = 0
    array_length = len(binary_array)
    for i in range(array_length):
        if binary_array[i] == 1:
            decimal_value += 2**(array_length - 1 - i)
    return decimal_value

binary_array1 = [0, 0, 0, 1]
binary_array2 = [0, 0, 1, 0]
binary_array3 = [0, 1, 0, 1]
binary_array4 = [1, 0, 0, 1]
binary_array5 = [0, 0, 1, 0]
binary_array6 = [0, 1, 1, 0]
binary_array7 = [1, 1, 1, 1]
binary_array8 = [1, 0, 1, 1]

print(binary_array_to_integer(binary_array1)) # Output: 1
print(binary_array_to_integer(binary_array2)) # Output: 2
print(binary_array_to_integer(binary_array3)) # Output: 5
print(binary_array_to_integer(binary_array4)) # Output: 9
print(binary_array_to_integer(binary_array5)) # Output: 2
print(binary_array_to_integer(binary_array6)) # Output: 6
print(binary_array_to_integer(binary_array7)) # Output: 15
print(binary_array_to_integer(binary_array8)) # Output: 11