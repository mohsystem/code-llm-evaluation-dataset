
def binary_array_to_number(arr):
    return int(\'\'.join(map(str, arr)), 2)

# Test cases
print(binary_array_to_number([0,0,0,1])) # 1
print(binary_array_to_number([0,0,1,0])) # 2
print(binary_array_to_number([0,1,0,1])) # 5
print(binary_array_to_number([1,0,0,1])) # 9
print(binary_array_to_number([0,1,1,0])) # 6
print(binary_array_to_number([1,1,1,1])) # 15
print(binary_array_to_number([1,0,1,1])) # 11
