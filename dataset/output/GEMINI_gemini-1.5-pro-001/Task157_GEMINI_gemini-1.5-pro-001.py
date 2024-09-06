import ctypes

# Allocate memory
size = 1024  # Size in bytes
memory = ctypes.cast(ctypes.create_string_buffer(size), ctypes.POINTER(ctypes.c_byte))

# Use the allocated memory (optional)
# ...

# Deallocate memory
ctypes.free(memory)