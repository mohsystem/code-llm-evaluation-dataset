
def filter_list(l):
    return [x for x in l if isinstance(x, int)]

print(filter_list([1, 2, "a", "b"]))
print(filter_list([1, "a", "b", 0, 15]))
print(filter_list([1, 2, "a", "b", "aasf", "1", "123", 123]))
