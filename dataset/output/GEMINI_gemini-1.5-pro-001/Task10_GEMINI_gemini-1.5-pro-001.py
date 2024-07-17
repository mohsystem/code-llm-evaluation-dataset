def get_sum(a, b):
    return a if a == b else (a + b) * (abs(a - b) + 1) // 2