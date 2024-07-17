
def get_valid_number(min_val, max_val):
    while True:
        try:
            number = int(input(f"Enter a number between {min_val} and {max_val}: "))
            if min_val <= number <= max_val:
                return number
            else:
                print(f"Please enter a number between {min_val} and {max_val}.")
        except ValueError:
            print("Invalid input. Please enter a number.")

def get_valid_string(max_length):
    while True:
        input_string = input(f"Enter your name (max {max_length} characters): ").strip()
        if 0 < len(input_string) <= max_length:
            return input_string
        else:
            print(f"Please enter a non-empty string with max {max_length} characters.")

def main():
    number = get_valid_number(1, 100)
    name = get_valid_string(50)

    print(f"Hello, {name}!")
    print(f"Your number squared is: {number ** 2}")
    print(f"Your number cubed is: {number ** 3}")

if __name__ == "__main__":
    main()
