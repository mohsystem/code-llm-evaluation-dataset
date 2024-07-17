def main():
    try:
        num1 = int(input("Enter first number: "))
        num2 = int(input("Enter second number: "))

        sum = num1 + num2
        difference = num1 - num2
        product = num1 * num2

        print("Sum:", sum)
        print("Difference:", difference)
        print("Product:", product)

        if num2 == 0:
            print("Cannot divide by zero.")
        else:
            quotient = num1 / num2
            print("Quotient:", quotient)

    except ValueError:
        print("Invalid input. Please enter numbers only.")
    except Exception as e:
        print("An error occurred:", e)


if __name__ == "__main__":
    main()