def largest_product(input_str, span):
    max_product = 0
    for i in range(len(input_str) - span + 1):
        product = 1
        for j in range(span):
            product *= int(input_str[i + j])
        if product > max_product:
            max_product = product
    return max_product

input_str = "63915"
span = 3
print(largest_product(input_str, span))