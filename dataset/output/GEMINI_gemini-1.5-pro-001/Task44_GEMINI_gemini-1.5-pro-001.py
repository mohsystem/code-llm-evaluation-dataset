def get_integer_input(prompt):
    while True:
        try:
            value = int(input(prompt))
            return value
        except ValueError:
            print("Invalid input. Please enter an integer.")

def main():
    num1 = get_integer_input("Enter the first number: ")
    num2 = get_integer_input("Enter the second number: ")

    sum = num1 + num2
    difference = num1 - num2
    product = num1 * num2

    print(f"The sum is: {sum}")
    print(f"The difference is: {difference}")
    print(f"The product is: {product}")

if __name__ == "__main__":
    main()