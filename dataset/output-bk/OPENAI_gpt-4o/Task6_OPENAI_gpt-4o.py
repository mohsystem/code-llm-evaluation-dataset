def find_uniq(array):
    a, b, c = array[:3]
    candidate = a if a != b and a != c else b
    for x in array:
        if x != candidate:
            return x
    return candidate

print("Python unique number:", find_uniq([1, 1, 1, 2, 1, 1]))
print("Python unique number:", find_uniq([0, 0, 0.55, 0, 0]))