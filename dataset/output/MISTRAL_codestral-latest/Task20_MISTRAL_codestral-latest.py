# Python
def dig_pow(n, p):
    sum = 0
    temp = n
    while temp > 0:
        sum += (temp % 10) ** p
        p += 1
        temp //= 10
    return sum // n if sum % n == 0 else -1

print(dig_pow(89, 1))
print(dig_pow(92, 1))
print(dig_pow(695, 2))
print(dig_pow(46288, 3))