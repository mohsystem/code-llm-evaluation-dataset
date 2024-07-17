def is_narcissistic(number):
    if number < 0:
        return False
    original_number = number
    sum = 0
    digits = len(str(number))
    while number > 0:
        digit = number % 10
        sum += digit ** digits
        number //= 10
    return sum == original_number