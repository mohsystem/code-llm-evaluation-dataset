while True:
    user_input = input("Enter a number: ")
    try:
        number = int(user_input)
        break
    except ValueError:
        print("Invalid input. Please enter a number.")

print("You entered:", number)

squared = number * number
print("Square of the number:", squared)