try:
    num = int(input("Enter a number: "))
    print("You entered:", num)
    num2 = int(input("Enter another number: "))
    print("You entered:", num2)
    result = num / num2
    print("Result:", result)
except ValueError:
    print("Invalid input. Please enter a valid number.")
except ZeroDivisionError:
    print("Cannot divide by zero.")