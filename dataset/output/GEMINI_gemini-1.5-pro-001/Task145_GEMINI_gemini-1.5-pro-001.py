def max_subarray_sum(arr):
    max_so_far = 0
    current_max = 0
    start_index = 0
    end_index = 0
    j = 0

    for i in range(len(arr)):
        current_max += arr[i]

        if current_max > max_so_far:
            max_so_far = current_max
            start_index = j
            end_index = i

        if current_max < 0:
            current_max = 0
            j = i + 1

    # Extract the subarray with maximum sum
    max_subarray = arr[start_index : end_index+1]
    return max_subarray


if __name__ == "__main__":
    arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    max_sub_array = max_subarray_sum(arr)
    print(f"Maximum contiguous subarray: {max_sub_array}")