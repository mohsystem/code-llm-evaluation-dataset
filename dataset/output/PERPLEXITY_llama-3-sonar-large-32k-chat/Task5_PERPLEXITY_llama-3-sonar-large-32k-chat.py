def persistence(n):
    count = 0
    while n >= 10:
        mult = 1
        for digit in str(n):
            mult *= int(digit)
        n = mult
        count += 1
    return count

print(persistence(39))  # 3
print(persistence(999)) # 4
print(persistence(4))   # 0