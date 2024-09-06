def persistence(num):
    if num < 10:
        return 0
    count = 0
    while num >= 10:
        prod = 1
        for digit in str(num):
            prod *= int(digit)
        num = prod
        count += 1
    return count