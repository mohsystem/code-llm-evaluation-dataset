def find_uniq(arr):
    if arr[0] != arr[1] and arr[0] != arr[2]:
        return arr[0]
    for i in range(1, len(arr)):
        if arr[i] != arr[i - 1]:
            return arr[i]
    return 0