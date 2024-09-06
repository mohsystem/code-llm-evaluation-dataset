try:
    user_input = input("Enter a number: ")
    number = float(user_input)
    result = number * 2
    print(f"The result is: {result}")
except ValueError:
    print("Invalid input. Please enter a number.")