def posNegSort(arr):
    pos = sorted([x for x in arr if x > 0])
    res = []
    pos_index = 0
    for x in arr:
        if x > 0:
            res.append(pos[pos_index])
            pos_index += 1
        else:
            res.append(x)
    return res