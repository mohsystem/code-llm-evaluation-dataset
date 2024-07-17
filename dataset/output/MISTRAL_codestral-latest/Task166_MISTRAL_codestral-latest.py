def pos_neg_sort(arr):
    pos = sorted([x for x in arr if x > 0])
    neg = [x for x in arr if x <= 0]
    result = []
    for num in arr:
        if num > 0:
            result.append(pos.pop(0))
        else:
            result.append(num)
    return result