import sys

if len(sys.argv) > 1:
    try:
        num = int(sys.argv[1])
        print(f"Python: Converted integer is {num}")
    except ValueError:
        print("Python: Invalid number")
else:
    print("Python: Please provide an input")