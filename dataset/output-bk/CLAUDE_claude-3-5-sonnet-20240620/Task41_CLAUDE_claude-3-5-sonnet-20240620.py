
def process_string(s):
    return s.upper()

def main():
    user_input = input("Enter a string: ")
    processed = process_string(user_input)
    print(f"Processed string: {processed}")

if __name__ == "__main__":
    main()
