
import ctypes

# Allocate memory
ptr = ctypes.create_string_buffer(10)

# Use the memory
ptr.value = b"Hello"
print(ptr.value)

# Memory is automatically deallocated when ptr goes out of scope
