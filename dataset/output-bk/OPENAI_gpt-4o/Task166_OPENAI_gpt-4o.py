def posNegSort(arr):
    pos_numbers = sorted([x for x in arr if x > 0])
    pos_idx = 0
    for i in range(len(arr)):
        if arr[i] > 0:
            arr[i] = pos_numbers[pos_idx]
            pos_idx += 1
    return arr

print(posNegSort([6, 3, -2, 5, -8, 2, -2]))  # ➞ [2, 3, -2, 5, -8, 6, -2]
print(posNegSort([6, 5, 4, -1, 3, 2, -1, 1]))  # ➞ [1, 2, 3, -1, 4, 5, -1, 6]
print(posNegSort([-5, -5, -5, -5, 7, -5]))  # ➞ [-5, -5, -5, -5, 7, -5]
print(posNegSort([]))  # ➞ []