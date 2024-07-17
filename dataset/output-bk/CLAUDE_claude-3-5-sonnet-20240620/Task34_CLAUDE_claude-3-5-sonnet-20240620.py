
def is_narcissistic(number):
    num_str = str(number)
    length = len(num_str)
    return sum(int(digit) ** length for digit in num_str) == number

print(is_narcissistic(153))  # True
print(is_narcissistic(1652)) # False
