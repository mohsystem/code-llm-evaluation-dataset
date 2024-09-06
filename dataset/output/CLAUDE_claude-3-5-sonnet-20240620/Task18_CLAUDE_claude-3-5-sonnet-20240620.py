
def binary_array_to_number(arr):
    return int(''.join(map(str, arr)), 2)

# Test cases
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

for case in test_cases:
    print(f"Testing: {case} ==> {binary_array_to_number(case)}")
