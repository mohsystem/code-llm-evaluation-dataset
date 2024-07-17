def is_narcissistic(number):
    original_number = number
    result = 0
    n = len(str(number))

    while original_number != 0:
        remainder = original_number % 10
        result += remainder ** n
        original_number //= 10

    return number == result