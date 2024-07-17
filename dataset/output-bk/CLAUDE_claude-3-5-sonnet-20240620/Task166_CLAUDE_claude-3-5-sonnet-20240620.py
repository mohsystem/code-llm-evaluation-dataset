
def posNegSort(arr):
    pos = sorted([x for x in arr if x > 0])
    pos_index = 0
    result = []
    for num in arr:
        if num > 0:
            result.append(pos[pos_index])
            pos_index += 1
        else:
            result.append(num)
    return result
