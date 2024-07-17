def largest_product(digits, span):
    if span < 1 or span > len(digits):
        return -1
    max_product = 0
    for i in range(len(digits) - span + 1):
        product = 1
        for j in range(i, i + span):
            product *= int(digits[j])
        max_product = max(max_product, product)
    return max_product