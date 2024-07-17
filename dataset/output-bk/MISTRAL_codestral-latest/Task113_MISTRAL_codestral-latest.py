result = ""

print("Enter strings to concatenate (enter 'end' to stop):")
input_str = input()

while input_str != "end":
    result += input_str
    input_str = input()

print("Concatenated string:", result)