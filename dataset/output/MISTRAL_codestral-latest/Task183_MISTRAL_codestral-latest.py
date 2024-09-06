def max_product(input_string, span):
    max_prod = 0
    for i in range(len(input_string) - span + 1):
        series = input_string[i:i+span]
        product = 1
        for digit in series:
            product *= int(digit)
        max_prod = max(max_prod, product)
    return max_prod