input_val = input("Enter a number: ")
try:
    number = int(input_val)
    print("You entered:", number)
except ValueError:
    print("Invalid input. Not an integer.")