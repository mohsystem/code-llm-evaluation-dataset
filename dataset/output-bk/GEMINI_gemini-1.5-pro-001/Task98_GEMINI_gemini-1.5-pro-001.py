input_string = input("Enter a number: ")

try:
    number = int(input_string)
    print("You entered:", number)
except ValueError:
    print("Invalid input. Please enter a valid integer.")