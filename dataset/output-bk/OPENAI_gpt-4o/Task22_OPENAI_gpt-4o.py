def filter_list(l):
    return [item for item in l if isinstance(item, int)]

print(filter_list([1, 2, "a", "b"])) # [1, 2]
print(filter_list([1, "a", "b", 0, 15])) # [1, 0, 15]
print(filter_list([1, 2, "a", "b", "aasf", "1", "123", 123])) # [1, 2, 123]