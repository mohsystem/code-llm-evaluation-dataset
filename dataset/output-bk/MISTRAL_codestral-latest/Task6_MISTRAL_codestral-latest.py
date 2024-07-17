# Python
def find_uniq(arr):
    a, b, c = arr[:3]

    if a != b and a != c:
        return a
    if a != b:
        return c

    for i in arr[3:]:
        if i != a:
            return i

    return -1