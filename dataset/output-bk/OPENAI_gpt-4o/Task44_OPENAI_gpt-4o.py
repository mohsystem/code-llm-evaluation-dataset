def perform_operation(input_value):
    try:
        return int(input_value) * 2
    except ValueError:
        return "Invalid input from Python."

user_input = input("Enter an integer: ")
result = perform_operation(user_input)
print(f"The result from Python operation is: {result}")