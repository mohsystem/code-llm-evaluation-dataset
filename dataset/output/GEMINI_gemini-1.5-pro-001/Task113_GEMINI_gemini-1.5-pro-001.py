num_strings = int(input("Enter the number of strings: "))
concatenated_string = ""
for i in range(num_strings):
    user_string = input(f"Enter string {i+1}: ")
    concatenated_string += user_string
print("Concatenated string:", concatenated_string)