
import sys

def convert_to_int(input_str):
    try:
        return int(input_str)
    except ValueError:
        return None

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <string>")
        sys.exit(1)

    input_str = sys.argv[1]
    result = convert_to_int(input_str)

    if result is not None:
        print(f"Converted integer: {result}")
    else:
        print("Invalid input: Cannot convert to integer")
