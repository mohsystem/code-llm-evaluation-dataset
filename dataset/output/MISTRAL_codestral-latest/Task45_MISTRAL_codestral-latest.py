try:
    num = int(input("Enter a number: "))
    print("You entered:", num)
    # Perform operations with num here
except ValueError:
    print("Error: Invalid input. Please enter a number.")