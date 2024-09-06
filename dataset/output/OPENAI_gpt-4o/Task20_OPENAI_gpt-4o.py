def dig_pow(n, p):
    s = sum(int(digit) ** (p + i) for i, digit in enumerate(str(n)))
    return s // n if s % n == 0 else -1

print(dig_pow(89, 1))     # Output: 1
print(dig_pow(92, 1))     # Output: -1
print(dig_pow(695, 2))    # Output: 2
print(dig_pow(46288, 3))  # Output: 51