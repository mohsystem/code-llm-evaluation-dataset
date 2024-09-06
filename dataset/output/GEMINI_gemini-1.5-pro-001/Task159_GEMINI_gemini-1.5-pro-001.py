import sys

def main():
    try:
        size = int(input("Enter the size of the buffer: "))
    except ValueError:
        print("Invalid input. Please enter an integer.")
        sys.exit(1)

    buffer = [None] * size

    for i in range(size):
        try:
            data = input(f"Enter data for index {i}: ")
            buffer[i] = data
        except Exception as e:
            print(f"Error: {e}")
            sys.exit(1)

    while True:
        try:
            index = int(input("Enter an index to read data (or -1 to exit): "))
        except ValueError:
            print("Invalid input. Please enter an integer.")
            continue

        if index == -1:
            break
        elif 0 <= index < size:
            print(f"Data at index {index}: {buffer[index]}")
        else:
            print("Index out of range.")

if __name__ == "__main__":
    main()