import sys

def main():
    try:
        buffer_size = int(input("Enter the buffer size: "))
    except ValueError:
        print("Invalid input. Please enter an integer.")
        sys.exit(1)

    buffer = [None] * buffer_size

    for i in range(buffer_size):
        try:
            buffer[i] = int(input(f"Enter data for index {i}: "))
        except ValueError:
            print("Invalid input. Please enter an integer.")
            sys.exit(1)

    while True:
        try:
            index = int(input("Enter an index to read (or -1 to exit): "))
        except ValueError:
            print("Invalid input. Please enter an integer.")
            continue

        if index == -1:
            break

        if 0 <= index < buffer_size:
            print(f"Data at index {index}: {buffer[index]}")
        else:
            print("Index out of range.")

if __name__ == "__main__":
    main()