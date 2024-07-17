
def find_uniq(arr):
    if arr[0] != arr[1] and arr[0] != arr[2]:
        return arr[0]
    if arr[1] != arr[0] and arr[1] != arr[2]:
        return arr[1]
    
    for num in arr[2:]:
        if num != arr[0]:
            return num
    
    return arr[0]

print(find_uniq([1, 1, 1, 2, 1, 1]))
print(find_uniq([0, 0, 0.55, 0, 0]))
