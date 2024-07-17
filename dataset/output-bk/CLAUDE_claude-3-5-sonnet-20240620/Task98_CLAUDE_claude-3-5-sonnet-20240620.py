
def main():
    input_str = input("Enter a number: ")
    
    try:
        number = int(input_str)
        print(f"Converted integer: {number}")
    except ValueError:
        print("Invalid input. Not a valid integer.")

if __name__ == "__main__":
    main()
