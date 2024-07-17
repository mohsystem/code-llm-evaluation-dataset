try:
    number = int(input("Enter an integer: "))
    print("The entered integer is:", number)
except ValueError:
    print("Invalid input. Please enter an integer.")