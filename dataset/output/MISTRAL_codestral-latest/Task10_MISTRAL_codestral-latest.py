def get_sum(a, b):
    if a == b:
        return a
    elif a < b:
        return sum(range(a, b + 1))
    else:
        return sum(range(b, a + 1))

print(get_sum(1, 0))  # Output: 1
print(get_sum(1, 2))  # Output: 3
print(get_sum(0, 1))  # Output: 1
print(get_sum(1, 1))  # Output: 1
print(get_sum(-1, 0))  # Output: -1
print(get_sum(-1, 2))  # Output: 2