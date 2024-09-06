
def persistence(num):
    if num < 10:
        return 0
    
    product = 1
    for digit in str(num):
        product *= int(digit)
    
    return 1 + persistence(product)

# Test cases
print(persistence(39))  # Output: 3
print(persistence(999))  # Output: 4
print(persistence(4))   # Output: 0
