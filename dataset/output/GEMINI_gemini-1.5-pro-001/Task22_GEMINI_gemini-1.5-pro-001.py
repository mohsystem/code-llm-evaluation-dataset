def filter_list(l):
  return [i for i in l if isinstance(i, int)]

print(filter_list([1, 2, 'a', 'b']))
print(filter_list([1, 'a', 'b', 0, 15]))
print(filter_list([1, 2, 'a', 'b', 'aasf', '1', '123', 123]))