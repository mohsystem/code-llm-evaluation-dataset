import sys

try:
    num = int(sys.argv[1])
    print("The integer value is:", num)
except ValueError:
    print("Invalid input. Please enter a valid integer.")
except IndexError:
    print("No input provided. Please provide a command line argument.")