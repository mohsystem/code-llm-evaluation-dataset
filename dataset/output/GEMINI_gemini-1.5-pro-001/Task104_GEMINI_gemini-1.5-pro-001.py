import sys

# Define the fixed-size buffer
BUFFER_SIZE = 1024

# Function to handle user input
def get_user_input():
    try:
        # Get user input from stdin
        user_input = sys.stdin.read(BUFFER_SIZE)
    except KeyboardInterrupt:
        # Handle Ctrl+C interrupt
        print("\nInput interrupted.")
        user_input = ""
    return user_input

# Main program
if __name__ == "__main__":
    print("Enter your input (max", BUFFER_SIZE, "bytes):")
    input_data = get_user_input()
    print("\nYou entered:\n", input_data)