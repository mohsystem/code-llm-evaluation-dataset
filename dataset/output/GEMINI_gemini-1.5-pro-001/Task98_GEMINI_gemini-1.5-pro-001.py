user_input = input("Enter an integer: ")
try:
    integer_value = int(user_input)
    print("Successfully converted to integer:", integer_value)
except ValueError:
    print("Invalid input. Please enter a valid integer.")