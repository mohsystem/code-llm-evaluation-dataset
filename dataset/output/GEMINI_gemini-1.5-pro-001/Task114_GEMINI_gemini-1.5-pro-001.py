def main():
    # String declaration and initialization
    str1 = "Hello"
    str2 = "World"

    # String concatenation
    concatenated_string = str1 + " " + str2
    print("Concatenated String:", concatenated_string)

    # String copying
    copied_string = str1
    print("Copied String:", copied_string)

    # String length
    length = len(concatenated_string)
    print("Length of Concatenated String:", length)

    # String manipulation - uppercase
    uppercase_string = concatenated_string.upper()
    print("Uppercase String:", uppercase_string)

    # String manipulation - lowercase
    lowercase_string = concatenated_string.lower()
    print("Lowercase String:", lowercase_string)

    # Substring extraction
    substring = concatenated_string[0:5]
    print("Substring:", substring)

if __name__ == "__main__":
    main()