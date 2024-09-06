
import sys

def divide_numbers(a, b):
    return a / b

def main():
    try:
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))
        result = divide_numbers(num1, num2)
        print(f"Result: {result}")
    except ValueError:
        print("Error: Please enter valid numbers.")
    except ZeroDivisionError:
        print("Error: Cannot divide by zero.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
    finally:
        print("Program execution completed.")

if __name__ == "__main__":
    main()
