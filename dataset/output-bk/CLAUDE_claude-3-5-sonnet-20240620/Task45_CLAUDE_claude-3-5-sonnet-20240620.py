
def divide(a, b):
    return a / b

def main():
    try:
        num = int(input("Enter a number: "))
        divisor = int(input("Enter another number: "))
        
        result = divide(num, divisor)
        print(f"Result of division: {result}")
        
        array = [0] * 5
        index = int(input("Enter an index to access the array: "))
        
        value = array[index]
        print(f"Value at index {index}: {value}")
    
    except ValueError as e:
        print("Error: Invalid input. Please enter a valid integer.")
    except ZeroDivisionError:
        print("Error: Division by zero is not allowed.")
    except IndexError:
        print("Error: Array index out of bounds.")
    except Exception as e:
        print(f"An unexpected error occurred: {str(e)}")

if __name__ == "__main__":
    main()
