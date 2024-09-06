# Python
import mmap

def read_from_buffer(index):
    with open("buffer.dat", "r+b") as f:
        mm = mmap.mmap(f.fileno(), 0)
        return mm[index]

# Allocate memory buffer
with open("buffer.dat", "wb") as f:
    f.write(b'\x00' * 1024)  # 1KB buffer

# User input for index
index = int(input("Enter index: "))
print("Value at index:", read_from_buffer(index))