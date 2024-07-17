def dig_pow(n, p):
    sum = 0
    for i, digit in enumerate(str(n)):
        sum += int(digit) ** (p + i)
    return sum // n if sum % n == 0 else -1


print(dig_pow(89, 1))
print(dig_pow(92, 1))
print(dig_pow(695, 2))
print(dig_pow(46288, 3))