def find_nb(m):
    n = 1
    total = 0
    while total < m:
        total += n**3
        if total == m:
            return n
        n += 1
    return -1