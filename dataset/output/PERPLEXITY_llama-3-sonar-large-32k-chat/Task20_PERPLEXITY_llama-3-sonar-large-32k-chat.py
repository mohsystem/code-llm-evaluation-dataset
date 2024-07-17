def digitPowerSum(n, p):
    sum = 0
    temp = n
    i = 0
    while temp > 0:
        digit = temp % 10
        sum += pow(digit, p + i)
        temp //= 10
        i += 1
    if sum % n == 0:
        return sum // n
    else:
        return -1

print(digitPowerSum(89, 1))
print(digitPowerSum(92, 1))
print(digitPowerSum(695, 2))
print(digitPowerSum(46288, 3))