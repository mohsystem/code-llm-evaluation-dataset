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

    result_array = arr[start_index : end_index+1]
    return result_array


input_array = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
result = max_subarray_sum(input_array)
print(result)