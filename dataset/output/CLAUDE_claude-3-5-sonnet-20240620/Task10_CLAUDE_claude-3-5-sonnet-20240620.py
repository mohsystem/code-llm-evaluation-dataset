
def get_sum(a, b):
    if a == b:
        return a
    start, end = min(a, b), max(a, b)
    return sum(range(start, end + 1))

print(get_sum(1, 0))
print(get_sum(1, 2))
print(get_sum(0, 1))
print(get_sum(1, 1))
print(get_sum(-1, 0))
print(get_sum(-1, 2))
