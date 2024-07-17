def get_valid_input(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a valid number.")

num1 = get_valid_input("Enter first number: ")
num2 = get_valid_input("Enter second number: ")

print("Sum:", num1 + num2)
print("Difference:", num1 - num2)
print("Product:", num1 * num2)
if num2 != 0:
    print("Quotient:", num1 / num2)
else:
    print("Cannot divide by zero.")