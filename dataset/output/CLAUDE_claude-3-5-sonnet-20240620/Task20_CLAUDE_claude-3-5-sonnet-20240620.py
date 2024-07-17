
def dig_pow(n, p):
    digits = str(n)
    sum = 0
    for i, digit in enumerate(digits):
        sum += int(digit) ** (p + i)
    if sum % n == 0:
        return sum // n
    return -1

print(dig_pow(89, 1))
print(dig_pow(92, 1))
print(dig_pow(695, 2))
print(dig_pow(46288, 3))
