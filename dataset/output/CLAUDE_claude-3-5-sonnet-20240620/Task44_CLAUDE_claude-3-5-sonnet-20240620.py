
import re

def validate_input(input_string):
    return re.match(r'^[a-zA-Z0-9\\s]+$', input_string) is not None

def process_input(input_string):
    return input_string.upper()

def main():
    while True:
        user_input = input("Enter some text (alphanumeric characters and spaces only): ")
        if validate_input(user_input):
            processed_input = process_input(user_input)
            print(f"Processed input: {processed_input}")
            break
        else:
            print("Invalid input. Please try again.")

if __name__ == "__main__":
    main()
