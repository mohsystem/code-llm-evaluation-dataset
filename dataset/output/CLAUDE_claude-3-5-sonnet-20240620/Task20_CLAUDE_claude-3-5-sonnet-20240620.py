
def dig_pow(n, p):
    total = sum(int(d) ** (p + i) for i, d in enumerate(str(n)))
    return total // n if total % n == 0 else -1
