def create_phone_number(numbers):
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*numbers)

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(create_phone_number(numbers))