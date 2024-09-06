# Python
strings = []
while True:
    user_input = input("Enter a string (or press enter to finish): ")
    if user_input == "":
        break
    strings.append(user_input)

concatenated_string = "".join(strings)
print("Concatenated string:", concatenated_string)