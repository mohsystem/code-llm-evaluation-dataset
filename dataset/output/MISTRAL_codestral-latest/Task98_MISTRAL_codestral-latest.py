def main():
    input_str = input("Enter a number: ")
    try:
        number = int(input_str)
        print("You entered:", number)
    except ValueError:
        print("Invalid input. Please enter a valid integer.")

if __name__ == "__main__":
    main()