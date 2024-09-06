def find_it(seq):
    result = 0
    for element in seq:
        result ^= element
    return result