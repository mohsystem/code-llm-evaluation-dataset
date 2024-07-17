def max_product(input_str, span):
    max_prod = 0
    for i in range(len(input_str) - span + 1):
        prod = 1
        for digit in input_str[i:i+span]:
            prod *= int(digit)
        max_prod = max(max_prod, prod)
    return max_prod