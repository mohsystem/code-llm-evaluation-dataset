import sys

try:
    num = int(sys.argv[1])
    print(num)
except ValueError:
    print("Invalid input. Please enter an integer.")