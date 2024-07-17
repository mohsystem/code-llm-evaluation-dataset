def reverse_string(s):
    return s[::-1]

if __name__ == "__main__":
    input_string = input("Enter a string: ")
    print("Reversed string (Python): " + reverse_string(input_string))