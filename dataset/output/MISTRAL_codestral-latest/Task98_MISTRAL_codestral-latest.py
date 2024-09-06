# Python
try:
    user_input = int(input("Enter a number: "))
    print("You entered:", user_input)
except ValueError:
    print("Invalid input. Please enter an integer.")