def filter_list(lst):
    return [i for i in lst if isinstance(i, int) and i >= 0]

print(filter_list([1, 2, "a", "b"])) # [1, 2]
print(filter_list([1, "a", "b", 0, 15])) # [1, 0, 15]
print(filter_list([1, 2, "a", "b", "aasf", "1", "123", 123])) # [1, 2, 123]