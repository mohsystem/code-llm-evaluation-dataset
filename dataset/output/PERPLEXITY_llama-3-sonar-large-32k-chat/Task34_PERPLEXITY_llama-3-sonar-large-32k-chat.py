def isNarcissistic(n):
    sum = 0
    temp = n
    digits = len(str(n))
    while temp != 0:
        digit = temp % 10
        sum += digit ** digits
        temp //= 10
    return sum == n

print(isNarcissistic(153)) # True
print(isNarcissistic(1652)) # False