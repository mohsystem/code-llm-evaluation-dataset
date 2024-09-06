import sys

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Please provide a string to convert.")
    else:
        input_str = sys.argv[1]
        try:
            converted_int = int(input_str)
            print(f"Converted integer: {converted_int}")
        except ValueError:
            print("Invalid input: Not a valid integer.")