
def expanded_form(num):
    result = []
    for i, digit in enumerate(str(num)[::-1]):
        if int(digit) != 0:
            result.append(digit + '0' * i)
    return ' + '.join(result[::-1])

# Test cases
print(expanded_form(12))    # Output: 10 + 2
print(expanded_form(42))    # Output: 40 + 2
print(expanded_form(70304)) # Output: 70000 + 300 + 4
