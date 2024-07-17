import sys

def main():
    if len(sys.argv) < 2:
        print("Please provide an argument.")
        return

    try:
        intValue = int(sys.argv[1])
        print("The integer value is:", intValue)
    except ValueError:
        print("Invalid input. Please enter a valid integer.")

if __name__ == "__main__":
    main()