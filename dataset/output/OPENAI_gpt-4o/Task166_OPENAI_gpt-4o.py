def posNegSort(lst):
    pos_nums = sorted([num for num in lst if num > 0])
    pos_index = 0
    result = []
    for num in lst:
        if num > 0:
            result.append(pos_nums[pos_index])
            pos_index += 1
        else:
            result.append(num)
    return result

print(posNegSort([6, 3, -2, 5, -8, 2, -2]))  # [2, 3, -2, 5, -8, 6, -2]
print(posNegSort([6, 5, 4, -1, 3, 2, -1, 1]))  # [1, 2, 3, -1, 4, 5, -1, 6]
print(posNegSort([-5, -5, -5, -5, 7, -5]))  # [-5, -5, -5, -5, 7, -5]
print(posNegSort([]))  # []