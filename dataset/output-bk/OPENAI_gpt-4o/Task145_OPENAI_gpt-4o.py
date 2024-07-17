def max_subarray_sum(nums):
    max_sum = current_sum = nums[0]
    for num in nums[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum

if __name__ == "__main__":
    import sys
    input_list = list(map(int, sys.argv[1:]))
    print("Python:", max_subarray_sum(input_list))