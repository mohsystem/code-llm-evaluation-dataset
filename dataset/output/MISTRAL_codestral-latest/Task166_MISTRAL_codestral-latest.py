def posNegSort(arr):
    pos = sorted([x for x in arr if x > 0])
    pos_i = 0
    for i in range(len(arr)):
        if arr[i] > 0:
            arr[i] = pos[pos_i]
            pos_i += 1
    return arr