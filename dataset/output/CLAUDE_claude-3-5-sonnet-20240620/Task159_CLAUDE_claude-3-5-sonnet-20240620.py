
import ctypes

# Allocate memory buffer
buffer_size = 100
buffer = (ctypes.c_char * buffer_size)()

# Initialize buffer with some data
for i in range(buffer_size):
    buffer[i] = chr(65 + (i % 26))

while True:
    try:
        index = int(input("Enter an index to read (0-99), or -1 to exit: "))
        if index == -1:
            break
        if 0 <= index < buffer_size:
            print(f"Data at index {index}: {buffer[index].decode('utf-8')}")
        else:
            print("Invalid index. Please enter a number between 0 and 99.")
    except ValueError:
        print("Invalid input. Please enter a valid integer.")

# Memory is automatically freed in Python
