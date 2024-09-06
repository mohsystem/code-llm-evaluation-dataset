
import sys

BUFFER_SIZE = 100

def main():
    buffer = ""
    while True:
        try:
            user_input = input("Enter text (or 'q' to quit): ")
            if user_input.lower() == 'q':
                break
            if len(buffer) + len(user_input) <= BUFFER_SIZE:
                buffer += user_input
                print(f"Buffer content: {buffer}")
            else:
                print(f"Error: Buffer overflow. Cannot add more than {BUFFER_SIZE} characters.")
        except EOFError:
            break

    print(f"Final buffer content: {buffer}")

if __name__ == "__main__":
    main()
