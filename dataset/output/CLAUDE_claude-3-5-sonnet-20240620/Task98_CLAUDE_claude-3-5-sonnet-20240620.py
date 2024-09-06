
try:
    user_input = input("Enter a number: ")
    number = int(user_input)
    print(f"Successfully converted to integer: {number}")
except ValueError:
    print("Invalid input. Please enter a valid integer.")
