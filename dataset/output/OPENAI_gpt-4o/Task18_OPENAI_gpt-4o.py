def convert_binary_array_to_int(binary_array):
    result = 0
    for bit in binary_array:
        result = result * 2 + bit
    return result

test_cases = [
    [0, 0, 0, 1],
    [0, 0, 1, 0],
    [0, 1, 0, 1],
    [1, 0, 0, 1],
    [0, 0, 1, 0],
    [0, 1, 1, 0],
    [1, 1, 1, 1],
    [1, 0, 1, 1]
]

for test_case in test_cases:
    print(convert_binary_array_to_int(test_case))