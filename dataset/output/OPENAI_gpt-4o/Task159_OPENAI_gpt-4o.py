# Python code

def main():
    size = int(input("Enter the size of the buffer: "))
    buffer = [0] * size

    while True:
        idx = int(input("Enter index (-1 to quit): "))
        if idx == -1:
            break
        if 0 <= idx < size:
            print(f"Value at index {idx}: {buffer[idx]}")
        else:
            print("Index out of bounds.")

if __name__ == "__main__":
    main()