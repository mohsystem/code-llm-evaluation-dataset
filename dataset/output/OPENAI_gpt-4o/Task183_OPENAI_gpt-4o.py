def largest_product(digits, span):
    if span == 0:
        return 1
    max_product = 0
    for i in range(len(digits) - span + 1):
        product = 1
        for j in range(i, i + span):
            product *= int(digits[j])
        if product > max_product:
            max_product = product
    return max_product

# Test case
digits = "63915"
span = 3
print(largest_product(digits, span))