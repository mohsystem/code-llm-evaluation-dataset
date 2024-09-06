def binary_array_to_int(arr):
    return int("".join(map(str, arr)), 2)

if __name__ == "__main__":
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

    for arr in test_cases:
        print(f'Testing: {arr} ==> {binary_array_to_int(arr)}')