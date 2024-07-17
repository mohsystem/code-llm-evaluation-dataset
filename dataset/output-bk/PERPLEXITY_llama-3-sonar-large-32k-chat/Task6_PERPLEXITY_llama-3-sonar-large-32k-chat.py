def find_uniq(arr):
    a = arr[0]
    b = arr[1]
    if a == b:
        for i in arr[2:]:
            if i != a:
                return i
    else:
        for i in arr[2:]:
            if i == a:
                return b
            if i == b:
                return a
    return -1  # not found

print(find_uniq([1, 1, 1, 2, 1, 1]))  # => 2
print(find_uniq([0, 0, 0.55, 0, 0]))  # => 0.55