
str1 = "Hello"
str2 = "World"

# Copy
copy = str1[:]

# Concatenate
concat = str1 + " " + str2

# Manipulate
upper = concat.upper()
sub = concat[:5]
replace = concat.replace(\'o\', \'0\')

print(f"Original: {str1}, {str2}")
print(f"Copy: {copy}")
print(f"Concatenated: {concat}")
print(f"Uppercase: {upper}")
print(f"Substring: {sub}")
print(f"Replaced: {replace}")
