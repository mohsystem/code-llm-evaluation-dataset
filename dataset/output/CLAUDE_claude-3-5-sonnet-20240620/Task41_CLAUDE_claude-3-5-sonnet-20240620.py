
import sys

def process_input(user_input):
    # Process the input (example: print it back)
    print(f"Processed input: {user_input}")

def main():
    # Get input from user with a maximum length
    user_input = input("Enter a string (max 100 characters): ")[:100]
    
    # Process the input
    process_input(user_input)

if __name__ == "__main__":
    main()
