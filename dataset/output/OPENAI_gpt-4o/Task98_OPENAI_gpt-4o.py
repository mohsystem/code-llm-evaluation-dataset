result = None
try:
    user_input = input("Enter a number: ")
    result = int(user_input)
    print("Converted Integer:", result)
except ValueError:
    print("Error: Not a valid integer")