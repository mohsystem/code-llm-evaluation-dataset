def find_nb(m):
    n = 0
    sum = 0
    while sum < m:
        n += 1
        sum += n**3
    return n if sum == m else -1