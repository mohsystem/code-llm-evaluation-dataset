import sys

if len(sys.argv) > 1:
    try:
        num = int(sys.argv[1])
        print("The integer value is:", num)
    except ValueError:
        print("Invalid input. Please enter a valid integer.")
else:
    print("No input provided.")