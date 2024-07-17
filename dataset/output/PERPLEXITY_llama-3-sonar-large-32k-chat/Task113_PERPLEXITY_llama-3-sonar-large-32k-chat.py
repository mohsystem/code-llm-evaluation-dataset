n = int(input("Enter the number of strings: "))
result = ""
for i in range(n):
    result += input("Enter string " + str(i + 1) + ": ")
print("Concatenated string: " + result)