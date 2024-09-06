
def largest_series_product(input_sequence, span):
    if span > len(input_sequence) or span <= 0:
        return None
    
    max_product = 0
    
    for i in range(len(input_sequence) - span + 1):
        series = input_sequence[i:i+span]
        product = 1
        for digit in series:
            product *= int(digit)
        max_product = max(max_product, product)
    
    return max_product

# Example usage
input_sequence = "63915"
span = 3
result = largest_series_product(input_sequence, span)
print(f"The largest product of {span} adjacent digits in {input_sequence} is: {result}")
