import ctypes

def main():
    # Allocate a memory buffer dynamically
    size = 10
    buffer = (ctypes.c_char * size)()

    # Fill the buffer with some data
    for i in range(size):
        buffer[i] = ord('A') + i

    # Allow the user to read data from the buffer
    while True:
        index = int(input(f"Enter index to read (0-{size-1}) or -1 to exit: "))
        if index == -1:
            break
        if 0 <= index < size:
            print(f"Data at index {index}: {chr(buffer[index])}")
        else:
            print("Index out of bounds")

if __name__ == "__main__":
    main()