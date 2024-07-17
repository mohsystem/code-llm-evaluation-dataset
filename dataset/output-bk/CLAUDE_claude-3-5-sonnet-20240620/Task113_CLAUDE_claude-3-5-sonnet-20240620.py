
result = ""

print("Enter strings to concatenate (type \'done\' to finish):")

while True:
    input_string = input()
    if input_string.lower() == \'done\':
        break
    result += input_string

print("Concatenated string:", result)
