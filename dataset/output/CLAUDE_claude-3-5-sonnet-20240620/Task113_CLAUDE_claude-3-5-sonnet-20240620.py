
strings = []
while True:
    s = input("Enter a string (or press Enter to finish): ")
    if s == "":
        break
    strings.append(s)

result = " ".join(strings)
print("Concatenated string:", result)
