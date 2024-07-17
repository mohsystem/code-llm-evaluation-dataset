def persistence(num):
    count = 0
    while num >= 10:
        num = multiply_digits(num)
        count += 1
    return count

def multiply_digits(num):
    product = 1
    while num > 0:
        product *= num % 10
        num //= 10
    return product

print(persistence(39))  # should return 3
print(persistence(999))  # should return 4
print(persistence(4))  # should return 0