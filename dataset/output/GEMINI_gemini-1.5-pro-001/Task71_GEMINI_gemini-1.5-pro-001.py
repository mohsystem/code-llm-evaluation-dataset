import sys

def main():
    if len(sys.argv) < 2:
        print("Please provide an argument to be converted to an integer.")
        sys.exit(1)

    try:
        user_input = sys.argv[1]
        converted_integer = int(user_input)
        print(f"Successfully converted '{user_input}' to integer: {converted_integer}")
    except ValueError:
        print(f"Unable to convert '{user_input}' to an integer.")

if __name__ == "__main__":
    main()