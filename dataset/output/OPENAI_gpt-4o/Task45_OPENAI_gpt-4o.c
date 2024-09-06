try:
    num = int(input("Enter a number for Python: "))
    print(f"Python read the number: {num}")
except ValueError as e:
    print(f"Invalid input in Python: {e}")