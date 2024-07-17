def find_missing(lst):
    n = len(lst) + 1
    total = n * (n + 1) // 2
    return total - sum(lst)