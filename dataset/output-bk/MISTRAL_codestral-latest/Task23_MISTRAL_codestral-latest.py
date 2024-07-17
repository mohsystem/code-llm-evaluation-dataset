def find_nb(m):
    n = 1
    while n**3 < m:
        m -= n**3
        n += 1
    return n if m == n**3 else -1