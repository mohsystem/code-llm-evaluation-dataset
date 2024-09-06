def dig_pow(n, p):
    digits = [int(x) for x in str(n)]
    sum_of_powers = sum([x ** (p + i) for i, x in enumerate(digits)])
    k = sum_of_powers // n
    return k if k * n == sum_of_powers else -1