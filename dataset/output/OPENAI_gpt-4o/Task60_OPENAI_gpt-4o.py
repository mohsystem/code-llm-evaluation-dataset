def expanded_form(num):
    result = ""
    num_str = str(num)
    length = len(num_str)

    for i, digit in enumerate(num_str):
        if digit != '0':
            result += digit + "0" * (length - i - 1) + " + "

    return result[:-3]

print(expanded_form(12))    # Should return "10 + 2"
print(expanded_form(42))    # Should return "40 + 2"
print(expanded_form(70304)) # Should return "70000 + 300 + 4"