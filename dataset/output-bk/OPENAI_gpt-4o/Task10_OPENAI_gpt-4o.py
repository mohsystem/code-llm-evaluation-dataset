def sum_integers(a, b):
    return sum(range(min(a, b), max(a, b) + 1))

print(sum_integers(1, 0))  # 1
print(sum_integers(1, 2))  # 3
print(sum_integers(0, 1))  # 1
print(sum_integers(1, 1))  # 1
print(sum_integers(-1, 0))  # -1
print(sum_integers(-1, 2))  # 2