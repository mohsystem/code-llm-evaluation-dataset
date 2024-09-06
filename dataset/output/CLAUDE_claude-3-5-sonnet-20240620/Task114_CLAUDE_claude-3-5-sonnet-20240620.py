
def string_operations():
    # String copy
    original = "Hello, World!"
    copied = original[:]
    print(f"Original: {original}")
    print(f"Copied: {copied}")

    # String concatenation
    str1 = "Python "
    str2 = "is awesome!"
    concatenated = str1 + str2
    print(f"Concatenated: {concatenated}")

    # String manipulation
    text = "   Python Programming   "
    stripped = text.strip()
    upper = text.upper()
    lower = text.lower()
    replaced = text.replace("Python", "Java")
    
    print(f"Stripped: '{stripped}'")
    print(f"Uppercase: {upper}")
    print(f"Lowercase: {lower}")
    print(f"Replaced: {replaced}")

if __name__ == "__main__":
    string_operations()
