def narcissistic(value):
    str_value = str(value)
    num_digits = len(str_value)
    total = sum(int(digit) ** num_digits for digit in str_value)
    return total == value