
def persistence(n):
    if n < 10:
        return 0
    count = 0
    while n >= 10:
        product = 1
        while n > 0:
            product *= n % 10
            n //= 10
        n = product
        count += 1
    return count

print(persistence(39))  # Output: 3
print(persistence(999)) # Output: 4
print(persistence(4))   # Output: 0
