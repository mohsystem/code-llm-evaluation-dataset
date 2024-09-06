def get_user_input(prompt):
    while True:
        try:
            return input(prompt)
        except EOFError:
            print("Invalid input. Please try again.")

def validate_input(input_str):
    if not input_str.isalpha():
        raise ValueError("Input should only contain alphabets")

def main():
    input_str = get_user_input("Enter a string: ")
    try:
        validate_input(input_str)
        print("Input is valid")
        print("Upper case: ", input_str.upper())
        print("Lower case: ", input_str.lower())
    except ValueError as e:
        print("Error: ", str(e))

if __name__ == "__main__":
    main()