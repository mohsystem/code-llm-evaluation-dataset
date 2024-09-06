def is_narcissistic(number):
    digits = list(map(int, str(number)))
    power = len(digits)
    return sum(d ** power for d in digits) == number

# Testing the function
print(is_narcissistic(153))  # True
print(is_narcissistic(1652))  # False