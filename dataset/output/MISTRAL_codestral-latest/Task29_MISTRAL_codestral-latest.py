def two_sum(numbers, target):
    num_dict = {}
    for i, num in enumerate(numbers):
        if target - num in num_dict:
            return [num_dict[target - num], i]
        num_dict[num] = i