def removeSmallest(arr):
    if not arr:
        return []
    minIndex = arr.index(min(arr))
    return arr[:minIndex] + arr[minIndex + 1:]

arr = [5, 3, 2, 1, 4]
print(' '.join(map(str, removeSmallest(arr))))