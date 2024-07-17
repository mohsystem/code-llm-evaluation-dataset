concatenated_string = ""

while True:
    input_string = input("Enter a string (or type 'quit' to exit): ")
    if input_string == "quit":
        break
    concatenated_string += input_string

print("Concatenated string:", concatenated_string)