def get_integer_input(prompt):
    while True:
        try:
            value = int(input(prompt))
            if value > 0:
                return value
            else:
                print("Invalid input. Please enter a positive integer.")
        except ValueError:
            print("Invalid input. Please enter an integer.")


def get_double_input(prompt):
    while True:
        try:
            value = float(input(prompt))
            if value > 0:
                return value
            else:
                print("Invalid input. Please enter a positive double.")
        except ValueError:
            print("Invalid input. Please enter a double.")


# Get an integer from the user
integer_input = get_integer_input("Enter an integer: ")

# Get a double from the user
double_input = get_double_input("Enter a double: ")

# Perform some operations on the input
sum_result = integer_input + int(double_input)
product_result = integer_input * double_input

print("Sum:", sum_result)
print("Product:", product_result)