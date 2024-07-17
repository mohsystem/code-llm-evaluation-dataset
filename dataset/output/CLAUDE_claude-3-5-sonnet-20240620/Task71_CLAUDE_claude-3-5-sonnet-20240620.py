
import sys

if len(sys.argv) != 2:
    print("Please provide a string argument.")
    sys.exit(1)

input_string = sys.argv[1]

try:
    result = int(input_string)
    print(f"Converted integer: {result}")
except ValueError:
    print("Invalid input. Cannot convert to integer.")
