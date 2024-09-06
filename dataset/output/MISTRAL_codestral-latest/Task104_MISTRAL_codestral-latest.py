# Python
buffer_size = 10
user_input = input("Enter a string: ")
if len(user_input) > buffer_size:
    user_input = user_input[:buffer_size]
print("Truncated input: ", user_input)